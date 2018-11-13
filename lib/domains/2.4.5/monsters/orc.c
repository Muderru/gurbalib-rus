#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";
inherit "/std/modules/m_block_exits";

#define INTERVAL 5
int count;

void setup() {
   object obj;
   set_name("орк");
   set_gender( "male" );
   add_ids("грязный", "вонючий");
   set_short("Орк");
   set_long("Это грязный и вонючий орк.");
   set_r_name("орка");
   set_d_name("орку");
   set_v_name("орка");
   set_t_name("орком");
   set_p_name("орке"); 
   set_race("orc");
   set_aggressive(1);
   set_level(random(2) + 1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   add_block("север");

   switch(random(3)) {
      case 0:
         obj = clone_object(DIR + "/obj/knife.c");
      case 1:
         obj = clone_object(DIR + "/obj/curved_knife.c");
      default:
         obj = clone_object(DIR + "/obj/axe.c");
   }
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}

void do_extra_actions() {
   count = count + 1;
   if (count >= INTERVAL) {
      switch(random(7)) {
         case 0:
            respond("говорить Убить его!");
            break;
         case 1:
            respond("говорить Жалкие люди!");
            break;
         case 2:
            respond("говорить Остановить его!");
            break;
         case 3:
            respond("говорить Взять его!");
            break;
         case 4:
            respond("говорить Выпотрошите ему кишки!");
            break;
         case 5:
            respond("говорить Убейте их, пока они не сбежали!");
            break;
         default:
            respond("говорить Что тут происходит?");
            break;
      }
      count = 0;
   }
}

int do_block(object who) {
   return 1;
}
