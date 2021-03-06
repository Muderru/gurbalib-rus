#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Берег Лунного озера");
   set_long("Вы стоите на берегу мертвого озера с тухлой вонючей водой. " +
      "В нем нет ни лягушек, ни рыбы, лишь их вздувшиеся останки плавают " +
      "в волнах. Отсюда в мрачный лес на север ведет узкая тропинка, " +
      "тогда как линия берега продолжается на северо-запад и северо-восток. " +
      "На юго-востоке вы видите остатки каменного моста, который вел на " +
      "Остров магов, но сейчас он рухнул в озеро и пройти по нему уже " +
      "не получится.");

   add_exit("север", DIR + "/rooms/south/sforst46.c");
   add_exit("северо-восток", DIR + "/rooms/south/sshore27.c");
   add_exit("северо-запад", DIR + "/rooms/south/sshore25.c");
   add_exit("юго-восток", "#go_southeast");
}

string query_long() {
   string str;

   str = "Вы стоите на берегу мертвого озера с тухлой вонючей водой. " +
      "В нем нет ни лягушек, ни рыбы, лишь их вздувшиеся останки плавают " +
      "в волнах. Отсюда в мрачный лес на север ведет узкая тропинка, " +
      "тогда как линия берега продолжается на северо-запад и северо-восток. " +
      "На юго-востоке вы видите остатки каменного моста, который вел на " +
      "Остров магов, но сейчас он рухнул в озеро и пройти по нему уже " +
      "не получится.";

   if (this_player()->query_level() > 15) {
      str += " Однако над вы замечаете над остатками моста радужное " +
         "сияние, по которому кажется можно пройти.";
   }
   return str;
}

int go_southeast() {
   string usermsg, othermsg;

   if (this_player()->query_level() <= 15) {
      write("Мост на остров магов разрушен, пройти по нему сейчас " +
         "невозможно.");
      return 1;
   }
   add_exit("юго-восток", DIR + "/rooms/south/sislnd1.c");
   usermsg = "Собрав волю в кулак, вы ступаете на призрачный мост " +
      "и начинаете идти в направлении Острова магов.";
   othermsg =  this_player()->query_Name() + " идет по призрачному " +
      "мосту.";

   /* XXX domove(DIR + "/rooms/south/sislnd1.c", usermsg, othermsg); */
   return 1;
}
