/* page.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: паж [-h] КОМАНДА" });
   lines += ({ "Заставляет вашего пажа выполнить указанную команду." });
   lines += ({ "Если нет пажа на месте, то заставляет его появиться." });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "Примеры:" });
   lines += ({ "\tпаж поклониться" });
   lines += ({ "\tпаж вооружиться меч" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
}

static void main(string str) {
   object ob;

   string page;

   if (!alsos) {
      setup_alsos();
   }

   page = "Паж " + this_player()->query_r_name();
   ob = this_player()->query_environment()->present(page);

   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (ob) {
      ob->parse(str);
   } else {
      ob = clone_object(DOMAINS_DIR + "/gurba/guilds/fighter/monsters/page.c");
      if (ob) {
         ob->move(this_player()->query_environment());
         ob->set_master(this_player());
         ob->setup();
         if (this_player()->query_gender() == "male") {
           this_player()->simple_action("$N позвал пажа.");
         } else if (this_player()->query_gender() == "female") {
           this_player()->simple_action("$N позвала пажа.");
         } else {
           this_player()->simple_action("$N позвало пажа.");
         }
      } else {
         if (this_player()->query_gender() == "male") {
           this_player()->simple_action("$N позвал пажа, но он не слышит.");
         } else if (this_player()->query_gender() == "female") {
           this_player()->simple_action("$N позвала пажа, но он не слышит.");
         } else {
           this_player()->simple_action("$N позвало пажа, но он не слышит.");
         }          
      }
   }
}
