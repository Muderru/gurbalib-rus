/* Handle both system wide aliases and wizard aliases. */
mapping player_alias;
mapping wizard_alias;

#define DATAFILE "/sys/daemons/data/alias_d.o"

nomask void restore_me(void) {
   unguarded("restore_object", DATAFILE);
}

nomask void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void create(void) {

   if (file_exists(DATAFILE)) {
      restore_me();
   } else {
   /* Setup some basic defaults encase we do not have anything setup */
   player_alias = ([
         "с": "идти север $*",
         "ю": "идти юг $*",
         "в": "идти восток $*",
         "з": "идти запад $*",
         "вв": "идти вверх $*",
         "вн": "идти вниз $*",
         "св": "идти северо-восток $*",
         "сз": "идти северо-запад $*",
         "юв": "идти юго-восток $*",
         "юз": "идти юго-запад $*",
         "и": "инвентарь $*",
         "инв": "инвентарь $*",
         "э": "инвентарь $*",
         "экип": "инвентарь $*",
         "сч": "счет $*",
         "пить": "есть $*",
         "см": "смотреть $*"
      ]);
      wizard_alias = ([
         "z": "update $*"
      ]);

      save_me();
   }
}

void add_player_alias(string cmd, string alias) {
   if (!player_alias) {
      player_alias = ([]);
   }

   player_alias[cmd] = alias;
   write("Алиас игрока " + cmd + " добавлен.");
   save_me();
}

int remove_player_alias(string cmd) {
   if (!player_alias) {
      player_alias = ([]);
   }

   if (!member_map(cmd, player_alias)) {
      return 0;
   }

   player_alias[cmd] = nil;
   write("Алиас игрока " + cmd + " удален.");
   save_me();
   return 1;
}

void add_wizard_alias(string cmd, string alias) {
   if (!wizard_alias) {
      wizard_alias = ([]);
   }

   wizard_alias[cmd] = alias;
   write("Алиас билдера " + cmd + " добавлен.");
   save_me();
}

int remove_wizard_alias(string cmd) {
   if (!wizard_alias) {
      wizard_alias = ([]);
   }

   if (!member_map(cmd, wizard_alias)) {
      return 0;
   }
   wizard_alias[cmd] = nil;
   write("алиас билдера " + cmd + " удален.");
   save_me();
   return 1;
}

int is_alias(string cmd) {

   if (!player_alias) {
      player_alias = ([]);
   }

   if (!wizard_alias) {
      wizard_alias = ([]);
   }

   if (player_alias[cmd]) {
      return 1;
   }

   if (query_wizard(this_player()->query_name())) {
      if (wizard_alias[cmd]) {
         return 1;
      }
   }

   return 0;
}

string query_alias(string cmd) {
   if (!player_alias) {
      player_alias = ([]);
   }

   if (!wizard_alias) {
      wizard_alias = ([]);
   }

   if (player_alias[cmd]) {
      return player_alias[cmd];
   }

   if (query_wizard(this_player()->query_name())) {
      if (wizard_alias[cmd]) {
         return wizard_alias[cmd];
      }
   }

   return nil;
}

string do_expand(string alias, string arg) {
   string *args;
   int i, sz;

   alias = replace_string(alias, "$*", arg);

   if (arg && arg != "") {
      args = explode(arg, " ");

      sz = sizeof(args);
      if (sz >= 10) {
         sz = 10;
      }
      for (i = 0; i < sz; i++) {
         alias = replace_string(alias, "$" + i, args[i]);
      }
   }
   return alias;
}

string expand_alias(string cmd) {
   string arg, alias;

   if (!cmd || cmd == "") {
      return "";
   }

   arg = "";

   sscanf(cmd, "%s %s", cmd, arg);

   if (is_alias(cmd)) {
      alias = query_alias(cmd);
      if (!alias) {
         return nil;
      }
      return do_expand(alias, arg);
   } else {
      if (!arg || arg == "") {
         return cmd;
      }
      return cmd + " " + arg;
   }
}

string *show_alias(string type, string str) {
   string line, *rules, *aliases;
   int i, done;

   done = 0;
   rules = ( { } );
   if (!str || str == "") {
      if (!type || type == "" || type == "player") {
         rules += ( { "Алиасы игрока:" } );
         aliases = map_indices(player_alias);
         for (i = 0; i < sizeof(aliases); i++) {
            line = aliases[i];
            rules += ({ "   " + line + ": " + player_alias[line] });
         }
      }
      if (!type || type == "" || type == "wizard" || type == "wiz") {
         rules += ( { "Алиасы билдера:" } );
         aliases = ({ });
         aliases = map_indices(wizard_alias);
         for (i = 0; i < sizeof(aliases); i++) {
            line = aliases[i];
            rules += ( { "   " + line + ": " + wizard_alias[line] });
         }
      }
      return rules;
   }

   if (type == "" || type == "player") {
      if (player_alias[str]) {
         done = 1;
         rules += ( { "Алиасы игрока: " + str + " : " + player_alias[str] } );
      }
   }

   if (type == "" || type == "wizard" || type == "wiz") {
      if (wizard_alias[str]) {
         done = 1;
         rules += ( { "Алиасы билдера: " + str + " : " + wizard_alias[str] } );
      }
   }
   if (!done) {
      rules = ( { "Нет такого алиаса: " + str } );
   }
   return rules;
}
