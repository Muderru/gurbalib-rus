#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

#define INTERVAL 8
int count;

void setup() {
   set_name("Лео");
   add_ids("архимаг", "Архимаг", "лео");
   set_gender( "male" );
   set_short("Архимаг Лео");
   set_long("Вы видите перед собой одного из самых великих волшебников современности.");
   set_r_name("Лео");
   set_d_name("Лео");
   set_v_name("Лео");
   set_t_name("Лео");
   set_p_name("Лео");
   set_race("human");
   set_level(40);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 90);
   set_skill("combat/defense", 200);

   set_spell_chance(50);
   set_spell_damage(30);
   set_spell_message("Лео запускает огромный огненный шар в $w.\n");
}

void do_extra_actions() {
   count = count + 1;
   if (count >= INTERVAL) {
      respond("smile");
      count = 0;
   }
}

void give_castle(string who) {
   object player;

   player = this_environment()->present(who);
   if (player) {
      if (query_wizard(player)) {
         /* XXX Not sure if want to do castles that way or not so do this
            instead for now */
         this_environment()->tell_room(this_object(), "Лео сказал: Кажется " +
            "я где-то потерял свои портативные замки, пожалуйста, зайдите позже.");
      } else {
         this_environment()->tell_room(this_object(), "Лео сказал: Прости " +
            player->query_Name() + ", нужно быть билдером чтобы получить свой замок.");
      }
   }
}

void outside_message(string str) {
   string who, what, where;
   object sword, player;

   str = ANSI_D->strip_colors(str);
   str = lowercase(str);

   if (sscanf(str, "%s дал тебе %s.", who, what) == 2) || (sscanf(str, "%s дала тебе %s.", who, what) == 2)  || (sscanf(str, "%s дало тебе %s.", who, what) == 2) {
       player = this_environment()->present(who);
       sword = this_object()->present("убийца орков");

       if (sword) {
          destruct_object(sword);
          if (!player->is_completed_quest("Убийца орков")) {
             player->add_completed_quest("Убийца орков");
             player->increase_expr(200);
             player->message("Поздравляем!!! Вы выполнили квест - " +
                "Убийца орков.\n");
          }
       }
   } else if (sscanf(str, "%s говорит: %s", who, what) == 2) {
      if (strstr(what[0..3], "привет") == 0 || 
          strstr(what[0..1], "hi") == 0) {
          player = this_environment()->present(who);

          this_object()->respond("говорить Добро пожаловать, " + who + ".");
          give_castle(who);
      }
   } else if (sscanf(str, "%s говорит:%scastle%s", who, what, where) == 3) {
      give_castle(who);
   }
}
