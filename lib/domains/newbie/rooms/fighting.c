#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("newbie");

   set_short("Арена новичков");
   set_long("Вы в небольшой земляной пещере, пол которой покрыт множеством следов. " +
      "С потолка свисают огромные цепкие корни. А в центре зала растет большой цветок.");

   add_item("цветок", "Большой цветок растет в центре пещеры в почти полной темноте. " +
      "Возможно вам стоит сорвать его.");

   add_action("do_pick", "сорвать");

   set_exits(([
      "север" : DIR + "/rooms/equipment", 
      "юг" : DIR + "/rooms/drinkme",
   ]));
}

int do_pick(string arg) {
   if ((arg == "flower") || (arg == "цветок")) {
      object obj;

      write("Как только вы приблизились к цветку, гигантский саблезубый кролик " +
         "появился из ниоткуда и преградил ваш путь.\n");
         if (this_player()->query_gender() == "male") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() +
         " приблизился к цветку в центре пещеры.\n" +
         "Тут внезапно появился гигантский саблезубый кролик, блокирующий его путь.\n");
       } else if (this_player()->query_gender() == "female") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() +
         " приблизилась к цветку в центре пещеры.\n" +
         "Тут внезапно появился гигантский саблезубый кролик, блокирующий ее путь.\n");
       } else {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() +
         " приблизилось к цветку в центре пещеры.\n" +
         "Тут внезапно появился гигантский саблезубый кролик, блокирующий его путь.\n");
       }

      obj = clone_object(DIR + "/monsters/bunny.c");
      obj->setup();
      obj->move(this_player()->query_environment());
      obj->attack(this_player());
      return 1;
   } else {
      return 0;
   }
}
