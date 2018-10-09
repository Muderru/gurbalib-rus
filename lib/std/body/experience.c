int level, experience;

int ready_for_next_level(void) {
   int tmpexp;

   tmpexp = level * level * 2000;

   if (experience > tmpexp) {
      return 1;
   }
   return 0;
}

string query_level_title(int level) {
   switch (level) {
      case 1:
      if (this_player()->query_gender() == "male") {
         return "Непосвященный";
      } else if (this_player()->query_gender() == "female") {
         return "Непосвященная";
      } else {
         return "Непосвященное";
      }
         break;
      case 2:
      if (this_player()->query_gender() == "male") {
         return "Начинающий";
      } else if (this_player()->query_gender() == "female") {
         return "Начинающая";
      } else {
         return "Начинающее";
      }      
         break;
      case 3:
      if (this_player()->query_gender() == "male") {
         return "Начинающий вникать";
      } else if (this_player()->query_gender() == "female") {
         return "Начинающая вникать";
      } else {
         return "Начинающее вникать";
      }      
         break;
      case 4:
      if (this_player()->query_gender() == "male") {
         return "Посредственный";
      } else if (this_player()->query_gender() == "female") {
         return "Посредственная";
      } else {
         return "Посредственное";
      }      
         break;
      case 5:
      if (this_player()->query_gender() == "male") {
         return "Заурядный";
      } else if (this_player()->query_gender() == "female") {
         return "Заурядная";
      } else {
         return "Заурядное";
      }      
         break;
      case 6:
      if (this_player()->query_gender() == "male") {
         return "Сносный";
      } else if (this_player()->query_gender() == "female") {
         return "Сносная";
      } else {
         return "Сносное";
      }      
         break;
      case 7:
      if (this_player()->query_gender() == "male") {
         return "Могучий";
      } else if (this_player()->query_gender() == "female") {
         return "Могучая";
      } else {
         return "Могучее";
      }      
         break;
      case 8:
      if (this_player()->query_gender() == "male") {
         return "Великий";
      } else if (this_player()->query_gender() == "female") {
         return "Великая";
      } else {
         return "Великое";
      }      
         break;
      case 9:
      if (this_player()->query_gender() == "male") {
            return "Барон";
      } else if (this_player()->query_gender() == "female") {
            return "Баронесса";
      } else {
            return "Барон";
      }      
         break;
      case 10:
      if (this_player()->query_gender() == "male") {
         return "Титан";
      } else if (this_player()->query_gender() == "female") {
         return "Титанша";
      } else {
         return "Титан";
      }      
         break;
      case 11:
      if (this_player()->query_gender() == "male") {
         return "Завоеватель";
      } else if (this_player()->query_gender() == "female") {
         return "Завоевательница";
      } else {
         return "Завоеватель";
      }      
         break;
      case 12:
      if (this_player()->query_gender() == "male") {
         return "Герой";
      } else if (this_player()->query_gender() == "female") {
         return "Героиня";
      } else {
         return "Герой";
      }      
         break;
      case 13:      
         return "Пророк";
         break;
      case 14:
         return "Легенда";
         break;
      case 15:
         return "Миф";
         break;
      case 16:
      if (this_player()->query_gender() == "male") {
            return "Великий барон";
      } else if (this_player()->query_gender() == "female") {
            return "Великая баронесса";
      } else {
            return "Великий барон";
      }      
         break;
      case 17:
      if (this_player()->query_gender() == "male") {
         return "Великий титан";
      } else if (this_player()->query_gender() == "female") {
         return "Великая титанша";
      } else {
         return "Великий титан";
      }      
         break;
      case 18:
      if (this_player()->query_gender() == "male") {
         return "Могучий завоеватель";
      } else if (this_player()->query_gender() == "female") {
         return "Могучая завоевательница";
      } else {
         return "Могучий завоеватель";
      }      
         break;
      case 19:
      if (this_player()->query_gender() == "male") {
         return "Легендарный герой";
      } else if (this_player()->query_gender() == "female") {
         return "Легендарная героиня";
      } else {
         return "Легендарный герой";
      }      
         break;
      default:
         return "Архимаг";
         break;
   }
}

void increase_level(void) {
   level += 1;
   this_object()->set_max_hp((level *
      this_object()->query_base_stat("str")) + 20);
   this_object()->set_max_mana((level *
      this_object()->query_base_stat("wis")) + 20);
   this_object()->set_max_end((level *
      this_object()->query_base_stat("con")) + 20);
   write("Поздравляем! Вы достигли " + level + "го уровня.\n");
   this_object()->set_title(query_level_title(level) + " $N.\n");
}

void increase_expr(int expr) {
   if (expr < 0) {
      expr = expr * -1;
   }
   experience += expr;
   if (experience < 0) {
      experience = 0;
   }
   if (ready_for_next_level()) {
      increase_level();
      write("Поздравляем! Вы достигли нового уровня...\n");
      level += 1;
   }
}

void decrease_expr(int expr) {
   if (expr > 0) {
      expr = expr * -1;
   }
   experience -= expr;
   if (experience < 0) {
      experience = 0;
   }
}

void set_expr(int expr) {
   experience = expr;
   if (experience < 0) {
      experience = 0;
   }
}

int query_expr(void) {
   return (experience);
}

int query_level(void) {
   return (level);
}
