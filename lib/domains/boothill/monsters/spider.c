inherit "/std/monster";

void setup(void) {
   set_name("паук");

   add_adj("пещерный");
   set_short("Пещерный паук");
   set_long("Даже его самые маленькие собратья внушают многим людям страх, ну а эта " +
      "метровая тварь с полуметровыми хелицерами одним своим видом способна напугать до смерти.");
   set_r_name("пещерного паука");
   set_d_name("пещерному пауку");
   set_v_name("пещерного паука");
   set_t_name("пещерным пауком");
   set_p_name("пещерном пауке");
   set_gender( "male" );
   set_race("spider");
   set_level(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   set_aggressive(1);
}
