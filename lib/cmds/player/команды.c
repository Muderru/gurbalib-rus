/* cmds.c */
inherit M_COMMAND;

int col;
string *lines;

string *usage(void) {
   string flags, *lines;

   flags = "игрока|verb";

   if (query_wizard(this_player())) {
      flags += "|wiz";
   }
   if (query_admin(this_player())) {
      flags += "|admin";
   }

   lines = ({ "Использование: команды [-h] [-v] [" + flags + "]" });
   lines += ({ "" });
   lines += ({ "Команда 'команды' выводит список всех доступных вам команд." });
   lines += ({ "Если вы выберете подсекцию команд игрока, то покажутся команды " +
      "доступные только игроку, " });
   lines += ({ "вместо всех доступных вам команд." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-e\tВключая эмоции." });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\t-v\tВертикальный режим, показывает команды по одной в линии." });
   lines += ({ "Примеры:" });
   lines += ({ "\tкоманды" });
   lines += ({ "\tкоманды игрока" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "help");

   add_also("wiz", "man");
}

static void show_cmds(string dir) {
   string *names, *files;
   mapping cmds;
   int c, d, sz, i;

   cmds = ([]);
   files = get_dir(dir + "/*.c")[0];
   for (i = sizeof(files) - 1; i >= 0; i--) {
      cmds[files[i][..strlen(files[i]) - 3]] = dir;
   }

   names = map_indices(cmds);

   lines += ( { "Команды: " + dir } );

   for (d = 0, sz = sizeof(names); d < sz; d += col) {
      int colnum;
      string line, tmp;

      line = "";

      for (colnum = 0; colnum < col; colnum++) {
         if (d + colnum < sz) {
            if (col == 1) {
               tmp = " (" + cmds[names[d + colnum]] + ")";
            } else {
               tmp = "";
            }

            line += (names[d + colnum] + tmp +
               "                                             " +
               "                         ")[0..(70 / col)];
         }
      }
      lines += ( { line } );
   }

}

static void main(string str) {
   string *path;
   int c, cmax;
   int width;

   width = this_player()->query_width();

   lines = ( { } ); 

   if (!alsos) {
      setup_alsos();
   }

   if (str == "-v") {
      col = 1;
   } else {
      col = 4;
      if (str && (str != "")) {
         switch (str) {
            case "игрока":
               show_cmds("/cmds/player");
               break;
            case "verb":
               show_cmds("/cmds/verb");
               break;
            case "wiz":
            case "wizard":
               if (query_wizard(this_player())) {
                  show_cmds("/sys/cmds/wiz");
               } else {
                  this_player()->more(usage());
               }
               break;
            case "admin":
               if (query_admin(this_player())) {
                  show_cmds("/sys/cmds/admin");
               } else {
                  this_player()->more(usage());
               }
               break;
            case "emote":
            case "эмоции":
               lines += EMOTE_D->show_emote("", width);
               break;
            case "fighter":
            case "fighters":
               show_cmds("/cmds/guild/fighter");
               break;
            default:
               this_player()->more(usage());
               break;
         }
         this_player()->more(lines);
         return;
      }
   }

   path = this_player()->query_path();

   for (c = sizeof(path) - 1; c >= 0; c--) {
      show_cmds(path[c]);
   }

   /* Currently we have none... */
   /* show_cmds("/cmds/verb"); */

   lines += EMOTE_D->show_emote("", width);

   this_player()->more(lines);
}
