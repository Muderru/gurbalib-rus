/* missile.c */
inherit M_COMMAND;

#define COST 10

string *usage(void) {
   string *lines;

   lines = ({ "Использование: колдовать снаряд [-h] ЦЕЛЬ" });
   lines += ({ "" });
   lines += ({ "Колдует магический снаряд в ЦЕЛЬ." });
   lines += ({ "Это заклинание требует " + COST + " маны." });
   lines += ({ "Оно наносит 1-5 урона ЦЕЛИ." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tколдовать снаряд кролик" });
   lines += ({ "\tколдовать снаряд туор" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "колдовать");
}

void missile(object thisp, object target) {
   int x;

   x = random(5) + 1;
   thisp->decrease_mana(COST);
   write("Вы выпустили магический снаряд из ваших рук в " +
      target->query_v_name() + ", травмируя на " + x + " очков жизни.\n");
   this_object()->targeted_action("Магический снаряд вылетел из рук " + this_player()->query_r_name() +
      " травмируя " + target->query_v_name() + ".\n");
   target->decrease_hp(x);
   target->attack(this_player());
}

void do_spell(object thisp, string target) {
   object tar;

   if (empty_str(target) || target == "-h") {
      this_player()->more(usage());
      return;
   } else {
      tar = this_environment()->present(target);
   }
   if (tar) {
      if (tar == thisp) {
         write("Вы не можете колдовать магический снаряд на самого себя.\n");
      } else {
         if (this_player()->query_mana() >= COST) {
            missile(thisp, tar);
         } else {
            write("У вас недостаточно маны.\n");
         }
      }
   } else {
      write("На кого вы хотите колдовать магический снаряд?\n");
   }
}

