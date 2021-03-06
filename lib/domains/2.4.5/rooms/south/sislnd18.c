#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Руины башни Арканартона");
   set_long("Вы стоите в центре руин башни злого мага Арканартона. " +
      "Окружающие следы разрушений говорят о жаркой магической схватке, " +
      "в результате которой башня была разрушена почти до основания. " +
      "Так как никто не видел тело мертвого Арканартона, люди шепчутся, " +
      "что он стал бессмертным личем и до сих пор скрывается где-то на острове. " +
      "Во все стороны отсюда отходят тропки, ведущие к подножию холма, а " +
      "затем и к берегу острова.");

   add_exit("север", DIR + "/rooms/south/sislnd13.c");
   add_exit("юг", DIR + "/rooms/south/sislnd16.c");
   add_exit("восток", DIR + "/rooms/south/sislnd15.c");
   add_exit("запад", DIR + "/rooms/south/sislnd17.c");
}
