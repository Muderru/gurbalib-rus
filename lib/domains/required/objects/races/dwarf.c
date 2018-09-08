/* Definition of the dwarf race */
inherit "/std/race";

void create(void) {
   ::create();

   base_stat_minimum["str"] = 7;
   base_stat_minimum["con"] = 10;

   stat_mod["str"] = 1;
   stat_mod["con"] = 2;
   stat_mod["dex"] = -1;
   stat_mod["cha"] = -2;

   set_race_short_desc("Дворфы это коренастые и сильные существа, " +
      "но они лишены магического таланта.");
   set_race_long_desc("У дфорфов природная предрасположенность к тяжелому труду. " +
      "Время проведенное в шахтах и кузницах сделало их сильными в выносливыми. " +
      "Эти качества делают из них превосходных воинов. " +
      "Однако большинство дворфов не может понять концепции магии, и дворфы-маги " +
      "вещь диковинная. Также они обладают хорошей сопротивляемостью к магии." +
      "Дворфы хорошо ладят с троллями и орками, " +
      "и разделяют их неприязнь к эльфам. ");

   set_language("dwarven");
   set_skill("language/dwarven", 100);
   set_skill("value", 50);
}

int has_darkvision(void) {
   return 1;
}

