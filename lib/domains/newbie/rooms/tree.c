#include "../domain.h"

inherit "/std/room";

#define FILE DIR + "/rooms/entrance.c"

void setup(void) {
   add_area("newbie");

   set_short("Северная часть поля");
   set_long("Вы остановились у старого мертвого дерева в центре большого поля. " +
      " Чуть дальше на юге вы замечаете дорогу, ведущую к городу.  Также " +
      "тут привлекает внимание странная нора в холме на востоке.");

   set_exits(([
      "юг" : STARTING_ROOM,
      "восток" : "#enter_hole",
   ]));

   set_objects(
      DIR + "/obj/sign", 
      DIR + "/obj/tree"
   );

   add_item("нора", "Это довольно таки большая нора.  Вы даже сможете " +
      "наверно протиснуться в нее.");

   add_action("break_branch", "сломать");
   add_action("squeeze_hole", "протиснуться");
}

int break_branch(string str) {
   object obj;

   if ((str == "ветка") || (str == "ветку")) {
      if (this_player()->is_completed_quest("NewbieVille")) {
         write("На дереве не осталось доступных веток, все обломали.\n");
      } else {
         if (this_player()->query_gender() == "male") {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " сломал ветку с дерева.\n");
       } else if (this_player()->query_gender() == "female") {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " сломала ветку с дерева.\n");
       } else {
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " сломало ветку с дерева.\n");
       }
         write("Вы отломили ветку от дерева.\n");
         obj = clone_object(DIR + "/obj/stick.c");
         obj->move(this_player());
         obj->setup();
      }

      return 1;
   } else {
      return 0;
   }
}

void enter_hole(void) {
   object obj;

   if (this_player()->is_completed_quest("NewbieVille")) {
      write("Вы больше не можете пролезть в нору.");
      this_object()->tell_room(this_player(), this_player()->query_Name() + 
         " пытается пролезть через нору, " +
         "но неудачно.");
      return;
   } else {
      obj = find_object(FILE);
      if (!obj) {
         obj = compile_object(FILE);
         if (!obj) {
            write("Ошибка в загрузке направления.\n");
            return;
         }
         obj->setup();
         obj->setup_mudlib();
      }
      if (this_player()->move(obj)) {
         write("Вы протискиваетесь через нору.");
         this_object()->tell_room(this_player(),
            this_player()->query_Name() + " протискивается через нору.\n");
         this_player()->do_look(this_environment());
      }
   }
   return;
}

int squeeze_hole(string str) {
   object obj;

   if ((str == "hole") || (str == "") || (str == "нора") || (str == "нору")) {
      enter_hole();
      return 1;
   }
   return 0;
}
