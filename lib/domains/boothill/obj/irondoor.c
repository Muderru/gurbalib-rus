inherit "/std/door";

void setup(void) {
   set_short("Тяжелая железная дверь");
   set_long("Через такую мощную дверь не пройти без ключа. " +
      "Такие двери обычно устанавливают в банковских сейфах, но зачем она нужна здесь?");
   /* XXX mudlib_setup("west","ironminedoor"); */
   set_id("тяжелая", "железная", "дверь");
   set_obj_i_name("тяжелая железная дверь");
   set_obj_r_name("тяжелой железной двери");
   set_obj_d_name("тяжелой железной двери");
   set_obj_v_name("тяжелую железную дверь");
   set_obj_t_name("тяжелой железной дверью");
   set_obj_p_name("тяжелой железной двери");
   set_obj_gender("female");
}
