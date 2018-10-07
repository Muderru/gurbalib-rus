inherit obj "/std/object";

int fuel, lit;

int set_fuel(int x) {
   fuel = x;
}

int query_fuel(void) {
   if (fuel < 0) {
      return 0;
   }
   return fuel;
}

int query_lit(void) {
   return lit;
}

static int light(void) {
   EVENT_D->subscribe_event("heart_beat");
   lit = 1;
    if (this_player()->query_gender() == "male") {
   write("Ты зажег " + this_object()->query_id() + ".\n");
   this_player()->query_environment()->tell_room(this_player(), 
      this_player()->query_Name() + " зажег " + 
      this_object()->query_id() + ".\n");
  } else if (this_player()->query_gender() == "female") {
   write("Ты зажгла " + this_object()->query_id() + ".\n");
   this_player()->query_environment()->tell_room(this_player(), 
      this_player()->query_Name() + " зажгла " + 
      this_object()->query_id() + ".\n");
  } else {
   write("Ты зажег " + this_object()->query_id() + ".\n");
   this_player()->query_environment()->tell_room(this_player(), 
      this_player()->query_Name() + " зажгло " + 
      this_object()->query_id() + ".\n");
  }

   return 1;
}

static int extinguish(void) {
   lit = 0;
   write("Ты гасишь " + this_object()->query_id() + ".\n");
   this_player()->query_environment()->tell_room(this_player(), 
      this_player()->query_Name() + " гасит " + 
      this_object()->query_id() + ".\n");
   return 1;
}

private int burn_fuel(void) {
   object room;

   if (!query_lit()) {
      return 0;
   }

   if (--fuel < 5) {
      room = query_environment();
      if (room->is_living()) {
        if (this_object()->query_obj_gender() == "male") {
         write("Ваш " + query_id() + " тускнеет.\n");
      } else if (this_player()->query_gender() == "female") {
         write("Ваша " + query_id() + " тускнеет.\n");
      } else {
         write("Ваше " + query_id() + " тускнеет.\n");
      }          

      }
   }

   if (fuel < 1) {
      room = query_environment();
      if (room->is_living()) {
        if (this_object()->query_obj_gender() == "male") {
         write("Ваш " + query_id() + " гаснет.\n");
      } else if (this_player()->query_gender() == "female") {
         write("Ваша " + query_id() + " гаснет.\n");
      } else {
         write("Ваше " + query_id() + " гаснет.\n");
      }
/*         say(room->query_Name() + "'s " + query_id() + " goes out.\n"); */
      } else {
         room->message_room(room, query_id() + " гаснет.\n");
      }

      lit = 0;
      EVENT_D->unsubscribe_event("heart_beat");
   }

   return 1;
}

private string lit_or_unlit(void) {
   if (query_lit()) {
      return "светится";
   }

   return "потухшее";
}

string query_short(void) {
   string str;

   str = ::query_short() + " [" + lit_or_unlit() + "]";

   if (query_fuel() < 20) {
      str += " [мало горючего]";
   }

   return str;
}

string query_long(void) {
   string str;

   str = ::query_long() + "\nОно " + lit_or_unlit() + ".";
   if (query_fuel() < 20) {
      str += "\nТут очень мало горючего.";
   }

   return str;
}

void event_heart_beat(void) {
   burn_fuel();
}

string query_name(void) {
   return query_id();
}

private void light_usage(void) {
   string *lines;

   lines = ({ "Использование: зажечь [-h] [OBJECT]" });
   lines += ({ "" });
   lines += ({ "Включает или зажигает указанный предмет." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tзажечь факел" });
   lines += ({ "\tзажечь лампа" });
   lines += ({ "Смотрите также:" });
   lines += ({ "\tкупить, погасить, опознать, список, слушать, смотреть, " +
      "искать, продать, цена" });

   if (query_wizard(this_player())) {
      lines += ({ "\tlast, locate, mudlist, possess, rwho, snoop, where, who"
         });
   }

   this_player()->more(lines);
}

private void extinguish_usage(void) {
   string *lines;

   lines = ({ "Использование: погасить [-h] [OBJECT]" });
   lines += ({ "" });
   lines += ({ "Погашает или выключает выбранный источник света." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпогачить факел" });
   lines += ({ "\tпогасить лампу" });
   lines += ({ "See also:" });
   lines += ({ "\tкупить, погасить, опознать, список, слушать, смотреть, " +
      "искать, продать, цена" });

   if (query_wizard(this_player())) {
      lines += ({ "\tlast, locate, mudlist, possess, rwho, snoop, where, who"
         });
   }

   this_player()->more(lines);
}

int do_light(string str) {
   if (empty_str(str)) {
      light_usage();
      return 1;
   }
   if (sscanf(str, "-%s", str)) {
      light_usage();
      return 1;
   }
   if (lowercase(str) != lowercase(query_id())) {
      return 0;
   }
   if (query_lit()) {
        if (this_object()->query_obj_gender() == "male") {
         write("Ваш " + str + " уже освещает.");
      } else if (this_player()->query_gender() == "female") {
         write("Ваша " + str + " уже освещает.");
      } else {
         write("Ваше " + str + " уже освещает.");
      }       
      return 1;
   }
   if (fuel < 1) {
        if (this_object()->query_obj_gender() == "male") {
         write("Ваш " + str + " без горючего.");
      } else if (this_player()->query_gender() == "female") {
         write("Ваша " + str + " без горючего.");
      } else {
         write("Ваше " + str + " без горючего.");
      }       
      return 1;
   }

   return light();
}


int do_extinguish(string str) {
   if (empty_str(str)) {
      extinguish_usage();
      return 1;
   }
   if (sscanf(str, "-%s", str)) {
      extinguish_usage();
      return 1;
   }
   if (lowercase(str) != lowercase(query_id())) {
      return 0;
   }
   if (!query_lit()) {
        if (this_object()->query_obj_gender() == "male") {
         write("Ваш " + str + " не освещает.");
      } else if (this_player()->query_gender() == "female") {
         write("Ваша " + str + " не освещает.");
      } else {
         write("Ваше " + str + " не освещает.");
      }       
      return 1;
   }

   return extinguish();
}

void create(void) {
   obj::create();

   set_fuel(1000);
   add_action("do_light", "зажечь");
   add_action("do_extinguish", "погасить");
}

