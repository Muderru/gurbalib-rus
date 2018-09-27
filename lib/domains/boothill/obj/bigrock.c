#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("валун");
   set_adj("огромный");
   set_short("Огромный валун");
   set_long("Этот валун занимает половину пещеры. На идеально гладкой поверхности " +
      "валуна не видно ни единой царапины, хотя все стены пещеры вокруг избиты " +
      "ударами кирок. Чтобы сдвинуть этот валун понадобится слон, или лучше " +
      "два.");
   set_obj_i_name("огромный валун");
   set_obj_r_name("огромного валуна");
   set_obj_d_name("огромному валуну");
   set_obj_v_name("огромный валун");
   set_obj_t_name("огромным валуном");
   set_obj_p_name("огромном валуне");
   set_obj_gender("male");
}

