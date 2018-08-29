/* Thingol, 9/26/2009. Fixed wrap_message() to wrap to the correct length. */
#include <limits.h>
#include <status.h>
#include <ports.h>

inherit "/sys/lib/runas";

object player;
object ansid;

string user_name;
string newpass;
static int logged_in;
static int data_version;
static int timeout_handle;
private static int auto_admin, auto_wiz;
object query_player(void);

void create(void) {
   ansid = find_object(ANSI_D);
   if (!ansid) {
      ansid = compile_object(ANSI_D);
   }

   auto_admin = 0;
   auto_wiz = 0;
   user_name = "who";
   data_version = 1;
   run_as("nobody");
}

void _open(mixed * tls) {
   if (SITEBAN_D->is_banned(query_ip_number(this_object()))) {
      /* site is banned */
      LOG_D->write_log("logins", ctime(time()) + "\t" + 
         query_ip_number(this_object()) + "\t" + "Banned Site\n");
      send_message("\nYour site is under an access restriction.\n" +
         "Please email " + ADMIN_EMAIL + " about access from your site.\n");
      destruct_object(this_object());
   }
   send_message("Welcome to " + MUD_NAME + ".\n");
   send_message("Running " + LIB_NAME + " " + LIB_VERSION + " on " +
      status()[ST_VERSION] + ".\n");
   send_message("\n");
   send_message(TELNET_D->query_banner());
   send_message("\nEnter your name (or 'who', 'guest', 'quit'): ");
   send_message(1);

   timeout_handle = call_out("login_timeout", 600);
   player = clone_object(PLAYER_OB);
   player->set_user(this_object());
   player->initialize_cmd_path();
   player->initialize_alias();
   player->set_long("A boring player without a description.");
   LOG_D->write_log("logins", ctime(time()) + "\t" + 
      query_ip_number(this_object()) + "\t" + "opening connection\n");
   player->input_to_object(this_object(), "input_name");
}

void open(void) {
   _open(allocate(DRIVER->query_tls_size()));
}

static void _close(mixed * tls, int ld) {
   string ip;

   ip = query_ip_number(this_object());
   if (!ip) {
      ip = "<NO IP>";
   }
   if (ld == 0) {
      player->set_linkdead(1);
      LOG_D->write_log("logins", ctime(time()) + "\t" + ip +
         "\t\t" + this_object()->query_name() + " disconnects\n");
   } else {
      if (player) {
         destruct_object(player);
      }
   }
}

void close(int ld) {
   _close(allocate(DRIVER->query_tls_size()), ld);
}

void login_timeout(void) {
   send_message("\nTimeout.\n");
   destruct_object(player);
   destruct_object(this_object());
}

void quit(void) {
   string str;

   player->save_me();
   LAST_D->add_entry(user_name, 0);
   USER_D->user_offline(user_name, this_object());
   if (query_ip_number(this_object())) {
      LOG_D->write_log("logins", ctime(time()) + "\t" + 
         query_ip_number(this_object()) +
         "\t" + this_object()->query_name() + " quits\n");
   } else {
      LOG_D->write_log("logins", ctime(time()) + "\t" +
         "\t\t" + this_object()->query_name() + " LD quits\n");
   }

   player->destruct();
   destruct_object(this_object());
}

void put_original(string str) {
   if (!str || str == "") {
      return;
   }
   send_message(str);
}

void put_message(string str) {
   string msg;

   if (!str || str == "") {
      return;
   }

   if (query_player()->query_ansi()) {
      msg = ansid->parse_colors(str);
   } else {
      msg = ansid->strip_colors(str);
   }
   send_message(msg);
}

