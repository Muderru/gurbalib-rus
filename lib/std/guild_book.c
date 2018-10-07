inherit "/std/object";
inherit "/std/modules/m_readable";

string guild;

void set_guild(string new_guild) {
   guild = new_guild;
}

string query_guild(void) {
   return guild;
}

void do_dub(object who) {
   who->set_title("$N новобранец.");
}

void join_guild(string str) {
   object player;

   player = this_player();

   if (player->guild_member(query_guild())) {
      write("Мастер гильдии говорит: Ты уже член гильдии.");
      return;
   }

   if (this_object()->can_join(player)) {
      player->join_guild(query_guild());
      this_object()->do_join(player);
   } else {
      this_object()->do_reject(player);
      return;
   }

   do_dub(player);

   if (CHANNEL_D->query_channel(query_guild())) {
      CHANNEL_D->chan_join(query_guild(), player);
      CHANNEL_D->event_player_join(( {
         player->query_name(), GUILD_D->query_guild_title(query_guild())
      }));
   }
}

void leave_guild(string str) {
   object player;

   player = this_player();

   if (!player->guild_member(query_guild())) {
      write("Мастер гильдии говорит: Почему ты хочешь покинуть гильдию, " +
         "хотя ты в ней не состоишь?");
      return;
   }

   if (this_object()->can_leave(player)) {

      player->leave_guild(query_guild());
      this_object()->do_leave(player);

      if (CHANNEL_D->query_channel(query_guild())) {
         CHANNEL_D->chan_leave(query_guild(), player);
      }

      player->set_title("$N безгильдийный.");

   } else {
      this_object()->do_keep(player);
   }
}
