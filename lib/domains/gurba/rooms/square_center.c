#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("Gurba");
   add_area("GurbaSquare");
   add_area("GurbaOutdoor");

   set_short("Центральная площадь города Гурба");
   set_long("Центральная площадь Гурбы специально приспособлена " +
      "для больших собраний людей. Особенно многолюдно здесь во " +
      "время казней. Специально для этого в центре площади установлен " +
      "помост, на котором видны пятна засохшей крови. Также тут " +
      "установлена большая статуя основателя города. А рядом с " +
      "ней висит выглядящий древним колокол.");

   set_exits(([
      "север" : DIR + "/rooms/square_north",
      "юг" : DIR + "/rooms/square_south",
      "восток" : DIR + "/rooms/square_east",
      "запад" : DIR + "/rooms/square_west",
      "северо-восток" : DIR + "/rooms/square_northeast",
      "северо-запад" : DIR + "/rooms/square_northwest",
      "юго-восток" : DIR + "/rooms/square_southeast",
      "юго-запад" : DIR + "/rooms/square_southwest",
   ]));

   add_item("статуя", "Вы видите искусную статую дворфа, высотой " +
      "в полтора раза выше человеческого роста. Статуя украшена " +
      "драгоценными камнями, а у ее основания есть табличка.");
   add_item("драгоценные камни", "драгоценности", "При ближайшем " +
      "рассмотрении они оказываются дешевой подделкой из цветного стекла.");
   add_item("табличка", "На табличке написано: \"Фадж, где ты сейчас?\"");
   add_item("колокол", "Этот бронзовый колокол выглядит очень старым. " +
      "Кажется в него можно позвонить.");

   add_action("do_ring", "позвонить");
}

int do_ring(string arg) {
   if (arg == "колокол" || arg == "в колокол") {
      write("Вы звоните в колокол. Глухой, тревожный звон раздается по площади.");
      this_environment()->tell_room(this_player(), 
            this_player()->query_Name( ) + " звонит в колокол. Глухой, " +
         "тревожный звон раздается по площади.");
      return 1;
   } else {
      return 0;
   }
}