void wrap_message(string str, varargs int chat_flag) {
   string msg, *words, *lines;
   int width, i, j, sz;

   if (!str || str == "") {
      return;
   }

   width = -1;
   /* Get the width from the player */
   if (player) {
      catch(width = player->query_width());
   }

   rlimits(MAX_DEPTH; MAX_TICKS) {
      /* Split the string into lines */
      lines = explode(str, "\n");

      /* Parse each line */
      for (j = 0; j < sizeof(lines); j++) {
         str = lines[j];
         msg = str;
         if (strlen(ansid->strip_colors(str)) > width) {
            int adding;
            string word_todo;

            sz = 0;
            words = explode(str, " ");
            msg = "";

            for (i = 0; i < sizeof(words); i++) {
               word_todo = nil;
               if (strlen(words[i]) > 4 && (strstr(words[i], "%^") != -1)) {
                  word_todo = ansid->strip_colors(words[i]);
               }
               /* word_todo is the word stripped from ansi codes */
               if (!word_todo) {
                  word_todo = words[i];
               }

               if (sz + strlen(word_todo) + adding > width) {
                  msg += "\n";

                  if (chat_flag) {
                     msg += "  ";
                  }

                  /* add length of word without ansi codes */
                  sz = strlen(word_todo) + 2;

                  /* add word with ansi codes */
                  msg += words[i];
               } else {
                  if (adding) {
                     msg += " " + words[i];
                  } else {
                     msg += words[i];
                  }
                  sz += strlen(word_todo) + adding;
               }
               /* determine how many spaces will be added next run */
               if (sz == 0) {
                  adding = 0;
               } else {
                  adding = 1;
               }
            }
         }
         if (query_player()->query_ansi()) {
            msg = ansid->parse_colors(msg);
         } else {
            msg = ansid->strip_colors(msg);
         }

         send_message(msg + "\n");
      }
   }
}

static void _receive_message(mixed * tls, string message) {
   rlimits(MAX_DEPTH; MAX_TICKS) {
      if (player->query_possessing()) {
         set_this_player(player->query_possessing());
      } else {
         set_this_player(player);
      }

      player->receive_message(message);
   }
}

void receive_message(string message) {
   _receive_message(allocate(DRIVER->query_tls_size()), message);
}

/* query USER_D for our privs and setup privileges accordingly */
void restore_privs(void) {
   string privs;

   privs = "";

   if (query_admin(user_name)) {
      privs += "system:";
   }

   if (query_wizard(user_name)) {
      int i, sz;
      string *dn;

      privs += "wizard:";
      dn = DOMAIN_D->query_domains();

      sz = sizeof(dn);
      for (i = 0; i < sz; i++) {
         if (DOMAIN_D->query_domain_member(dn[i], user_name)) {
            privs += dn[i] + ":";
         }
      }
   }

   privs += user_name;

   run_as(privs);
   if (player) {
      player->restore_privs();
   }
}

static void login_user(void) {
   object usr, tmp_player;
   int i, flag, done;
   string start;

   restore_privs();

   send_message(1);

   flag = 0;

   usr = USER_D->find_user(user_name);

   if (usr) {
      send_message("Already logged in.\n");
      flag = 1;
      if (usr->query_player()->query_linkdead() == 1) {
         send_message("Reconnecting to linkdead player.\n");
         tmp_player = usr->query_player();
         usr->set_player(player);
         player = tmp_player;
         set_this_player(player);
         LINKDEAD_D->remove_linkdead(player);
         usr->quit();
         LOG_D->write_log("logins",
            ctime(time()) + "\t" + query_ip_number(this_object()) + "\t" +
            this_object()->query_name() + " reconnects\n");
         player->set_linkdead(0);
         player->set_user(this_object());
         USER_D->user_online(user_name, this_object());
         logged_in = 1;
         player->write_prompt();
         remove_call_out(timeout_handle);
      } else {
         send_message("Reconnect to the other copy? (y/n) : ");
         player->input_to_object(this_object(), "handle_reconnect");
      }
   } else {
      player->set_name(user_name);
      USER_D->user_online(user_name, this_object());
      logged_in = 1;
      player->set_short(capitalize(user_name) + player->query_title());
      send_message("\n\n");
      send_message(TELNET_D->query_motd());
      player->login_player();

      start = player->query_start_room();
      done = 0;
      if (start) {
         done = player->move(start);
         if (!done) {
            send_message("Invalid start room.\n");
         }
      }
      if (!done) {
         done = player->move(STARTING_ROOM);
      }
      if (!done) {
         player->move(VOID);
      }

      player->simple_action("$N $vlog in.\n");
      player->do_look(player->query_environment());
      player->write_prompt();
      remove_call_out(timeout_handle);
      LAST_D->add_entry(user_name, 1);

      LOG_D->write_log("logins", ctime(time()) + "\t" +
         query_ip_number(this_object()) + "\t" +
         this_object()->query_name() + " connects\n");
   }
}

