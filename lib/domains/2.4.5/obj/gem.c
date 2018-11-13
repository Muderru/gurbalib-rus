#include "../domain.h"

inherit "/std/object";

void setup(void) {
   int temp;

   temp = random(3);
   if (temp == 0) {
      set_id("бриллиант");
      add_ids("самоцвет", "драгоценный камень");
      set_short("Бриллиант");
      set_long("Вы видите большой бриллиант, он выглядит ценным.");
      set_obj_i_name("бриллиант");
      set_obj_r_name("бриллианта");
      set_obj_d_name("бриллианту");
      set_obj_v_name("бриллиант");
      set_obj_t_name("бриллиантом");
      set_obj_p_name("бриллианте");
      set_obj_gender("male");
   } else if (temp == 1) {
      set_id("изумруд");
      add_ids("самоцвет", "драгоценный камень");
      set_short("Изумруд");
      set_long("Вы видите большой изумруд, он выглядит ценным.");
      set_obj_i_name("изумруд");
      set_obj_r_name("изумруда");
      set_obj_d_name("изумруду");
      set_obj_v_name("изумруд");
      set_obj_t_name("изумрудом");
      set_obj_p_name("изумруде");
      set_obj_gender("male");
   } else if (temp == 2) {
      set_id("сапфир");
      add_ids("самоцвет", "драгоценный камень");
      set_short("Сапфир");
      set_long("Вы видите большой сапфир, он выглядит ценным.");
      set_obj_i_name("сапфир");
      set_obj_r_name("сапфира");
      set_obj_d_name("сапфиру");
      set_obj_v_name("сапфир");
      set_obj_t_name("сапфиром");
      set_obj_p_name("сапфире");
      set_obj_gender("male");
   }
   set_gettable(1);
   set_value(random(250) + 300);
   set_weight(1);
}
