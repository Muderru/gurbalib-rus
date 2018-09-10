/* group.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: группа [-h] [PCOMMAND ИГРОК] [GCOMMAND]" });
   lines += ({ "" });
   lines += ({ "Позволяет создать вам группу и работать в команде." });
   lines += ({ "" });
   lines += ({ "Допустимые GCOMMANDS: " });
   lines += ({ "\tпринять       Принимает предложение вступить в группу." });
   lines += ({ "\tхп            Сортирует группу по хп/мана/усталость" });
   lines += ({ "\tпокинуть      Покинуть группу." });
   lines += ({ "\tстатус        Выводит информацию о группе." });
   lines += ({ "\tсказать msg   Отправляет сообщение MSG каждому члену группы." });
   lines += ({ "\tразделить     Разделить добычу между членами группы, " +
      "они должны быть рядом." });
   lines += ({ "" });
   lines += ({ "Допустимые PCOMMANDS: " });
   lines += ({ "\tвступить (PLAYER)   Отправляет предложение вступить в группу." });
   lines += ({ "\tлидер (PLAYER)      Передать лидерство другому " +
      "игроку." });
   lines += ({ "\tимя NAME            Дает название вашей группе." });
   lines += ({ "\tудалить (PLAYER)    Удаляет игрока из группы." });

   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tгруппа имя Налетчики" });
   lines += ({ "\tгруппа принять туор" });
   lines += ({ "\tгруппа хп" });
   lines += ({ "\tгруппа сказать бейте стражника." });
   lines += ({ "\tгруппа разделить" });
  
   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "cmds");
}

string *get_group_members() {
}

string get_group_name() {
}

int get_group_exp() {
   return 0;
}

int get_group_gold() {
   return 0;
}

/* XXX Lots of work left */

int do_group_hp() {
   string name, *members, *lines;
   int x, maxx, hp, mana, end, maxhp, maxmana, maxend;
   object obj;

   members = get_group_members();
   maxx = sizeof(members);

   lines = ({ "Группа: " + get_group_name() + "\n" });
   lines += ({ "-----------------------------------" });

   for (x = 0; x < maxx; x++ ) {
      obj = USER_D->find_player(members[x]);
      if (obj) {
         name = uppercase(members[x]);

         if (obj->is_group_leader()) {
            name += "*";
         }

         hp = obj->query_hp();
         maxhp = obj->query_max_hp();
         mana = obj->query_mana();
         maxmana = obj->query_max_mana();
         end = obj->query_end();
         maxend = obj->query_max_end();

         lines += ({ name + "\tХП: " + hp + "/" + maxhp +
            "\tМАНА: " + mana + "/" + maxmana + 
            "\tУСТ: " + end + "/" + maxend + "\n" });
      }
   }
   this_player()->more(lines);
}

int do_group_accept() {
}

int do_group_leave() {
}

int is_leader(object player) {
}

int do_group_status() {
   string *lines, *members;
   int x, maxx;

   members = get_group_members();
   maxx = sizeof(members);

   lines = ({ "Группа: " + get_group_name() + "\n" });
   lines += ({ "Группа ОПЫТ: " + get_group_exp() + "\n" });
   lines += ({ "Группа ДЕНЬГИ: " + get_group_gold() + "\n" });

   lines += ({ "Члены:\n" });
   maxx = sizeof(members);

   for (x = 0; x < maxx; x++) {
      lines += ({ "\t" + members[x] + "\n" });
   }

   this_player()->more(lines);
}

int do_group_split() {
   if (is_leader(this_player())) {
   } else {
      write("Вы не лидер группы и не можете разделить добычу.\n");
   }
}

int do_group_invite(string who) {
}

int do_group_leader(string who) {
   if (is_leader(this_player())) {
   } else {
      write("Вы не лидер группы и не можете изменить лидера.\n");
   }
}

int do_group_name(string who) {
   if (is_leader(this_player())) {
   } else {
      write("Вы не лидер группы и не можете изменить ее " +
         "название.\n");
   }
}

int do_group_remove(string who) {
   if (is_leader(this_player())) {
   } else {
      write("Вы не лидер группы и не можете удалять ее членов " +
         "из группы.\n");
   }
}

int do_group_say(string what) {
}

static void main(string arg) {
   string file;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(arg) || (arg == "help")) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(arg, "-%s", arg)) {
      this_player()->more(usage());
      return;
   }

   switch (arg) {
      case "хп":
         do_group_hp();
         break;
      case "покинуть":
         do_group_leave();
         break;
      case "принять":
         do_group_accept();
         break;
      case "статус":
         do_group_status();
         break;
      case "разделить":
         do_group_split();
         break;
      default:
/* Need to handle multi args here... */
         break;
   }

   return;
}
