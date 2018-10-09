string type;
string wield_message;
string unwield_message;
int wielded;

void create(void) {
   type = "single";
}

/* return 1 to allow player to wield this. */
int wield_hook(object player) {
   return 1;
}

void after_wield(object player) {
}

void after_unwield(object player, string cmd) {
}

int is_wieldable(void) {
   return 1;
}

void set_wield_message(string str) {
   wield_message = str;
}

string query_wield_message(void) {
   if (!wield_message) {
            if (this_player()->query_gender() == "male") {
              return "$N вооружился " + this_object()->query_obj_t_name() +".";
          } else if (this_player()->query_gender() == "female") {
              return "$N вооружилась " + this_object()->query_obj_t_name() +".";
          } else {
              return "$N вооружилось " + this_object()->query_obj_t_name() +".";
          }
   }
   return wield_message;
}

void set_unwield_message(string str) {
   unwield_message = str;
}

string query_unwield_message(void) {
   if (!unwield_message) {
            if (this_player()->query_gender() == "male") {
              return "$N перестал использовать " + this_object()->query_obj_v_name() +".";
          } else if (this_player()->query_gender() == "female") {
              return "$N перестала использовать " + this_object()->query_obj_v_name() +".";
          } else {
              return "$N перестало использовать " + this_object()->query_obj_v_name() +".";
          } 
   }
   return unwield_message;
}

void set_wield_type(string type) {
   if (type == "one" || type == "single") {
      type = "single";
   } else if (type == "two" || type == "both" || type == "dual") {
      type = "both";
   }
}

string query_wield_type(void) {
   if (!type || type == "") {
      type = "single";
   }
   return type;
}

void set_wielded(int f) {
   wielded = f;
}

int query_wielded(void) {
   return wielded;
}

int is_wielded(void) {
   return query_wielded();
}

string query_wield_position(void) {
   if (type == "both") {
      return "Держит в обеих руках";
   }
   return "Держит в одной руке";
}
