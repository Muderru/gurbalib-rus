/* passwd.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   if (query_admin(this_player())) {
      lines = ({ "Использование: пароль [-h] [ИГРОК ПАРОЛЬ]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам сменить ваш пароль или пароль" });
   lines += ({ " указанного игрока." });
   } else {
      lines = ({ "Использование: пароль [-h]" });
   lines += ({ "" });
   lines += ({ "Позволяет вам сменить ваш пароль." });
   }
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпароль" });

   if (query_admin(this_player())) {
      lines += ({ "\tпароль туор bingo" });
   }

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "alias");
   add_also("player", "ansi");
   add_also("player", "clear");
   add_also("player", "describe");
   add_also("player", "ignore");

   add_also("admin", "coloradm");
}

static void main(string arg) {
   string who, passwd;

   if (!alsos) {
      setup_alsos();
   }

   if (arg && (arg != "")) {
      if (!query_admin(this_player())) {
         this_player()->more(usage());
         return;
      }
      if (sscanf(arg, "%s %s", who, passwd) == 2) {
         if (USER_D->player_exists(who) > 0) {
            if (USER_D->reset_password(who, passwd)) {
               write("Пароль для игрока: " + who + ", изменен на : " + 
                  passwd + "\n");
            }
         } else {
            write(who + " такого игрока не существует.\n");
         }
      } else {
         this_player()->more(usage());
      }
      return;
   }

   if (query_guest(this_player())) {
      write("Гостевой аккаунт не имеет пароля.\n");
   } else {
      call_other(this_user(), "change_passwd", "");
   }
}