void handle_reconnect(string str) {
   if (!str || str == "") {
      send_message("Please enter y or n : ");
      player->input_to_object(this_object(), "handle_reconnect");
   } else if (lowercase(str) == "y") {
      object usr, tmp_player;
      int flag, i;

      usr = USER_D->find_user(user_name);
      if (usr) {
         flag = 1;
         tmp_player = usr->query_player();
         usr->set_player(player);
         player->set_user(usr);
         player = tmp_player;
         player->set_user(this_object());
         usr->quit();

         LOG_D->write_log("logins", ctime(time()) + "\t" +
           query_ip_number(this_object()) +
           "\t" + this_object()->query_name() + " reconnects\n");

         player->set_linkdead(0);
         send_message("Other copy kicked.\n");
         USER_D->user_online(user_name, this_object());
         logged_in = 1;
         player->write_prompt();
         remove_call_out(timeout_handle);
      }
   } else if (str == "n") {
      send_message("So long then.\n");
      remove_call_out(timeout_handle);
      player->destruct();
      destruct_object(this_object());
   } else {
      send_message("Please enter y or n : ");
      player->input_to_object(this_object(), "handle_reconnect");
   }
}

string query_name(void) {
   return user_name;
}

/* The MSSP specification can be found here: 
   http://tintin.sourceforge.net/mssp/
*/
void mssp_reply(void) {
   /* Change these values in /include/mssp.h */

   send_message("\r\nMSSP-REPLY-START\r\n");

   /* These are Required */
   send_message("NAME\t" + IMUD_NAME + "\r\n"); /* Name of the MUD */
   /* Current number of logged in players */
   send_message("PLAYERS\t" + sizeof(players()) + "\r\n");
   /* Unix time value of the startup time of the MUD */
   send_message("UPTIME\t" + status()[ST_STARTTIME] + "\r\n");

   /* Generic */
   send_message("PORT\t" + LOGIN_PORT + "\r\n");
   send_message("CODEBASE\t" + LIB_NAME + LIB_VERSION + "/" + 
      status()[ST_VERSION] + "\r\n");
   send_message("CONTACT\t" + ADMIN_EMAIL + "\r\n");
   #ifdef WEBSITE
   send_message("WEBSITE\t" + WEBSITE + "\r\n");
   #endif

   /* Categorization */
   send_message("FAMILY\t" + MSSP_FAMILY + "\r\n");
   send_message("STATUS\t" + MSSP_STATUS + "\r\n");
   send_message("INTERMUD\t" + MSSP_INTERMUD + "\r\n");

   /* Protocols */
   send_message("ANSI\t" + MSSP_ANSI + "\r\n");
   send_message("MCCP\t" + MSSP_MCCP + "\r\n");

   /* Commercial */
   send_message("PAY TO PLAY\t" + MSSP_PAY_TO_PLAY + "\r\n");
   send_message("PAY FOR PERKS\t" + MSSP_PAY_FOR_PERKS + "\r\n");

   send_message("MSSP-REPLY-END\r\n");
}

void login_who(void) {
   string *out;
   int i, max;

   out = USER_D->list_players(0);

   max = sizeof(out);
   for (i = 0; i < max; i++) {
      write(out[i]);
   }
}

void write_races(void) {
   int i;
   string line, *races;

   send_message("\n");

   races = RACE_D->query_races();
   for (i = 0; i < sizeof(races); i++) {
      line = capitalize(races[i]) + "              ";
      line = line[..10];
      line += " - " + RACE_D->query_race_short(races[i]) + "\n";
      send_message(line);
   }
   send_message("\n");
}

