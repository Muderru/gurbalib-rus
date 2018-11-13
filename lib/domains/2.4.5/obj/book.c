#include "../domain.h"

inherit "/std/sign";

void setup(void) {
   set_id("книга");
   set_short("Книга на иностранном языке");
   set_long("Эта книга подвешена железной цепью к стене.\n" +
      "На обложке написано: 'ADVENTURING'.\n");
   set_obj_i_name("книга");
   set_obj_r_name("книги");
   set_obj_d_name("книге");
   set_obj_v_name("книгу");
   set_obj_t_name("книгой");
   set_obj_p_name("книге");
   set_obj_gender("female");

   set_message("ADVENTURING.\n\n" +
      "On later years, it has become more and more complicated to " +
      "adventure and\ngather experience. This book was written to be a " +
      "guide for adventurers.\n\n" +
      "As everyone knows, the meaning of life is to gain experience " +
      "and raise\nyour level. This can be done here at the adventurers " +
      "guild, but a small\nfee is sometimes required if there is not " +
      "enough experience.\n\n" +
      "The best way to get experience is to exterminate bad monsters " +
      "that stroll\naround our city. Experience can also be gained by " +
      "killing players.\n\n" +
      "Your reputation will depend on how kind you are. If you kill " +
      "good players,\nyou will be regarded as evil. This is not good, " +
      "because other players\nwill stay out of your way, and gather " +
      "together and attack evil players.\n\n" +
      "The altogether top goal is to become wizard. All wizards will be " +
      "assigned\na castle, which they can rebuild any way they like.\n\n" +
      "Note: As this is a glorified version of real life, you better " +
      "get drunk\nif you are hurt. Then, you will heal faster. Never " +
      "trust privacy. Wizards\nhas eyes everywhere, which they use to " +
      "study usage of their castles etc.");
}
