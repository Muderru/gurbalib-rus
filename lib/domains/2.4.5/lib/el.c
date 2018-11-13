#define ELFILE "/domains/2.4.5/rooms/elevator.c"

object get_el() {
   object obj;
   obj = find_object(ELFILE);
   if (!obj) {
      if (obj = compile_object(ELFILE)) {
         obj->setup();
         obj->setup_mudlib();
      }
   }

   return obj;
}

void el_arrives() {
   this_object()->tell_room(nil, "Дзинь! На западе открылась дверь.");
   this_object()->add_exit("запад", ELFILE);
   this_object()->remove_item("дверь");
   this_object()->add_item("дверь", "Дверь открыта.");
   this_object()->lamp_off();
}

void el_leaves() {
   this_object()->tell_room(nil, "На западе закрылась дверь.");
   this_object()->remove_exit("запад");
   this_object()->remove_item("дверь");
   this_object()->add_item("дверь", "Дверь закрыта.");
}

int press_button(string str) {
   object elev;

   if ((str == "кнопка") ||  (str == "кнопку")) {
      write("Вы нажали на кнопку.\n");
      if (this_player()->query_gender() == "male") {
       this_object()->tell_room(this_player(), this_player()->query_Name() + 
         " нажал на кнопку.\n");
      } else if (this_player()->query_gender() == "female") {
       this_object()->tell_room(this_player(), this_player()->query_Name() + 
         " нажала на кнопку.\n");
      } else {
       this_object()->tell_room(this_player(), this_player()->query_Name() + 
         " нажало на кнопку.\n");
      }

      this_object()->tell_room(this_object(),
         "Рядом с подъемником загорелась лампа.\n");

      this_object()->lamp_on();

      elev = get_el();
      call_other(elev, "set_floor", this_object()->query_floor());
      return 1;
   }
   return 0;
}