void input_name(string str) {
   string usr;
   int i;

   if (str == "MSSP-REQUEST") {
      mssp_reply();

      str = "";            /* force login fail */
   }

   if (lowercase(str) == "quit") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   } else if (lowercase(str) == "who") {
      player->set_name("who");
      login_who();
      str = "";
   }  else if (lowercase(str) == "guest") {
      usr = "guest";
      while (USER_D->find_user(usr) ) {
         i++;
         usr = "guest" + (string) i;
         }
      player->set_name(usr);
      user_name = usr;

      /* Skip ahead for the guest user, no need for password and other stuff */
      send_message("Please enter your gender (male/female/neuter) : ");
      player->input_to_object(this_object(), "input_get_gender");
      return;
   } 

   if (!str || str == "") {
      send_message("\r\nPlease enter your name : ");
      player->input_to_object(this_object(), "input_name");
   } else {
      str = lowercase(str);

      if (strlen(str) > 16) {
         send_message("Name too long.\n");
         input_name("");
         return;
      }
      if (!USER_D->valid_player_name(str)) {
         send_message("A name must start with a letter, and can contain " +
            "letters and numbers.\n");
         input_name("");
         return;
      }

      user_name = str;
      if (BANISH_D->is_banished(user_name)) {
         /* user_name is a banished name */
         LOG_D->write_log("logins", ctime(time()) + "\t" +
            query_ip_number(this_object()) +
            "\t" + query_name() + " <- banished name\n");
         send_message("\nThe name '" + user_name +
            "' is reserved and not available for use.\n");
         destruct_object(player);
         destruct_object(this_object());
         return;
      }
      if (USER_D->player_exists(str)) {
         /* Player exists */
         player->set_name(user_name);
         player->restore_me();
         send_message("Enter your password: ");
         send_message(0);
         player->input_to_object(this_object(), "input_old_passwd");
      } else {
         player->set_name(user_name);
         if (SITEBAN_D->is_newbanned(query_ip_number(this_object()))) {
            /* site is new character banned */
            LOG_D->write_log("logins", ctime(time()) + "\t" +
               query_ip_number(this_object()) +
               "\t" + query_name() + " <- Newbanned site\n");
            send_message("\nThis site is under development and not yet open " +
               "to players.\nPlease email " + ADMIN_EMAIL +
               " about future access from your site.\n");
            destruct_object(player);
            destruct_object(this_object());
            return;
         }

         send_message("Ah. New player.\n");
         send_message("Is '" + user_name + "' correct (y/n)? : ");
         player->input_to_object(this_object(), "input_correct_name");
      }
   }
}

void input_correct_name(string str) {
   if (!str || str == "") {
      send_message("Please enter 'y' or 'n' : ");
      send_message("Is '" + user_name + "' correct (y/n)? : ");
      player->input_to_object(this_object(), "input_correct_name");
   }

   if (lowercase(str) == "y" || lowercase(str) == "yes") {
      send_message("Enter your password: ");
      send_message(0);
      player->input_to_object(this_object(), "input_new_passwd");
   } else {
      send_message("Enter your name : ");
      send_message(1);
      player->input_to_object(this_object(), "input_name");
   }
}

void input_old_passwd(string str) {
   if (!str || str == "") {
      send_message("\nPlease enter your password: ");
      send_message(0);
      player->input_to_object(this_object(), "input_old_passwd");
   }
   if (USER_D->login(user_name, str)) {
      login_user();
   } else {
      send_message("\nPasswords don't match!\n");
      destruct_object(player);
      destruct_object(this_object());
   }
}

void change_passwd(string str) {
   string passwd2;

   send_message("\nOld password: ");
   send_message(0);
   player->input_to_object(this_object(), "change_passwd2");
}

void change_passwd2(string str) {
   if (!str || str == "") { 
      send_message("\nNo password, aborting.\n");
      send_message(1);
      return;
   }

   if (!USER_D->login(user_name, str)) {
      send_message("\nInvalid password, aborting.\n");
      send_message(1);
      return;
   }

   newpass = str;
   send_message("\nNew, password: ");
   send_message(0);
   player->input_to_object(this_object(), "change_passwd3");
}

void change_passwd3(string str) {
   if (!str || str == "") { 
      send_message("\nNo password, aborting.\n");
      send_message(1);
      return;
   }

   newpass = str;
   send_message("\nAgain, new password: ");
   send_message(0);
   player->input_to_object(this_object(), "change_passwd4");
}

void change_passwd4(string str) {
   send_message(1);

   if (!str || str == "") { 
      send_message("\nNo password, aborting.\n");
      return;
   }

   if (newpass != str) {
      send_message("\nPasswords do not match.\n");
      return;
   } else {
      LOG_D->write_log("change_passwd", ctime(time()) + "\t" +
         query_ip_number(this_object()) + "\t" + query_name() + "\n");

      USER_D->set_password(this_player()->query_name(), str);
      send_message("\nPassword successfully changed.\n");
   }
}

