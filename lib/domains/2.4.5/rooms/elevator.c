#include "../domain.h"

inherit "/std/room";

int location, destination;
string open;

void set_floor(int x) {
   destination = x;

   tell_room(this_object(), "Подъемник начал двигаться.\n");

   switch (location) {
      case 0:
         open = "закрыта";
         remove_exit("восток");
         break;
      case 1:
         open = "открыта";
         remove_exit("восток");
         add_exit("восток", DIR + "/rooms/wiz_hall.c");
         break;
      case 2:
         open = "открыта";
         remove_exit("восток");
         add_exit("восток", DIR + "/rooms/church.c");
         break;
      case 3:
         remove_exit("восток");
         add_exit("восток", DIR + "/rooms/attic.c");
         open = "открыта";
         break;
   }
}

int query_location() {
   return location;
}

void setup(void) {
   add_area("2.4.5");

   set_short("Подъемник");

   location = 1;
   set_floor(1);
   add_exit("north", DIR + "/rooms/vill_shore.c");
   add_action("press_button", "нажать");
   add_action("press_button", "давить");
}

string query_long() {
   string str;

   str = "Вы стоите на подъемнике. На стене вы видите три кнопки " +
      "пронумерованные от 1 до 3.\nСейчас горит кнопка " + destination + 
      ". Дверь на востоке " + open + ".\n";

   return str;
}

/* XXX Need to do the door, button and stuff.... */

int press_button(string str) {
   object elev;

   if (str == "1") {
      write("Вы нажали кнопку 1.\n");
      if (this_player()->query_gender() == "male") {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажал на кнопку 1.\n");
      } else if (this_player()->query_gender() == "female") {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажала на кнопку 1.\n");
      } else {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажало на кнопку 1.\n");
      }      
      set_floor(1);

   } else if (str == "2") {
      write("Вы нажали кнопку 2.\n");
      if (this_player()->query_gender() == "male") {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажал на кнопку 2.\n");
      } else if (this_player()->query_gender() == "female") {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажала на кнопку 2.\n");
      } else {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажало на кнопку 2.\n");
      }      
      set_floor(2);

   } else if (str == "3") {
      write("Вы нажали кнопку 3.\n");
            if (this_player()->query_gender() == "male") {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажал на кнопку 3.\n");
      } else if (this_player()->query_gender() == "female") {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажала на кнопку 3.\n");
      } else {
      this_object()->tell_room(this_player(), this_player()->query_Name() +
         " нажало на кнопку 3.\n");
      }
      set_floor(3);

   } else {
      write("Какую кнопку вы хотите нажать? (1, 2, 3)?\n");
   }
   return 1;
}

