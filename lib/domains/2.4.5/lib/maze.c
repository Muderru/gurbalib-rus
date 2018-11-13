/* XXX Need to redo movement so it works more like this...
   in newbie and in normal movement...  Right now this is wrong though... */

void goto_the(string location, string dir) {
   object room;
   string error;
     
   event("body_leave", this_player());
   if (this_player()->query_gender() == "male") {
      this_player()->query_environment()->tell_room(this_player(), 
        this_player()->query_Name() + " ушел на " + dir + ".\n");
   } else if (this_player()->query_gender() == "female") {
      this_player()->query_environment()->tell_room(this_player(), 
        this_player()->query_Name() + " ушла на " + dir + ".\n");
   } else {
      this_player()->query_environment()->tell_room(this_player(), 
        this_player()->query_Name() + " ушло на " + dir + ".\n");
   }

   error = catch(this_player()->move(location));

   /* Need to do last exit stuff XXX */

   if (error) {
      if (query_wizard(this_player()) == 1) {
         write("\nПрипятствие не дает вам пройти.\n" + "Ошибка: " + error + "\n");
         return;
      } else {
         write ("\nПрипятствие не дает вам пройти.\n");
      }
   }

   call_other(this_player(), "do_look", this_environment());

   room = this_player()->query_environment();
   room->event("body_enter", this_player());
   if (this_player()->query_gender() == "male") {
       room->tell_room(this_player(), this_player()->query_Name()  + " пришел.\n");
   } else if (this_player()->query_gender() == "female") {
       room->tell_room(this_player(), this_player()->query_Name()  + " пришла.\n");
   } else {
       room->tell_room(this_player(), this_player()->query_Name()  + " пришло.\n");
   }   

}
