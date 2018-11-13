#include "../domain.h"
inherit "/std/room";

int door_closed;
int locked;
string key;

void setup(void) {
   add_area("2.4.5");

   set_short("Банк");
   set_long("Вы зашли в банк. На востоке находится низкая стойка, " +
      "которая перегорожена толстыми железными прутьями. В стене " +
      "за стойкой вы видите дверь, ведущую в глубь банка.");

   add_exit("запад", DIR + "/rooms/narr_alley.c");
   add_exit("восток", "#enter_door");

   add_item("стойка", "На стойке висит большая табличка:\n" +
      "ЗАКРЫТО НА РЕКОНСТРУКЦИЮ.\n");

   add_item("дверь", "#look_door");

   set_objects (DIR + "/monsters/bankguard.c");
   door_closed = 1;
   locked = 1;
   key = "банковский ключ";
}

/* Need to attach these commands to a user... */

string look_door() {
   if (!door_closed) {
      return "Дверь открыта.";
   }
   return "Дверь закрыта.";
}

int open_door() {
   if (locked) {
      write("Дверь заперта.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с запертой дверью.\n");
   } else if (door_closed) {
      door_closed = 0;
      write("Вы открыли дверь.\n");
      if (this_player()->query_gender() == "male") {
      tell_room(this_player(), this_player()->query_Name() + 
         " открыл дверь.\n");
      } else if (this_player()->query_gender() == "female") {
      tell_room(this_player(), this_player()->query_Name() + 
         " открыла дверь.\n");
      } else {
      tell_room(this_player(), this_player()->query_Name() + 
         " открыло дверь.\n");
      }      
   } else {
      write("Дверь уже открыта.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с открытой дверью.\n");
   }
   return 1;
}

int close_door() {
   if (door_closed) {
      write("Дверь уже закрыта.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с закрытой дверью.\n");
   } else {
      door_closed = 1;
      write("Вы закрыли дверь.\n");
      if (this_player()->query_gender() == "male") {
      tell_room(this_player(), this_player()->query_Name() + 
         " закрыл дверь.\n");
      } else if (this_player()->query_gender() == "female") {
      tell_room(this_player(), this_player()->query_Name() + 
         " закрыла дверь.\n");
      } else {
      tell_room(this_player(), this_player()->query_Name() + 
         " закрыло дверь.\n");
      } 
   }
   return 1;
}

int has_key(string str) {
   object obj;

   obj = this_player()->present(str);

   if (obj) {
      return 1;
   }
   return 0;
}

int unlock_door() {
   if (!locked) {
      write("Дверь уже не заперта.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с дверью.\n");
   } else if (has_key(key)) {
      write("Вы отперли дверь.\n");
      if (this_player()->query_gender() == "male") {
      tell_room(this_player(), this_player()->query_Name() + 
         " отпер дверь.\n");
      } else if (this_player()->query_gender() == "female") {
      tell_room(this_player(), this_player()->query_Name() + 
         " отперла дверь.\n");
      } else {
      tell_room(this_player(), this_player()->query_Name() + 
         " отперло дверь.\n");
      }      
      locked = 0;
   } else {
      write("Вы не можете найти ключ от этой двери.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с дверью.\n");
   }
}

int lock_door() {
   if (locked) {
      write("Дверь уже заперта.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с дверью.\n");
   } else if (!door_closed) {
      write("Дверь открыта, ее сейчас нельзя запереть.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с дверью.\n");
   } else if (has_key(key)) {
      write("Вы заперли дверь.\n");
      if (this_player()->query_gender() == "male") {
      tell_room(this_player(), this_player()->query_Name() + 
         " запер дверь.\n");
      } else if (this_player()->query_gender() == "female") {
      tell_room(this_player(), this_player()->query_Name() + 
         " заперла дверь.\n");
      } else {
      tell_room(this_player(), this_player()->query_Name() + 
         " заперло дверь.\n");
      }      
      locked = 1;
   } else {
      write("Вы не можете найти ключ от этой двери.\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " возится с дверью.\n");
   }
}

int enter_door() {
   if (!door_closed) {
/* XXX domove isn't done yet */
      /* return domove(DIR + "/rooms/bankroom.c", usermsg, othermsg); */
   } else {
      write("Дверь закрыта. Может быть сначала следует ее открыть?\n");
      tell_room(this_player(), this_player()->query_Name() + 
         " безуспешно пытается войти в закрытую дверь.\n");
   }
   return 1;
}

