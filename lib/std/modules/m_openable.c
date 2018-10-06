static int open_state;
static string open_message;
static string close_message;
static string open_desc;
static string closed_desc;

int is_openable(void) {
   return 1;
}

int is_closable(void) {
   return 1;
}

int can_open(object who) {
   return 1;
}

int is_open(void) {
   return (open_state == 1);
}

int is_closed(void) {
   return (open_state == 0);
}

int can_close(object who) {
   return 1;
}

void set_open_message(string str) {
   open_message = str;
}

void set_close_message(string str) {
   close_message = str;
}

string query_open_message(void) {
   if (!open_message || open_message == "") {
            if (this_player()->query_gender() == "male") {
              return "$N открыл "+ this_object()->query_obj_i_name() +".";
          } else if (this_player()->query_gender() == "female") {
              return "$N открыла "+ this_object()->query_obj_i_name() +".";
          } else {
              return "$N открыло "+ this_object()->query_obj_i_name() +".";
          }
   }
   return open_message;
}

string query_close_message(void) {
   if (!close_message || close_message == "") {
            if (this_player()->query_gender() == "male") {
              return "$N закрыл "+ this_object()->query_obj_i_name() +".";
          } else if (this_player()->query_gender() == "female") {
              return "$N закрыла "+ this_object()->query_obj_i_name() +".";
          } else {
              return "$N закрыло "+ this_object()->query_obj_i_name() +".";
          }
   }
   return close_message;
}

void set_open_description(string str) {
   open_desc = str;
}

void set_closed_description(string str) {
   closed_desc = str;
}

string query_open_description(void) {
   return open_desc;
}

string query_closed_description(void) {
   return closed_desc;
}

string query_default_closed_desc() {
   return this_object()->query_short() + " %^RED%^[закрыто]%^RESET%^";
}

string query_default_open_desc() {
   return this_object()->query_short() + " %^GREEN%^[открыто]%^RESET%^";
}

void update_description(void) {

   if (!open_desc || open_desc == "") {
      open_desc = query_default_open_desc();
   }

   if (!closed_desc || closed_desc == "") {
      closed_desc = query_default_closed_desc();
   }

   if (open_state == 1) {
      this_object()->set_short(query_open_description());
   } else {
      this_object()->set_short(query_closed_description());
   }
}

void set_open_state(int state) {
   open_state = state;
   if (state == 1) {
      this_object()->simple_action("$N открыт.");
   } else {
      this_object()->simple_action("$N закрыт.");
   }

   update_description();
}

int query_open_state(void) {
   return open_state;
}

string query_cannot_open_message(object who) {
   return "Кажется, замок заело.";
}

int do_open(object who) {
   if (open_state == 1) {
      write("Это уже открыто.");
      return 0;
   }
   if (!can_open(who)) {
      who->targeted_action(query_cannot_open_message(who), nil,
         this_object());
      return 0;
   }
   open_state = 1;
   update_description();
   if (who) {
      who->targeted_action(query_open_message(), nil, this_object());
   } else {
      this_object()->simple_action("$N открыт.");
   }
   return 1;
}

int do_close(object who) {
   if (!open_state) {
      write("Это уже закрыто.");
      return 0;
   }
   open_state = 0;
   update_description();
   if (who) {
      who->targeted_action(query_close_message(), nil, this_object());
   } else {
      this_object()->simple_action("$N закрыт.");
   }
   return 1;
}
