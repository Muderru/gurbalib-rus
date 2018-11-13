#include "../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("Магазин");
   set_long("Вы зашли в небольшой магазинчик. На прилавках лежат " +
      "видавшие виды товары и муляжи из папье-маше. Над дверью весит " +
      "колокольчик, дребезжащий при каждом открытии двери, то есть " +
      "практически постоянно. На севере и западе расположены служебные " +
      "помещения, а на юге выход отсюда.");

   add_exit("север", DIR + "/rooms/store.c");
   add_exit("юг", DIR + "/rooms/vill_road2.c");
   add_exit("запад", DIR + "/rooms/storage.c");

  set_objects(
      DIR + "/monsters/shopkeep.c",
      "/domains/required/objects/mer_sign.c",
      DIR + "/obj/field.c"
   );
}
