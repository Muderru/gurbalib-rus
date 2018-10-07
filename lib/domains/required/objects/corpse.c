inherit "/std/container";

static string orig_name;

void setup(void) { }

void create(void) {
   ::create();

   if (clone_num() != 0) {
      call_out("decompose", 30);
   }

   set_id("труп");
   set_short("Дурно пахнущий труп");
   set_long("Это полуразложившийся вонючий труп.");
   set_obj_i_name("труп");
   set_obj_r_name("трупа");
   set_obj_d_name("трупу");
   set_obj_v_name("труп");
   set_obj_t_name("трупом");
   set_obj_p_name("трупе");
   set_obj_gender("male");
}

void set_name(string name) {
   object obj;
   obj = this_environment()->present(name);
   orig_name = obj->query_r_name();
   set_short("Труп " + orig_name);
}

void corpse_destruct(void) {
   int i, dim;
   object *inv;

   inv = query_inventory();
   for (i = 0, dim = sizeof(inv); i < dim; i++) {
      inv[i]->move(query_environment());
   }
   query_environment()->tell_room(nil, "Пепел к пеплу, прах к праху.");
   destruct();
}

void decompose(void) {
   call_out("corpse_destruct", 30);
   if (!orig_name) {
      orig_name = "чей-то";
   }

   set_short("Частично разложившийся труп " + orig_name);
   query_environment()->tell_room(nil, "Труп " +
      orig_name + " частично разложился.");
}
