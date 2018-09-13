/* skills.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: умения [-h] [все]" });
   if (query_wizard(this_player())) {
      lines += ({ "Использование: умения [set SKILL VALUE]" });
   }
   lines += ({ "" });
   lines += ({ "Выводит список ваших умений и как хорошо вы ими владеете." });
   lines += ({ "Администраторы также могут этой командой задавать значения " +
      "выбранным умениям." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\tвсе\tПоказывает все умения, доступные в игре." });
   lines += ({ "Примеры:" });
   lines += ({ "\tумения" });
   lines += ({ "\tумения все" });
   if (query_wizard(this_player())) {
      lines += ({ "\tумения set spell/cure 5" });
   }

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "hp");
   add_also("player", "inventory");
   add_also("player", "junk");
   add_also("player", "levels");
   add_also("player", "score");
   add_also("player", "top");

   add_also("wiz", "status");
}

/*
 * An 'advanced' skill command, by Fudge, Sorressean and Aidil
 */

private void show_skills(string * skills) {
   string line, *lines;
   int i, maxi;

   if (sizeof(skills) == 0) {
      write("Вы ничего не умеете.");
      return;
   }

   lines = ({ });
   maxi = sizeof(skills);
   for (i = 0; i < maxi; i++) {
      line = skills[i] + "                                     ";
      line = line[0..30] + ": " + this_player()->query_skill(skills[i]);
      lines += ({ line });
   }
   this_player()->more(lines);
}

static int filter_skill(string skill, string str) {
   return sscanf(skill, str + "%*s") != 0;
}

static int set_skill(string skill, int value) {
   if (SKILL_D->is_skill(skill)) {
      this_player()->set_skill(skill, value);
      write("Умение: " + skill + ", установлено в: " + value + "\n");
      return 1;
   } else {
      write("Ошибка: " + skill + " в настоящий момент не является действительным.\n");
   }
   return 0;
}

static void main(string str) {
   string skill, *skills;
   int i, value;

   if (!alsos) {
      setup_alsos();
   }

   /*
    * Check to see if the player wants to see all skills in game
    * If so, we just populate the skills list with the game skills 
    * rather than player skills and show it as normal.
    */

   if (empty_str(str)) {
      skills = this_player()->query_skills();
   } else if (str == "все") {
      skills = SKILL_D->query_skills();

      /* empty our input string, else the remainder of this function will 
       * try to use it as a filter */
      str = "";

   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   } else if (sscanf(str, "set %s %d", skill, value) == 2) {
      if (query_wizard(this_player())) {
         set_skill(skill, value);
         return;
      } else {
         this_player()->more(usage());
         return;
      }
   } else if (sscanf(str, "все %s", str) == 0) {
      /* Filtered list of skills of this_player() */
      skills = this_player()->query_skills();
   } else {
      /* Filtered list of all game skills */
      skills = SKILL_D->query_skills();
   }

   if (!empty_str(str)) {
      /* write("Using " + str + " to filter skills."); */
      skills = filter_array(skills, "filter_skill", this_object(), str);
   }

   show_skills(skills);
}