void input_new_passwd(string str) {
   if (!str || str == "") {
      send_message("\nPlease enter your password: ");
      send_message(0);
      player->input_to_object(this_object(), "input_new_passwd");
   } else {
      LOG_D->write_log("new_players", ctime(time()) + "\t" +
         query_ip_number(this_object()) + "\t" + query_name() + "\n");
      USER_D->new_user(user_name, str);
      send_message("\nEnter password again: ");
      send_message(0);
      player->input_to_object(this_object(), "input_check_passwd");
   }
}

void input_check_passwd(string str) {
   if (!str || str == "") {
      send_message("\nPlease enter the password again: ");
      send_message(0);
      player->input_to_object(this_object(), "input_check_passwd");
   } else {
      if (USER_D->login(user_name, str)) {
         send_message("\nPlease enter your real name : ");
         send_message(1);
         player->input_to_object(this_object(), "input_get_real_name");
      } else {
         send_message("\nThe passwords don't match.\n");
         send_message("Goodbye!!!\n");
         USER_D->delete_user(user_name);
         destruct_object(player);
         destruct_object(this_object());
      }
   }
}

void input_get_real_name(string str) {
   player->set_realname(str);

   send_message("Please enter your email address : ");
   player->input_to_object(this_object(), "input_get_email");
}

void input_get_email(string str) {
   player->set_email(str);
   send_message("Please enter your website : ");
   player->input_to_object(this_object(), "input_get_website");
}

void input_get_website(string str) {
   player->set_website(str);

   send_message("\nEnter your gender (male/female/neuter) : ");
   player->input_to_object(this_object(), "input_get_gender");
}

void input_get_gender(string str) {
   if (!str || str == "") {
      send_message("Please enter your gender (male/female/neuter) : ");
      player->input_to_object(this_object(), "input_get_gender");
      return;
   }

   str = lowercase(str);
   if (str == "m" || str == "male") {
      player->set_gender("male");
   } else if (str == "f" || str == "female") {
      player->set_gender("female");
   } else if (str == "n" || str == "neuter") {
      player->set_gender("neuter");
   } else if (str == "quit") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   } else {
      send_message("Please use 'male', 'female' or 'neuter'.\n");
      send_message("Please enter your gender (male/female/neuter) : ");
      player->input_to_object(this_object(), "input_get_gender");
      return;
   }
   write_races();
   send_message("Please choose one of the races, or type 'info <race>' : ");
   player->input_to_object(this_object(), "input_get_race");
}

void input_get_race(string str) {
   if (!str || str == "") {
      write_races();
      send_message("Please choose one of the races, or type 'info <race>' : ");
      player->input_to_object(this_object(), "input_get_race");
      return;
   }
   str = lowercase(str);

   if (str == "quit") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   }

   if ( (strlen(str) > 5) && (str[0..3] == "info") ) {
      string r;

      r = str[5..( strlen(str) - 1)];
      if (RACE_D->is_race( r ) ) {
         send_message( RACE_D->query_race_long(r) + "\n\n" +
            "Please choose one of the races, or type 'info <race>' : ");
         player->input_to_object(this_object(), "input_get_race");
         return;
      }
   }
         
   if (!RACE_D->is_race(str)) {
      send_message("Please choose one of the races, or type 'info <race>' : ");
      player->input_to_object(this_object(), "input_get_race");
      return;
   }

   player->set_race(str, 1);

   player->set_hp(player->query_max_hp());
   player->set_mana(player->query_max_mana());
   player->set_end(player->query_max_end());
   player->save_me();
   login_user();
}

void set_player(object p) {
   player = p;
}

object query_player(void) {
   return player;
}

void set_auto_admin(int flag) {
   if (require_priv("system") ) {
      auto_admin = flag;
   }
}

int query_auto_admin() {
   return auto_admin;
}

void set_auto_wiz(int flag) {
   if (require_priv("system") ) {
      auto_wiz = flag;
   }
}

int query_auto_wiz() {
   return auto_wiz;
}

static void _receive_error(mixed * tls, string err) {
   console_msg("Network error in user object: " + object_name(this_object()) +
      " : " + err + "\n");
}

void receive_error(string err) {
   _receive_error(allocate(DRIVER->query_tls_size()), err);
}

static void upgraded(void) {
   ansid = find_object(ANSI_D);
   if (data_version) {
      return;
   }
   if (query_player()) {
      logged_in = data_version = 1;
   }
}

int online(void) {
   return logged_in;
}
