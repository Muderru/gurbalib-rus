inherit "/std/room";

void setup(void) {
   add_area("required");

   set_short("Огромное поле");
   set_long("Вы стоите в центре огромного поля.  На севере вы видите высокое " +
      "мертвое дерево с каким-то знаком.  Все пространство на востоке занимают " +
      "бескрайние прерии.  На западе вы замечаете древний город Гурба.  На юге же " +
      "раскинулся темный лес.");

   set_exits(([
      "north" : "/domains/newbie/rooms/tree", 
      "south" : "/domains/2.4.5/rooms/forest1", 
      "east" : "/domains/boothill/rooms/outside_town",
      "west" : "/domains/gurba/rooms/gate_east",
   ]));
}
