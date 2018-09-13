/* rsay.c */
inherit M_COMMAND;

string *usage(void) {
   int x, max;
   string *langs, *lines;

   lines = ({ "Использование: произнести [-h] [ЯЗЫК] MSG" });
   lines += ({ "" });
   lines += ({ "Сказать в текущей комнате сообщение MSG на указанном языке." });
   lines += ({ "Если язык LANGUAGE не указан, то используется ваш расовый." });
   lines += ({ "Доступные ЯЗЫКИ: " });

   langs = LANGUAGE_D->query_languages();
   max = sizeof(langs);
   for (x = 0; x < max; x++) {
      lines += ({ "\t" + langs[x] });
   }

   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпроизнести catfolk Привет, никто не хочет погладить киску?" });
   lines += ({ "\tпроизнести Можете прочитать это?" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "bug");
   add_also("player", "chan");
   add_also("player", "emote");
   add_also("player", "say");
   add_also("player", "shout");
   add_also("player", "tell");
   add_also("player", "whisper");
   add_also("player", "wizcall");

   add_also("wiz", "echo");
   add_also("wiz", "echoto");
   add_also("wiz", "ssay");
   add_also("wiz", "sysmsg");
   add_also("wiz", "translate");
   add_also("wiz", "wizlog");

   add_also("admin", "wall");
}

static void tell_them(string str, string *words, string lang, string *words2) {
   object *usr;
   int i, imax, k, kmax, x;
   string tmp;

   usr = USER_D->query_players();
   imax = sizeof(usr);
   for (i = 0; i < imax; i++) {
      if (usr[i] == this_player()) {
         write("Вы говорите на языке " + lang + ": " + str + "\n");
      } else {
         tmp = "";
         kmax = sizeof(words);
         for (k = 0; k < imax; k++) {
             x = random(100) + 1;
             if ((usr[i]->query_language() == lang) || 
                query_wizard(usr[i]) ||
                (x < usr[i]->query_skill("language/" + lang))) {
                tmp = tmp + words[k] + " ";
             } else {
                tmp = tmp + words2[k] + " ";
             }
         }

         usr[i]->message(this_player()->query_Name() + 
            " говорит на языке " + lang + ": " + tmp + "\n");
      }
   }
}

void garble_tell(string str, string lang, string *words, string *words2) {
   int k, kmax, x;

   kmax = sizeof(words);
   for (k = 0; k < kmax; k++) {
      x = random(100) + 1;
      if (x < this_player()->query_skill("language/" + lang)) {
         words2 += ({ LANGUAGE_D->english_to_racial(lang, words[k]) });
      } else {
         /*Mess up the word... */
         words2 += ({ LANGUAGE_D->random_word(lang) });
         words = words2;
      }
   }

   tell_them(str, words, lang, words2);
}

static void main(string str) {
   int i, k, x, kmax;
   string *words, *words2;
   string rest, first, lang;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      this_player()->more(usage());
      return;
   }
   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   lang = "";
   words2 = ({ });

   if (sscanf(str, "%s %s", first, rest) == 2) {
      if (LANGUAGE_D->valid_language(first)) {
         lang = first;
         str = rest;
      }
   }

   if (lang == "") {
      lang = this_player()->query_language();
      if (!LANGUAGE_D->valid_language(lang)) {
         lang = "";
      }
   }
   if (lang == "") {
      this_player()->query_environment()->tell_room(this_player(),
         this_player()->query_Name() + " издает неописуемые звуки.\n");
      write("Вы говорите: " + str + "\n");
      return;
   }

   for (i = strlen(str) - 1; i > 0; i--) {
      if (str[i] != ' ') {
         break;
      }
      str = str[0..(i - 1)];
   }

   if (str != "") {
      str = lowercase(str);
      words = explode(str, " ");

      if (lang == "english" || lang == "русский") {
         tell_them(str, words, lang, words);
      } else {

         garble_tell(str, lang, words, words2);
      }
   }
}

