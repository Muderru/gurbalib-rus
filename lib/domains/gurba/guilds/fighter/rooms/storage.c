#include "../../../domain.h"

inherit "/std/room";

void setup(void) {
   set_short("%^BLUE%^Кладовые Гильдии бойцов%^RESET%^");
   set_long("Все вещи членов гильдии здесь аккуратно разложены " +
      "по именным хранилищам. Тут даже есть ваше персональное хранилище на востоке.");

   set_exits(([
      "юг" : DIR + "/guilds/fighter/rooms/main",
      "восток" : "#go_locker",
   ]));

}

void go_locker(void) {
   string locker;
   object obj;

   locker = DIR + "/data/lockers/" + this_player()->query_name() + "/locker";

   if (file_exists(locker + ".o")) {
      obj = clone_object(DIR + "/guilds/fighter/rooms/locker.c");

      if (!obj) {
         write("Ошибка: Хранилище отсутствует. Пожалуйста, сообщите об этом админу.");
         return;
      }

      obj->setup();
      obj->set_player_name(this_player()->query_name());
      obj->restore_me();

      if (!obj) {
         write("Ошибка: Хранилище отсутствует. Пожалуйста, сообщите об этом админу.");
         return;
      }
   } else {
      SECURE_D->make_lockerdir("gurba", this_player()->query_name());
      obj = clone_object(DIR + "/guilds/fighter/rooms/locker.c");
      obj->setup();
      obj->set_player_name(this_player()->query_name());
      obj->save_me();
   }

   if (this_player()->move(obj)) {
      /* XXX Need to move this stuff to other move's like summon/goto */
      this_object()->event("body_leave", this_player());
      
         if (this_player()->query_gender() == "male") {
          tell_room(this_player(), this_player()->query_Name() + " ушел на восток.\n");
          obj->tell_room(this_player(), this_player()->query_Name() + " вошел.\n");
       } else if (this_player()->query_gender() == "female") {
          tell_room(this_player(), this_player()->query_Name() + " ушла на восток.\n");
          obj->tell_room(this_player(), this_player()->query_Name() + " вошла.\n");
       } else {
          tell_room(this_player(), this_player()->query_Name() + " ушло на восток.\n");
          obj->tell_room(this_player(), this_player()->query_Name() + " вошло.\n");
       }

       this_player()->do_look(this_environment());
   } else {
      write("Ошибка произошла здесь...\n");
   }
}
