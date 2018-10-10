/* cure.c */
inherit M_COMMAND;

#define COST 10
#define SKILLREQUIRED 15

string *usage(void) {
   string *lines;

   lines = ({ "Использование: колдовать лечение [-h] [ЦЕЛЬ]" });
   lines += ({ "" });
   lines += ({ "Вызывает заклинание лечения легких ран на ЦЕЛЬ." });
   lines += ({ "Если цель не указана, то на себя." });
   lines += ({ "Это заклинание требует " + COST + " маны." });
   lines += ({ "Оно лечит 1-5 очков жизни ЦЕЛИ." });
   lines += ({ "Для произнесения заклинания требуется умение прокачанное до " + 
      SKILLREQUIRED + ", прежде чем вы сможете лечить " });
   lines += ({ "других игроков." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tколдовать лечение" });
   lines += ({ "\tколдовать лечение туор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "колдовать");
}

int max_hp(object target) {
   if (target->query_hp() >= target->query_max_hp()) {
      return 1;
   }
   return 0;
}

void cure(object thisp, object target) {
   int x;

   x = random(5) + 1;
   thisp->decrease_mana(COST);

   if (max_hp(target) || target->is_dead()) {
      write("Ваше заклинание не возымело эффекта.\n");
      this_object()->targeted_action("Мягкое сияние окутало " + target->query_v_name() +
         ", но затем быстро исчезло.\n");
      return;
   }

   if (thisp == target) {
      if (this_player()->query_gender() == "female") {
      this_object()->targeted_action("Мягкое сияние окутало " + target->query_v_name() +
         " и облегчило ее страдания.\n");
      } else {
      this_object()->targeted_action("Мягкое сияние окутало " + target->query_v_name() +
         " и облегчило его страдания.\n");
      }
      write("Вы сконцентрировались и вылечили себя на " + x + " очков жизни.\n");
   } else {
      if (this_player()->query_gender() == "female") {
      write("Вы приложили руки на раны " + target->query_r_name() +
         " излечивая ее на " + x + " очков жизни.\n");
      this_object()->targeted_action("Мягкое сияние окутало " +
         target->query_v_name() + " облегчая ее страдания.\n");
      } else {
      write("Вы приложили руки на раны " + target->query_r_name() +
         " излечивая его на " + x + " очков жизни.\n");
      this_object()->targeted_action("Мягкое сияние окутало " +
         target->query_v_name() + " облегчая его страдания.\n");
      }
   }
   target->increase_hp(x);
}

void do_spell(object thisp, string target) {
   object tar;

   if (empty_str(target)) {
      tar = thisp;
   } else if (target == "-h") {
      this_player()->more(usage());
      return;
   } else {
      tar = this_environment()->present(target);
   }
   if (thisp->query_mana() < COST) {
      write("Недостаточно маны.\n");
   } else {
      if (tar) {
         if (tar == thisp) {
            cure(thisp, tar);
         } else if (thisp->query_skill("spell/cure") >= SKILLREQUIRED) {
            cure(thisp, tar);
         } else {
            write("Вы недостаточно хорошо овладели этим заклинанием, чтобы колдовать его на других.\n");
         }
      } else {
         write("На кого вы хотите колдовать лечение?\n");
      }
   }
}

