int tied_rope;  /* Flag to note if the rope is here and tied or not. */
string *rooms_to_notify;

void set_rooms_to_notify(string * str) {
   rooms_to_notify = str;
}

string *query_rooms_to_notify() {
   return rooms_to_notify;
}

int is_rope(string str) {
   return call_other(str, "query_tied");
}

string query_extra_long(int can_go_up, int can_go_down) {
   string dir_up, dir_down, or_str, str;
   if (can_go_up) {
      dir_up = "вверх";
   } else {
      dir_up = "";
   }
   if (can_go_down) {
      dir_down = "вниз";
   } else {
      dir_down = "";
   }
   if (can_go_up && can_go_down) {
      or_str = " или ";
   } else {
      or_str = "";
   }

   str = dir_up + or_str + dir_down;
   return "Эта веревка позволит вам взобраться " + str + ".";
}

void move_player(object player, object old_room, string direction, string room) {
   player->move(room);
   player->write("Вы взобрались " + direction + " с помощью веревки.");
   old_room->tell_room(player, player->query_Name() + " взбирается " +
      direction + " с помощью веревки.\n");
   player->query_environment()->tell_room(player, player->query_Name() +
      " взбирается " + direction + " с помощью веревки.\n");
   player->do_look(player->query_environment());
}

void notify_rooms(string str) {
   string *rooms;
   int i, dim;
   rooms = query_rooms_to_notify();
   for (i = 0, dim = sizeof(rooms); i < dim; i++) {
      call_other(rooms[i], "message_room", this_player(), str);
   }
}

int do_tie(string str) {
   object obj;

   if (str == "кольцо" || str == "веревка") {
      obj = this_player()->present("веревка");
      if (obj) {
         /* XXX we do not need a rope for to secure already tied one. */
         if (tied_rope) {
            write("Вы проверяете надежно ли веревка привязана к кольцу.\n");
            this_player()->query_environment()->tell_room(this_player(),
               this_player()->query_Name() +
               " проверяет надежно ли веревка привязана к кольцу.\n");
         } else {
            if (obj->move(this_player()->query_environment())) {
               obj->set_gettable(0);
               obj->set_tied("кольцо");
               write("Вы привязали веревку к кольцу.\n");
               if (this_player()->query_gender() == "male") {
                 this_player()->query_environment()->tell_room(this_player(),
                    this_player()->query_Name() + " привязал веревку к кольцу.\n");
               } else if (this_player()->query_gender() == "female") {
                 this_player()->query_environment()->tell_room(this_player(),
                    this_player()->query_Name() + " привязала веревку к кольцу.\n");
               } else {
                 this_player()->query_environment()->tell_room(this_player(),
                    this_player()->query_Name() + " привязало веревку к кольцу.\n");
               }
               notify_rooms("Конец веревки показался из дыры в " +
                  "потолке!\n");
               tied_rope = 1;
            }
         }
      } else {
         write("Вы не привязали веревку к кольцу.\n");
      }
      return 1;
   }
   return 0;
}

int do_untie(string str) {
   object obj;

   if (str == "кольцо" || str == "веревка") {
      obj = this_player()->query_environment()->present("веревка");
      if (obj) {
         if (tied_rope) {
            obj->set_gettable(1);
            obj->set_tied("");
            if (obj->move(this_player())) {
               write("Вы отвязали веревку от кольца и подняли ее.\n");
               if (this_player()->query_gender() == "male") {
                 this_player()->query_environment()->tell_room(this_player(),
                    this_player()->query_Name() + " отвязал веревку от кольца.\n");
               } else if (this_player()->query_gender() == "female") {
                 this_player()->query_environment()->tell_room(this_player(),
                    this_player()->query_Name() + " отвязала веревку от кольца.\n");
               } else {
                 this_player()->query_environment()->tell_room(this_player(),
                    this_player()->query_Name() + " отвязало веревку от кольца.\n");
               }               
               notify_rooms("Конец веревки пропал в дыре в " +
                  "потолке!\n");
               tied_rope = 0;
            }
         } else {
            write("Веревка не привязана ни к чему.\n");
            this_player()->query_environment()->tell_room(this_player(),
               this_player()->query_Name() + " задумчиво рассматривает кольцо.\n");
         }
      } else {
         write("К кольцу ничего не привязано.\n");
      }
      return 1;
   }
   return 0;
}

int query_tied() {
   return tied_rope;
}
