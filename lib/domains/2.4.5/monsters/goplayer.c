#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

#define INTERVAL 8
#define RESETINTERVAL 8

int count;
object solved_by, wrong_by;

void setup(void) {
   set_name("игрок");
   set_gender( "male" );
   set_short("Игрок в Го");
   set_long("Вы видите сидящего перед доской человека, размышляющего над игрой. " +
      "Кажется, сейчас ему не помешает помощь и почему бы не предложить" +
      "ему сыграть одну игру?\n");
   set_r_name("игрока");
   set_d_name("игроку");
   set_v_name("игрока");
   set_t_name("игроком");
   set_p_name("игроке");
   set_race("human");
   set_level(10);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 100);
   set_skill("combat/defense", 100);
   set_aggressive(0);
}

void do_extra_actions() {
   int x;
   
   x = query_environment()->query_current_problem();

   count = count + 1;
   if (x < 3) {
      if (count > INTERVAL) {
         switch(random(5)) {
            case 0:
               respond("говорить Хмм. Это сложно!");
               break;
            case 1:
               respond("говорить Придурок написавший эту книгу не знал " +
                  "о этой комбинации.");
               break;
            case 2:
               respond("говорить Бросок здесь будет просто потрачен впустую.");
               break;
            case 3:
               respond("говорить Эта группа более живая, чем я.");
               break;
            default:
               respond("говорить Это просто, используя ой-оотоши.");
               break;
         }
         count = 0;
      }
   } else {
      if (count > RESETINTERVAL) {
         count = 0;
         query_environment()->set_current_problem(0);
      }
   }
}

int make_move(int prob) {
   int i;

   if (solved_by) {
      respond("говорить Точно! Это работает!");
      query_environment()->tell_object(this_object(),
         "Он сразу же разыгрывает новую комбинацию.");
      solved_by->message("Вы чувствуете, что становитесь опытнее.");

      solved_by->increase_expr(prob * 100);

      solved_by = nil;
      query_environment()->set_current_problem( prob + 1);
   }
   if (wrong_by) {
      respond("говорить Нет, так это не работает.");
      query_environment()->tell_room(this_object(),
         "Он глубоко задумывается.");
      wrong_by = nil;
   }
}

void outside_message(string str) {
   string name, what;
   int prob;
   object room, who;

   str = ANSI_D->strip_colors(str);
   if (sscanf(str, "%s сказал вам: Играть %s.\n", name, what) == 2 ||
      sscanf(str, "%s говорит: Играть %s.\n", name, what) == 2 ||
      sscanf(str, "%s сказала вам: Играть %s.\n", name, what) == 2 ||
      sscanf(str, "%s сказало вам: Играть %s.\n", name, what) == 2) {
      room = query_environment();

      if (!room) {
         return;
      }
      who = room->present(name);

      if (!who) {
         return;
      }

      prob = room->query_current_problem();
      if (prob == 0) {
         if (what == "б1" || what == "б 1" || what == "1б" || what == "1 б") {
            solved_by = who;
         } else {
            wrong_by = who;
         }
      } else if (prob == 1) {
         if (what == "б2" || what == "б 2" || what == "2б" || what == "2 б") {
            solved_by = who;
         } else {
            wrong_by = who;
         }
      } else if (prob == 2) {
         if (what == "д3" || what == "д 3" || what == "3д" || what == "3 д") {
            solved_by = who;
         } else {
            wrong_by = who;
         }
      }

      query_environment()->tell_room(this_object(),
         "Игрок в Го раздумывает над игрой.");
      if (solved_by) {
         solved_by->message("Вот зараза!");
      } else if (wrong_by) {
         wrong_by->message("Вот зараза!");
      }
      make_move(prob);
   } else {
   if (sscanf(str, "%s сказал вам: %s.\n", name, what) == 2 ||
      sscanf(str, "%s говорит: %s.\n", name, what) == 2 ||
      sscanf(str, "%s сказала вам: %s.\n", name, what) == 2 ||
      sscanf(str, "%s сказало вам: %s.\n", name, what) == 2) {
         respond("говорить Что?");
      }
   }
}

