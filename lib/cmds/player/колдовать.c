/* cast.c */
inherit M_COMMAND;

#define SPELL_DIR "/cmds/spells"

string find_spell(string spellname);

string *usage(string str) {
   object target;
   string spellpath, *lines;

   if (str != "") {
      spellpath = find_spell(str);
      if (spellpath) {
         call_other(spellpath, "setup_alsos");
         return call_other(spellpath, "usage");
      }
   }

   lines = ({ "Использование: колдовать [-h] [spell [target]]" });
   lines += ({ "" });
   lines += ({ "позволяет вам колдовать заклинания.  Если вы не укажете заклинания, " +
      " выведет вам список " });
   lines += ({ "доступных заклинаний." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tколдовать снаряд крыса" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "eat");
   add_also("player", "enter");
   add_also("player", "follow");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "query");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

static int has_spell(string spellname) {
   string skill;

   if (query_admin(this_player()) || query_wizard(this_player())) {
      return 1;
   }
   if (this_player()->query_skill("spell/" + spellname)) {
      return 1;
   }
   return 0;
}

static void list_spells(void) {
   string *files;
   int i, x;
   string name;

   files = get_dir(SPELL_DIR + "/*.c")[0];

   write("Доступные заклинания:\n");
   for (i = sizeof(files) - 1; i >= 0; i--) {
      x = strlen(files[i]) - 3;
      name = files[i][..x];
      if (has_spell(name)) {
         write("\t" + name + "\n");
      }
   }
}

static string find_spell(string spellname) {
   string str;

   str = SPELL_DIR + "/" + spellname;
   if (file_exists(str + ".c")) {
      return str;
   }
   return nil;
}

static void cast_spell(string spell, string who) {
   string spellpath;
   object target;

   spellpath = find_spell(spell);

   if (!spellpath || !has_spell(spell)) {
      write("Вы не знаете заклинания: " + spell + "\n");
      list_spells();
      return;
   }
   call_other(spellpath, "do_spell", this_player(), who);
}

static void main(string str) {
   string spellname, who;

   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      list_spells();
      return;
   }

   if (sscanf(str, "-h %s", str)) {
      this_player()->more(usage(str));
      return;
   } else if (sscanf(str, "-%s", str)) {
      this_player()->more(usage(""));
      return;
   }

   if (this_player()->is_dead()) {
      write("Вы не можете сделать этого, пребывая в мире мертвых.\n");
      return;
   }

   if (sscanf(str, "%s %s", spellname, who) != 2) {
      cast_spell(str, nil);
   } else {
      cast_spell(spellname, who);
   }
}
