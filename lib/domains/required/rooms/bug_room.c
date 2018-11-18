inherit "/std/room";

#define DIR "/domains/required"

void setup(void) {
   add_area("required");

   set_short("Комната багов");
   set_long("Вы видите здесь несколько больших и мягких кресел, так " +
      "как администраторы игры проводят здесь много времени, изучая " +
      "сообщения о багах. ");

   add_item("кресло", "В мягком кресле вы видите отпечаток чей-то " +
      "огромной задницы.");
   add_item("кресла", "Они очень дорогие и удобные, так и хочется " +
      "в них присесть.");

   set_objects(DIR + "/objects/bug_board");

   set_exits(([
      "выход" : STARTING_ROOM, 
   ]));
}
