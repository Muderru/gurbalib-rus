inherit "/std/sign";


void setup(void) {
   set_id("список", "топ", "топ игроков", "топ список", "список лучших игроков");
   set_short("Список лучших игроков");
   set_obj_i_name("список");
   set_obj_r_name("списка");
   set_obj_d_name("списку");
   set_obj_v_name("список");
   set_obj_t_name("списком");
   set_obj_p_name("списке");
   set_obj_gender("male");
   set_gettable(1);
   set_value(5);
   set_weight(1);

   set_message("#query_long");
}

string query_long() {
   mixed **top_scores;
   string  name, xp, kills, killed, quests, *lines, stuff;
   int i, dim;

   top_scores = TOP_SCORE_D->get("");
   if (nilp(top_scores)) {
      return "Пока еще никто не набрал очков. " +
         "Пора попытать удачу!";
   }
   dim = sizeof(top_scores);

   lines = allocate(dim + 2);

   lines[0] = "10 лучших игроков:";
   lines[1] = "-------------------------------------------";

   for (i = 0; i < dim; i++) {
      name = top_scores[i][0];
      xp = add_comma("" + top_scores[i][1]);
      kills = add_comma("" + top_scores[i][2]);
      killed = add_comma("" + top_scores[i][3]);
      quests = add_comma("" + top_scores[i][4]);
      lines[i + 2] = name + ": " + xp + ", " + kills + "/" + killed + ", " +
         quests;
   }

   stuff = implode(lines, "\n");

   return stuff;
}

