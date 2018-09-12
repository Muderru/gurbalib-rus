/* query.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: оценить [-h] [ОБЪЕКТ]" });
   lines += ({ "" });
   lines += ({ "Оценивает объект по сравнению с вами." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tоценить крыса" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "attack");
   add_also("player", "cast");
   add_also("player", "eat");
   add_also("player", "enter");
   add_also("player", "follow");
   add_also("player", "go");
   add_also("player", "pray");
   add_also("player", "quit");
   add_also("player", "wimpy");
}

static void main(string str) {
   object obj;
   float x, y;
   string name;

   if (!alsos) {
      setup_alsos();
   }

   if (!str && (str != "")) {
      this_player()->more(usage());
      return;
   }

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (this_player()->is_dead()) {
      write("Вы не можете сделать этого, пребывая в мире мертвых.\n");
      return;
   }

   obj = this_player()->query_environment()->present(lowercase(str));
   if (!obj) {
      write("Оценить что?\n");
      return;
   }

   if (!obj->is_living() || obj->is_dead()) {
      write("Вы не можете оценить это.\n");
      return;
   }

   if (obj == this_player()) {
      write("Вы пришли в смятение.\n");
      return;
   }

   name = obj->query_v_name();
   write("Вы долго и пристально вглядываетесь в " + name + "\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " оценивает " + name + ".\n");

   y = (float)obj->query_max_hp();
   x = (float)this_player()->query_max_hp();
   write("Уровень угрозы " + obj->query_r_name() + " составляет для вас " + (y / x) + ".\n");
}
