/* junk.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: хлам [-h] [все|ПРЕДМЕТ]" });
   lines += ({ "" });
   lines += ({ "Команда хлам позволяет вам сделать игру чище.  "});
   lines += ({ "Если у вас или в комнате есть предмет, который больше вам не нужен," +
      " просто уничтожьте его этой замечательной командой." });
   lines += ({ "" });
   lines += ({ "Если вы хотите уничтожить все, что есть в инвентаре, используйте: хлам все" });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "" });
   lines += ({ "Примеры:" });
   lines += ({ "\tхлам труп" });
   lines += ({ "\tхлам меч" });
   lines += ({ "\tхлам все" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "hp");
   add_also("player", "inventory");
   add_also("player", "levels");
   add_also("player", "score");
   add_also("player", "skills");
   add_also("player", "top");

   add_also("wiz", "status");
}

void do_junk(object obj) {
   string objname;

   objname = obj->query_obj_i_name();
   if (!objname || objname == "") {
      objname = obj->query_id();
   }

   if (obj->is_living()) {
      write("Вы не можете уничтожить " + objname + ".\n");
      return;
   }

   write("Вы уничтожили " + objname + ".\n");
   if (this_player()->query_gender() == "male") {
         this_player()->query_environment()->tell_room(this_player(),
          this_player()->query_Name() + " уничтожил " + objname + ".\n");
   } else if (this_player()->query_gender() == "female") {
         this_player()->query_environment()->tell_room(this_player(),
          this_player()->query_Name() + " уничтожила " + objname + ".\n");
   } else {
         this_player()->query_environment()->tell_room(this_player(),
          this_player()->query_Name() + " уничтожило " + objname + ".\n");
   }         
      destruct_object(obj);
}

static void main(string str) {
   object obj, *inv;
   int x, xmax;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (str == "все") {
      inv = this_player()->query_inventory();
      xmax = sizeof(inv);
      for (x = 0; x < xmax; x++) {
         do_junk(inv[x]);
      }
      return;
   }

   obj = this_environment()->present(str);

   if (!obj) {
      obj = this_player()->present(str);
   }

   if (!obj) {
      write("Что вы хотите уничтожить?");
      return;
   }

   do_junk(obj);
}
