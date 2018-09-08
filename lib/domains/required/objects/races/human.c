/* Definition of the human race */
inherit "/std/race";

void create(void) {
   ::create();

   set_race_short_desc("Люди обречены оставаться посредственностями " +
      "во всех аспектах.");
   set_race_long_desc("Люди преобладают в этом мире. Сила их расы в " +
      "их многочисленности. Поэтому особенности всех остальных рас сравниваются " +
      "с особенностями людей. Люди могут заниматься любым делом, " +
      "но нигде они, как правило, не достигают высот.");
   set_language("english");
/* no need to do this: set_skill("language/engilsh",100); */
}
