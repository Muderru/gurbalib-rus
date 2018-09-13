/* score.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: счет [-h] [-q] [ИГРОК]" });
   lines += ({ "" });
   lines += ({ "показывает основные характеристики указанного игрока." });
   lines += ({ "Если игрок не указан, по показывает ваши." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tсчет" });
   lines += ({ "\tсчет туор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "hp");
   add_also("player", "inventory");
   add_also("player", "junk");
   add_also("player", "levels");
   add_also("player", "skills");
   add_also("player", "top");

   add_also("wiz", "status");
}

static void main(string str) {
   int mh, h, expr, level, quest, mm, m, me, e, ac, i, mw, w, next_xp;
   mixed *money;
   object obj;
   string age, *l;

   if (!alsos) {
      setup_alsos();
   }

   quest = 0;
   if (str == "-q") {
      str = "";
      quest = 1;
   } else if (sscanf(str, "-q %s", str)) {
      quest = 1;
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (!empty_str(str)) {
      if (query_wizard(this_player())) {
         obj = USER_D->find_player(str);
         if (!obj) {
            write("Не удается найти игрока: " + str + "\n");
            return;
         }
      } else {
         this_player()->more(usage());
         return;
      }
   } else {
      obj = this_player();
   }

   money = obj->query_all_coins();
   mh = obj->query_max_hp();
   h = obj->query_hp();
   mm = obj->query_max_mana();
   m = obj->query_mana();
   me = obj->query_max_end();
   e = obj->query_end();
   expr = obj->query_expr();
   ac = obj->query_defense();
   level = obj->query_level();
   age = obj->query_age();
   w = this_player()->query_internal_weight();
   mw = this_player()->query_internal_max_weight();
   next_xp = level * level * 2000;

   l = ({ "[ " + obj->query_name() + " ] " + obj->query_title() });
   l += ({ "A " + obj->query_gender() + " " + obj->query_race() +
      " who is " + obj->query_status() + "\n" });
   l += ({ "Сила        :  " + obj->query_stat("str") +
      "\t\t" + "Очки жизни :   " + h + "/" + mh + "  (" +
      percentage(h, mh) + "%)" });
   l += ({ "Интеллект   :  " + obj->query_stat("int") +
      "\t\t" + "Мана       :   " + m + "/" + mm + "  (" +
      percentage(m, mm) + "%)" });
   l += ({ "Мудрость    :  " + obj->query_stat("wis") +
      "\t\t" + "Выносливость : " + e + "/" + me  + "  (" +
      percentage(e, me) + "%)" });
   l += ({ "Ловкость    :  " + obj->query_stat("dex") +
      "\t\t" + "Класс брони  : " + ac });
   l += ({ "Телосложение:  " + obj->query_stat("con") +
      "\t\t" + "Уровень      : " + level });
   l += ({ "Харизма     :  " + obj->query_stat("cha") +
      "\t\t" + "Опыт    :      " + add_comma("" + expr) + "  (" +
      percentage(expr, next_xp) + "%)" });
   l += ({ "Прогресс    :  " + w + "/" + mw + " (" +
      percentage(w, mw) + "%)\tОпыт до уровня:" +
      add_comma("" + (next_xp - expr)) + "\n"
      });

   l += ({ "Убийства: " + add_comma("" + obj->query_kills()) + "  " +
      "Убит : " + add_comma("" + obj->query_killed()) + "\n" });

   l += ({ "Возраст:" + age + "\t" + "Деньги:" });

   for (i = 0; i < sizeof(money); i++) {
      l += ({ "\t\t\t\t" + capitalize(money[i][0]) + ": " +
         add_comma("" + money[i][1]) });
   }

   if (quest) {
      string *quests;
      int j, k;

      l += ({ "Заданий выполнено:" });
      quests = this_player()->query_quests_completed();
      if (quests) {
         k = sizeof(quests);
         for (j = 0; j < k; j++) {
            l += ({ "\t" + quests[j] });
         }
      }
   }
   this_player()->more(l);

   return;
}
