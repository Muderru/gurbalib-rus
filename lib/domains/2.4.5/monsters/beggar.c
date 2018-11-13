#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

int count;
int buying_beer;
#define INTERVAL 5

void setup() {
   buying_beer = 0;
   set_name("нищий");
   add_id("грязный");
   set_gender( "male" );
   set_short("Грязный нищий");
   set_long("Этот старик уже несколько лет не мылся и от реально сильно воняет.");
   set_r_name("нищего");
   set_d_name("нищему");
   set_v_name("нищего");
   set_t_name("нищим");
   set_p_name("нищем");   
   set_race("human");
   set_level(3);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
}

void do_extra_actions() {
   count = count + 1;

   if (buying_beer == 0 && count >= INTERVAL) {
      switch(random(3)) {
         case 0:
           respond("говорить Пожалуйста, дайте пару монеток бедному нищему!");
           break;
         case 1:
           respond("говорить Почему у меня нет денег?");
           break;
         default:
           respond("говорить Две монетки, дайте пожалуйста!");
           break;
      }
      count = 0;
   }
/* May need to change this up.... XXX check for coin and value? */
/*
 * respond() uses a callout so we have to string them together
 * with call_out() that is greater than the delay of respond().
 * I think.. :)
 */
   if (buying_beer == 0 && this_object()->query_total_money() > 12) {
      buying_beer = 1;
      call_out("go_east", 5);
   }
}

static void go_east() {
   respond("идти восток");
   call_out("buy_beer", 5);
}

static void buy_beer() {
   respond("купить пиво");
   call_out("drink_beer", 5);
}

static void drink_beer() {
   respond("пить пиво");
   call_out("go_west", 5);
}

static void go_west() {
   respond("идти запад");
   buying_beer = 0;
}

void outside_message(string str) {
   int x;
   str = ANSI_D->strip_colors(str);
   x = strlen(str) -3;
   
   str = str[..x];

   if (is_fighting() && random(100) < 20) {
      respond("говорить Зачем мне это?");
   }
}
