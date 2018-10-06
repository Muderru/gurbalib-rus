#include "../../../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("Зал Гильдии бойцов");
   set_long("Вы зашли в приемный зал Гильдии бойцов. Это высокое " +
      "просторное помещение с рядом массивных колонн. В центре зала " +
      "с потолка свисает большая бронзовая люстра. На стенах зала " +
      "висят портреты героев и мастеров оружия прошлого. Внутренние " +
      "помещения гильдии расположены на севере, а на юге можно " +
      "выйти на улицу.");
   set_exits(([
      "юг" : DIR + "/rooms/gelmir3", 
      "север" : DIR + "/guilds/fighter/rooms/main",
   ]));

   set_objects(
      DIR + "/guilds/fighter/monsters/master",
      DIR + "/guilds/fighter/objects/book"
   );

   add_item("стены", "стены", "портреты",
      "На массивных стенах, помимо портретов мастеров оружия и героев " +
      "прошлого, висят образцы доспехов и оружия, начиная от самых " +
      "древних до современных.");
   add_item("люстра", "Она поистине огромна, даже сложно представить " +
      "как такая махина держится на потолке. Сотни ее свечей ярко " +
      "освещают этот немаленький зал.");
}

int do_listen(void) {
   write("На севере вы слышите бряцание металла по металлу и иногда " +
      "полный боли крик.");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " прислушивается.\n");
   return 1;
}

/*
int join_guild(string str) {
   if (!str || str == "" || str == "fighter" || str == "fighters") {
      if (!present()) {
         write("The guild master is not here, you will have to wait " +
            "for him to come back.");
         return 1;
      } else {
         if (
      }
   }
   return 0;
}

int leave_guild(string str) {
}
*/
