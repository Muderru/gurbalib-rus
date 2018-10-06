inherit "/std/monster";

int nFollow;
string master_name, master_name_2;
object master;
string my_name;

void set_master(object m) {
   if (m) {
      master = m;
      master_name = m->query_r_name();
      master_name_2 = m->query_Name();
   }
}

void setup(void) {
   if (!master_name || master_name == "") { /* If no master set a default... */
      master_name = "Сирдуда";
   }
   set_name("слуга " + master_name);
   my_name = "Слуга " + master_name;
   set_gender("male");
   set_level(1);
   add_id("раб");
   set_short("Слуга " + capitalize(master_name));
   set_long("Слуга одет в простую робу и его голова всегда склонена " +
      "в смирении.");
   set_r_name("слуги " + master_name);
   set_d_name("слуге " + master_name);
   set_v_name("слугу " + master_name);
   set_t_name("слугой " + master_name);
   set_p_name("слуге " + master_name);   
   set_race("human");
   nFollow = call_out("follow_master", 2);
   respond("bow " + master_name);
}

void follow_master(void) {
   object *objs;
   int i;
   int nMasterHere;

   nMasterHere = 0;
   objs = query_environment()->query_inventory();
   for (i = 0; i < sizeof(objs); i++) {
      if (objs[i] == master) {
         nMasterHere = 1;
      }
   }

   if (nMasterHere == 0) {
      if (!master) {
         remove_call_out(nFollow);
         respond("сказать Кажется, что мастер больше не нуждается в моих услугах.");
         die();
         destruct_object(this_object());
         return;
      }
      if (query_environment() != master->query_environment()) {
         switch (random(10)) {
            case 0:
               query_environment()->tell_room(nil, my_name + " ушел.");
               break;
            case 1:
               query_environment()->tell_room(nil, my_name +
                  " пытается следовать за его мастером.");
               break;
            case 2:
               query_environment()->tell_room(nil,
                  my_name + " следует за его мастером.");
               break;
            case 3:
               query_environment()->tell_room(nil, my_name +
                  " исчез в облаке дыма.");
               break;
            case 4:
               query_environment()->tell_room(nil,
                  my_name + " внезапно испарился.");
               break;
            case 5:
               query_environment()->tell_room(nil,
                  my_name + " скрылся из вида.");
               break;
            case 6:
               query_environment()->tell_room(nil, my_name +
                  " убежал за своим мастером.");
               break;
            case 7:
               query_environment()->tell_room(nil, my_name +
                  " внезапно обнаружил, что его мастер ушел и выбежал из комнаты.");
               break;
            case 8:
               query_environment()->tell_room(nil, my_name +
                  " скрылся в тенях и пропал.");
               break;
            case 9:
               query_environment()->tell_room(nil, my_name +
                  " щелкнул пальцами и скрылся.");
               break;
         }

         move(master->query_environment()->base_name());
         switch (random(10)) {
            case 0:
               query_environment()->tell_room(nil, my_name +
                  " следует за светом его жизни.");
               break;
            case 1:
               query_environment()->tell_room(nil, my_name +
                  " следует за мастером шаг в шаг.");
               break;
            case 2:
               query_environment()->tell_room(nil, my_name +
                  " появился рядом с мастером в облаке дыма.");
               break;
            case 3:
               query_environment()->tell_room(nil, my_name + " вошел.");
               break;
            case 4:
               query_environment()->tell_room(nil, my_name + " появился.");
               break;
            case 5:
               query_environment()->tell_room(nil, my_name +
                  " пришел вскоре после его мастера.");
               break;
            case 6:
               query_environment()->tell_room(nil, my_name +
                  " вбежал, стараясь не отставать от мастера.");
               break;
            case 7:
               query_environment()->tell_room(nil, "Пришел смиренный слуга.");
               break;
            case 8:
               query_environment()->tell_room(nil,
                  "Вошел смиренный человек в робе.");
               break;
            case 9:
               query_environment()->tell_room(nil, my_name +
                  " догоняет своего мастера.");
               break;
         }
      }
   }
   nFollow = call_out("follow_master", 2);
}

void parse(string str) {
   if (str == "уходи" || str == "умри" || str == "уволен") {
      remove_call_out(nFollow);
      respond("сказать Кажется, что мастер больше не нуждается в моих услугах.");
      this_environment()->remove_object(this_object());
      destruct_object(this_object());
   } else {
      respond(str);
   }
}

void outside_message(string str) {
   string pre;

   str = ANSI_D->strip_colors(str);
   str = str[..(strlen(str) - 3)];

   pre = capitalize(master_name_2) + " говорит: Слуга, ";

   if (strstr(str, pre) != -1) {
      parse(str[(strlen(pre))..]);
   }
}
