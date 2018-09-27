#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("boothill");

   set_short("Старый паб");
   set_long("Всю дальнюю стену перегораживает деревянный бар, заставленный " +
      "бутылками с непонятным пойлом. Тут не так много посетителей, но шума " +
      "от них, как от огромной толпы народа. Они сидят за кривыми стульями и" +
      "и покосившимися столами и что-то громко обсуждают.");

   set_exits(([
      "запад" : DIR + "/rooms/infront_saloon.c",
   ]));

   set_objects(DIR + "/obj/piano.c");

   add_action("do_play", "играть");
}

int do_play(string str) {
   int x;

   if (!this_object()->present("пианино")) {
      return 0;
   }

   if ((str == "пианино") || (str == "на пианино")) {
      x = random(5);
      switch(x) {
         case 0:
            write("Вы начали наигрывать грязные частушки.");
            if (this_player()->query_gender() == "male") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начал наигрывать грязные частушки.");
          } else if (this_player()->query_gender() == "female") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начала наигрывать грязные частушки.");
          } else {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начало наигрывать грязные частушки.");
       }
            break;
         case 1:
            write("Вы начали играть любовную балладу.");
            if (this_player()->query_gender() == "male") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начал играть любовную балладу.");
          } else if (this_player()->query_gender() == "female") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начала играть любовную балладу.");
          } else {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начало играть любовную балладу.");
       }
            break;
         case 2:
            write("Вы начали исполнять классическую мелодию.");
            if (this_player()->query_gender() == "male") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начал исполнять классическую мелодию.");
          } else if (this_player()->query_gender() == "female") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начала исполнять классическую мелодию.");
          } else {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начало исполнять классическую мелодию.");
       }
            break;
         default:
            write("Вы начали исполнять популярную мелодию.");
            if (this_player()->query_gender() == "male") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начал исполнять популярную мелодию.");
          } else if (this_player()->query_gender() == "female") {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начала исполнять популярную мелодию.");
          } else {
            this_environment()->tell_room(this_player(), 
               this_player()->query_Name() + " начало исполнять популярную мелодию.");
       }
            break;
      }
      return 1;
   }
   return 0;
}

