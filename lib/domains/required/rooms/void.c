inherit "/std/room";

void setup(void) {

   add_area("required");

   set_short("Бездна");
   set_long("Бесформенная бездна бурлит вокруг вас, переливаясь всеми цветами радуги.");

   set_exits(([
      "выход" : STARTING_ROOM,
   ]));
}
