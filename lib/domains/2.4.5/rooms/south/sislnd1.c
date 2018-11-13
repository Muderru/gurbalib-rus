#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Перешеек");
   set_long("Вы стоите на берегу Острова магов, тянущегося отсюда на " +
      "восток и юго-запад. На юге вы видите руины башни Арканартона - " +
      "архимага жившего на этом острове. Чтобы попасть туда, нужно" +
      "пройти по магическому мосту на северо-западе, воздвигнутому " +
      "взамен старого каменного.");

   add_exit("юг", DIR + "/rooms/south/sislnd13.c");
   add_exit("восток", DIR + "/rooms/south/sislnd2.c");
   add_exit("северо-запад", "#go_northwest");
   add_exit("северо-восток", DIR + "/rooms/south/sislnd12.c");
}

void go_northwest(void) {
   string usermsg, othermsg;

   usermsg = "Вы собрали свою волю в кулак и ступили на практически " +
      "невидимый мост.";
   if (this_player()->query_gender() == "male") {
       othermsg = this_player()->query_Name() + " ступил на мерцающий " +
        "мост.";
   } else if (this_player()->query_gender() == "female") {
       othermsg = this_player()->query_Name() + " ступила на мерцающий " +
        "мост.";
   } else {
       othermsg = this_player()->query_Name() + " ступило на мерцающий " +
        "мост.";
   }      
   /* XXX domove(DIR + "/rooms/south/sshore26.c",usermsg, othermsg); */
}
