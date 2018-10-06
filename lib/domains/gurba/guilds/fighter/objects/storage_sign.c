inherit "/std/sign";

void setup(void) {
   set_message(" Наберите 'список' чтобы увидеть содержимое склада.\n Use 'borrow <item>' " +
      "to borrow an item from the storage.\n Use 'store <item>' to return " +
      "the item to the storage.");
   set_id("табличка");
   set_short("Деревянная табличка");
   add_ids("деревянная", "деревянная табличка"); 
   set_obj_i_name("деревянная табличка");
   set_obj_r_name("деревянной таблички");
   set_obj_d_name("деревянной табличке");
   set_obj_v_name("деревянную табличку");
   set_obj_t_name("деревянной табличкой");
   set_obj_p_name("деревянной табличке");
   set_obj_gender("female");
}
