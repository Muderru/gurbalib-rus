/* Created by Fudge */

inherit "/std/object";
inherit "/std/modules/m_openable";
inherit "/std/modules/m_messages";
inherit "/std/modules/m_block_exits";

static string our_exit, our_identity, sibling_room;
static object sibling;

void create(void) {
   ::create();
   set_id("door");
   set_short("A wooden door");
   set_long("Your average wooden door.");
   set_gettable(0);
   set_open_state(0);
}

int is_door(void) {
   return 1;
}

string query_door_exit(void) {
   return our_exit;
}

void refresh_sibling(void) {
   object *obs;
   int i;

   if (!sibling) {
      /* We've lost the cached sibling. Find it again. */
      sibling_room = this_object()->query_environment()->query_exit(our_exit);
      obs = sibling_room->query_inventory();
      if (obs) {
         for (i = 0; i < sizeof(obs); i++) {
            if (obs[i]->query_door_identity() == our_identity
               && obs[i]->query_door_exit() == invert_exit(our_exit)) {
               sibling = obs[i];
            }
         }
      }
   }
}

void update_sibling(void) {

   if (!sibling) {
      refresh_sibling();
   }

   if (this_object()->query_open_state() == 1) {
      sibling->do_open(0);
   }

   if (sibling) {
      if (sibling->query_open_state() == 1) {
         /* We need to update this doors state */
         this_object()->do_open(0);
      }
   }
}

void do_on_open(object who) {
   if (!sibling) {
      refresh_sibling();
   }

   if (sibling) {
      if (sibling->query_open_state() == 1) {
         return;
      }
      sibling->set_open_state(1);
   }
}

void do_on_close(object who) {
   if (!sibling) {
      refresh_sibling();
   }

   if (sibling) {
      if (!sibling->query_open_state()) {
         return;
      }
      sibling->set_open_state(0);
   }
}

int do_block(object who) {
   if (this_object()->query_open_state()) {
      return 0;
   }
   return 1;
}

void mudlib_setup(mixed *args) {

   if (sizeof(args) != 2) {
      return;
   }

   add_adj(args[0]);

   our_exit = args[0];
   our_identity = args[1];
   update_sibling();
   add_block(our_exit);
   set_open_description(query_open_description() + " %^CYAN%^[" + our_exit +
      "]%^RESET%^");
   set_closed_description(query_closed_description() + " %^CYAN%^[" + our_exit +
      "]%^RESET%^");
   update_description();
}

string query_door_identity(void) {
   return our_identity;
}

void set_door_identity(string ident) {
   our_identity = ident;
}
