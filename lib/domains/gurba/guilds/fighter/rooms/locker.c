#include "../../../domain.h"

inherit "/std/room";

string player_name;
string *myitems;

void restore_me(void) {
   object obj;
   int i, max;

   if (!unguarded("restore_object", DIR + "/data/lockers/" +
      player_name + "/locker.o")) {
      write("Ошибка восстановления " + DIR + "/data/lockers/" +
         player_name + "/locker.o");
      write("Пожалуйста сообщите администрации.");
      return;
   }
   max = sizeof(myitems);
   for (i = 0; i < max; i++) {
      obj = clone_object(myitems[i]);
      unguarded("restore_object", DIR + "/data/lockers/" + player_name + 
         "/" + i + ".o");
   }
   set_short("Хранилище " + this_player()->query_r_name());
}

void clean_up(void) {
   int x, y, max;
   object *objs;
   myitems = ({});

   objs = this_object()->query_inventory();
   if (objs) {
      max = sizeof(objs);
   } else {
      max = 0;
   }
   max = max - 1;

   for (x = max; x >= 0; x--) {
      if (objs[x]->is_living()) {
         objs[x]->move(VOID);
      } else {
         objs[x]->destruct();
      }
      destruct();
   }
}

void save_me(void) {
   int x, y, max;
   object *objs;
   myitems = ({});

   unguarded("save_object", DIR + "/data/lockers/" + player_name + "/locker.o");

   objs = this_object()->query_inventory();
   if (objs) {
      max = sizeof(objs);
   } else {
      max = 0;
   }
   y = 0;
   for (x = 0; x < max; x++) {
      if (objs[x]->is_living()) {
      } else {
         myitems += ({ objs[x]->base_name() });
         unguarded("save_object", DIR + "/data/lockers/" + player_name + 
            "/" + y + ".o");
         y = y + 1;
      }
   }

   unguarded("save_object", DIR + "/data/lockers/" + player_name + "/locker.o");
}

void set_player_name(string str) {
   player_name = str;
   set_short("Хранилище " + this_player()->query_r_name());
}

void setup(void) {
   set_short("Чье-то хранилище");
   set_long("Вы можете хранить здесь ваши вещи. Отсюда они никуда не пропадут.");

   add_action("do_save", "хранить");

   set_exits(([
      "запад" : DIR + "/guilds/fighter/rooms/storage.c",
   ]));
}

/* On exit need to save_me and destroy this object... XXX */
int do_save(string str) {
   object obj;
   string file;

   file = DIR + "/guilds/fighter/rooms/storage.c";

   if (!(obj = find_object(file))) {
      catch {
         obj = compile_object(file);
         obj->setup();
         obj->setup_mudlib();
      } : {
         write("Ошибка загрузки " + str);
      }
   }

   if (this_player()->move(obj)) {
      /* XXX Need to move this stuff to other move's like summon/goto */
      this_object()->event("body_leave", this_player());
           
         if (this_player()->query_gender() == "male") {
           tell_room(this_player(), this_player()->query_Name() + " ушел на запад.\n");
           obj->tell_room(this_player(), this_player()->query_Name() + " вошел.\n");
       } else if (this_player()->query_gender() == "female") {
           tell_room(this_player(), this_player()->query_Name() + " ушла на запад.\n");
           obj->tell_room(this_player(), this_player()->query_Name() + " вошла.\n");
       } else {
           tell_room(this_player(), this_player()->query_Name() + " ушло на запад.\n");
           obj->tell_room(this_player(), this_player()->query_Name() + " вошло.\n");
       } 

      this_player()->do_look(this_environment());
   } else {
      write("Здесь случилась ошибка...\n");
   }

   save_me();
   clean_up();
}
