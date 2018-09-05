inherit "/std/room";
#define REQDIR "/domains/required"

private string myname(void) {
   string who;

   who = owner_file(file_name());
   if (!who || who == "") {
      who = "ERROR in owner_file:";
   }
   return capitalize(who);
}

void setup(void) {
   set_short("Мастерская " + this_player()->query_r_name());
   set_long("Эта комната заставлена разными мистическими устройствами.  " +
      "Вы не совсем уверены для чего они нужны, но кажется кто-то очень " +
      "постарался, расставляя их здесь. В центре комнаты стоит большой " +
      "стол, заваленный всякими инструментами.");
   set_exits(([
      "выход" : STARTING_ROOM,
      "восток" : REQDIR + "/rooms/bug_room",
   ]));

   add_item("стол", "Этот огромный стол сделан из великолепного красного дерева. " +
      "Кажется, что " +
      myname() + " любит проводить за ним время.");

   add_item("инструменты", "Они используются " + this_player()->query_t_name() +
      " для всяких разных операций.");

   set_objects(
      REQDIR + "/monsters/rat", 
      REQDIR + "/objects/chest", 
      REQDIR + "/objects/short_sword", 
      REQDIR + "/objects/helmet"
   );
}
