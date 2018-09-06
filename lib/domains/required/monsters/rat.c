inherit "/std/monster";

void setup(void) {
   set_name("крыса");  /* Именительный */

   set_gender( "female" );

   add_adj("грязная", "крысу");
   set_short("Маленькая вонючая крыса");  
   set_long("Маленькая вонючая крыса копошится тут.");
   set_r_name("маленькой вонючей крысы");
   set_d_name("маленькой вонючей крысе");
   set_v_name("маленькую вонючую крысу");
   set_t_name("маленькой вонючей крысой");
   set_p_name("маленькой вонючей крысе");
   set_race("rodent");
   set_level(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
}
