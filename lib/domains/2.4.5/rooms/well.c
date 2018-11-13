#include "../domain.h"

inherit "/std/room";
inherit "/std/modules/m_block_exits";

void setup(void) {
   add_area("2.4.5");

   set_short("Дно колодца");
   set_long("Вы зачем-то спустились на дно старого колодца. Здесь " +
      "сыро и мерзко. В западной стене вы видите дверь и рычаг рядом " +
      "с ней. На север отходит полукруглый туннель. Сверху с поверхности " +
      "брызжет слабый свет.");

   add_exit("север", DIR + "/rooms/maze/maze1.c");
   add_exit("запад", DIR + "/rooms/sub/door_trap.c");
   add_exit("вверх", DIR + "/rooms/narr_alley.c");

   add_item("рычаг", "Вы видите короткую деревянную рукоятку, на которую можно нажать.");
   add_item("дверь", "#do_look_door");

   add_action("pull_lever", "нажать");
   add_action("pull_lever", "повернуть");

   add_block("запад");
}

object load_traproom() {
   object traproom;
   string trapname;

   trapname = DIR + "/rooms/sub/door_trap";
   traproom = find_object(trapname);
   if (!traproom) {
      if (traproom = compile_object(trapname)) {
         traproom->setup();
         traproom->setup_mudlib();
      }
   }
   return traproom;
}

string do_look_door() {
   object traproom;

   traproom = load_traproom();
   if (!traproom || traproom->query_trap()) {
      return "Дверь открыта.";
   } else {
      return "Дверь закрыта.";
   }
}

int pull_lever(string str) {
   object traproom;

   if (empty_str(str) || str != "рычаг") {
      return 0;
   }

   traproom = load_traproom();

   if (!traproom) {
      write("Кажется, что застрял рычаг.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " пытается нажать рычаг, но он застрял.\n");
      return 0;
   }

   if (traproom->toggle_door()) {
      write("Вы нажали на рычаг.\n");
      if (this_player()->query_gender() == "male") {
      tell_room(this_player(), this_player()->query_Name() +
         " нажал на рычаг.\n");
      } else if (this_player()->query_gender() == "female") {
      tell_room(this_player(), this_player()->query_Name() +
         " нажала на рычаг.\n");
      } else {
      tell_room(this_player(), this_player()->query_Name() +
         " нажало на рычаг.\n");
      }
      if (traproom->query_trap()) {
         tell_room(nil, "Болт скользит на место.\n");
      } else {
         tell_room(nil, "Болт скользит с места.\n");
      }
      return 1;
   }
   return 0;
}

int do_block(object who) {
   object traproom;

   traproom = load_traproom();

   if (!traproom || !traproom->query_trap()) {
      write("Дверь заблокирована.\n");
      return 1;
   } else {
      return 0;
   }
}

int do_open(string str) {
   object traproom;

   if (str == "дверь") {
      traproom = load_traproom();
      if (!traproom || traproom->query_trap()) {
         write("Дверь уже открыта.");
         tell_room(this_player(), this_player()->query_Name() + " пытается " +
            "открыть открытую дверь еще шире.\n");
         return 1;
      }
      write("Кажется, дверь не работает.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " смотрит на дверь в недоумении.\n");
      return 1;
   }
   return 0;
}

int do_close(string str) {
   return do_open(str);
}

