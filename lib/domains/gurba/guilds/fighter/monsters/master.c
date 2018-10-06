inherit "/std/monster";
inherit "/std/modules/m_block_exits";
inherit "/std/modules/m_triggers";

void setup(void) {
   set_name("Боб");
   set_gender("male");
   add_id("глава", "глава гильдии", "боб");
   set_short("Глава гильдии Боб");
   set_long("Боб руководит Гильдией бойцов уже много лет. Его волосы " +
      "поседели, но он по прежнему один из лучших бойцов. Чтобы руководить " +
      "этой организацией, нужно быть лучшим практически во всем.");
   set_r_name("Боба");
   set_d_name("Бобу");
   set_v_name("Боба");
   set_t_name("Бобом");
   set_p_name("Бобе");  
   set_race("human");
   set_level(15);
   add_block("north");

   if (clone_num() != 0) {
      set_actions(40, ({
         "сказать Ты в отличной форме. Становись бойцом!",
         "smile", "emote размахивает его мечом со свистом.", 
       }));
   }

   add_pattern("%s улыбается.", "smile $1");
}

int do_block(object who) {
   if (who->guild_member("fighter")) {
      return 0;
   }
   this_object()->respond("сказать Прости. Но Гильдия бойцов сейчас " +
      "переполнена.");
   return 1;
}
