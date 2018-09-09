/* An interface to the channel daemon By Fudge */
/* chan.c */
inherit M_COMMAND;

#include <channel.h>

string *usage(void) {
   string *lines;

   lines = ({ "Использование: канал [-h] [cmd COMMAND CHANNEL | CHANNEL MSG]" });
   lines += ({ "" });
   lines += ({ "Команда позволяет вам взаимодействовать с каналами." });
   lines += ({ "Каналы это основной путь общения сообщества игроков. " });
   lines += ({ "Если не указано аргументов у команды, то будет выведен список подключенных каналов." });
   lines += ({ "" });
   lines += ({ "Доступные команды: " });
   lines += ({ "\tвкл\tПрисоединиться к каналу." });
   lines += ({ "\tвыкл\tПокинуть канал." });
   lines += ({ "\tистория\tПоказывает историю сообщений канала." });
   lines += ({ "\tинфо\tПоказывает инфо по каналу." });
   lines += ({ "\tсписок\tПоказывает кто сейчас присутствует на канале." });

   if (query_wizard(this_player())) {
      lines += ({ "\tновый\tСоздает канал." });
      lines += ({ "\tудалить\tУдаляет канал." });
      lines += ({ "\tцвет COL\tИзменяет цвет канала на COL." });
   }

   if (query_admin(this_player())) {
      lines += ({ "\timud CHAN\tПодсоединяет этот канал к intermud каналу CHAN." });
      lines += ({ "\tguild GUILD\tДелает канал специфичным для гильдии GUILD." });
      lines += ({ "\tadmin\tДелает этот канал доступным только для админов." });
      lines += ({ "\twiz\tДелает этот канал доступным только для билдеров (wizard)." });
      lines += ({ "\topen\tДелает этот канал открытым." });
      lines += ({ "\treadonly\tДелает этот канал доступным только для чтения." });
      lines += ({ "\tpermanent\tДелает этот канал закрепленным." });
   }

   lines += ({ "Если сообщение начинается с одного из указанных ниже символов, " });
   lines += ({ "то оно считается эмоцией: ':', '!', ';' " });
   lines += ({ "Если вы хотите, чтобы ваше сообщение начиналось с : используйте :: вместо него." });

   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tканал cmd выкл объявления" });
   lines += ({ "\tканал cmd вкл объявления" });
   lines += ({ "\tканал объявления привет всем!" });
   lines += ({ "\tканал оос :woo" });
   lines += ({ "\tканал оос ::woo" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "bug");
   add_also("player", "emote");
   add_also("player", "rsay");
   add_also("player", "say");
   add_also("player", "shout");
   add_also("player", "tell");
   add_also("player", "whisper");
   add_also("player", "wizcall");

   add_also("wiz", "echoto");
   add_also("wiz", "ssay");
   add_also("wiz", "sysmsg");
   add_also("wiz", "translate");
   add_also("wiz", "wizlog");

   add_also("admin", "wall");
}

static void list_channels(int x) {
   string *channels, *schannels, *lines;
   mapping ichans;
   string line;
   int i, sz;

   channels = CHANNEL_D->query_channels();
   schannels = this_player()->query_channels();

   if (x) {
      lines = ( { "%^BOLD%^%^CYAN%^Ваши подключенные каналы: %^RESET%^" } );
   } else {
      lines = ( { "%^BOLD%^%^CYAN%^Доступные каналы: %^RESET%^" } );
   }

   for (i = 0, sz = sizeof(channels); i < sz; i++) {
      if (member_array(channels[i], schannels) == -1) {
         if (!x) {
            line = channels[i] + "     \t";
            line += "%^RED%^ВЫКЛ%^RESET%^";
            lines += ({ line });
         }
      } else {
         line = channels[i] + "     \t";
         line += "%^GREEN%^ВКЛ%^RESET%^";
         lines += ( { line } );
      }
   }

   if (query_wizard(this_player())) {
      ichans = IMUD_D->query_chanlist();
      channels = map_indices(ichans);

      lines += ( { "" } );
      lines += ( { "IMud каналы" } );
      lines += ( { "--------------" } );
      for (i = 0; i < sizeof(channels); i++) {
         if ((ichans[channels[i]][0]) && (ichans[channels[i]][0] != -1)) {
            lines += ( { channels[i] + ", " + ichans[channels[i]][0] } );
         }
      }
   }

   this_player()->more(lines, 1);
}

static void chan_cmd(string cmd, string chan) {
   string rest, *args;

   switch (cmd) {
      case "присоединиться":
      case "вкл":
         CHANNEL_D->chan_join(chan, this_player());
         break;
      case "покинуть":
      case "выкл":
         CHANNEL_D->chan_leave(chan, this_player());
         break;
      case "новый":
         CHANNEL_D->chan_new(chan, ALL);
         break;
      case "admin":
         CHANNEL_D->chan_set_flag(chan, ADMIN_ONLY);
         write("Канал " + chan + " становится доступным только для админов.\n");
         break;
      case "wiz":
         CHANNEL_D->chan_set_flag(chan, WIZ_ONLY);
         write("Канал " + chan + " становится доступным только для билдеров.\n");
         break;
      case "open":
         CHANNEL_D->chan_set_flag(chan, ALL);
         write("Канал " + chan + " становится открытым.\n");
         break;
      case "readonly":
         CHANNEL_D->chan_set_flag(chan, READ_ONLY);
         write("Канал " + chan + " становится доступным только для чтения.\n");
         break;
      case "permanent":
         CHANNEL_D->chan_make_permanent(chan);
         break;
      case "":
      case "кто":
      case "список":
         CHANNEL_D->chan_who(chan);
         break;
      case "ист":
      case "история":
         CHANNEL_D->show_history(chan);
         break;
      case "удалить":
         CHANNEL_D->chan_delete(chan);
         break;
      case "инфо":
         CHANNEL_D->show_info(chan);
         break;
      case "помощь":
         this_player()->more(usage());
         break;
      case "цвет":
         args = explode(chan, " ");
         if (sizeof(args) < 2) {
            this_player()->more(usage());
            return;
         }
         write("Старый цвет для этого канала " + args[1] + ": " + 
            CHANNEL_D->chan_query_color(args[1]) + "\n");
            CHANNEL_D->chan_set_color(args[1], args[0]);
         write("Новый цвет для этого канала " + args[1] + ": " + 
            CHANNEL_D->chan_query_color(args[1]) + "\n");
         break;
      case "imud":
         args = explode(chan, " ");
         CHANNEL_D->chan_imud(args[1], args[0]);
         write("Канал подсоединен: " + args[0] + " к imud каналу: " +
            args[1] + "\n");
         break;
      case "guild":
         args = explode(chan, " ");
         if (sizeof(args) < 2) {
            this_player()->more(usage());
            return;
         }
         write("Старая гильдия для канала " + args[1] + ": " + 
            CHANNEL_D->chan_query_guild(args[1]) + "\n");
            CHANNEL_D->chan_set_guild(args[1], args[0]);
         break;
      default:
         write("Недоступная команда " + cmd + "\n");
         this_player()->more(usage());
         break;
   }
}

static void main(string str) {
   string chan, cmd, rest;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      list_channels(1);
      return;
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(str, "%s %s", cmd, chan) != 2) {
      this_player()->more(usage());
      return;
   }

   if (cmd == "cmd") {
      if ((chan == "список") || (chan == "кто")) {
         list_channels(0);
         return;
      } else if (sscanf(chan, "%s %s", cmd, rest) < 2) {
         this_player()->more(usage());
         return;
      }
  
      chan_cmd(cmd, rest);
   } else {
      if (sscanf(str, "%s %s", chan, rest) == 2) {
         if ((rest[0] == ';') || (rest[0] == ':') || (rest[0] == '!')) {
            if (rest[1] != rest[0]) {
               CHANNEL_D->chan_emote(chan, rest[1..]);
               return;
            } else {
               rest = rest[1..];
            }
         }
         CHANNEL_D->chan_say(chan, rest);
      } else {
         this_player()->more(usage());
      }
   }
}
