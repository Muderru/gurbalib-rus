#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Горная тропа");
   set_long("Вы находитесь в начале тропы, поднимающейся в горы. " +
     "Хотя ее и завалило камнями после недавнего обвала, среди валунов " +
     "на севере остался узкий проход. Также возможно получится " +
     "вскарабкаться вверх по камням.");

   add_exit("север", DIR + "/rooms/mine/tunnel.c");
   add_exit("юг", DIR + "/rooms/plain11.c");
   add_exit("вверх", "#do_climb"); 
   add_action("do_climb", "вскарабкаться");
}

int do_climb(string str) {
   string usermsg, othermsg;

   usermsg = "Вы вскарабкались на камни.";
   if (this_player()->query_gender() == "male") {
     othermsg = this_player()->query_Name() + " вскарабкался вверх по ущелью.";
   } else if (this_player()->query_gender() == "female") {
     othermsg = this_player()->query_Name() + " вскарабкалась вверх по ущелью.";
   } else {
     othermsg = this_player()->query_Name() + " вскарабкалось вверх по ущелью.";
   }


   /* XXX domove(DIR + "/rooms/ravine.c", usermsg, othermsg);  */
   return 1;
}
