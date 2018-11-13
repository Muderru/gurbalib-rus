#include "../domain.h"

inherit "/std/monster";
inherit "/std/modules/m_triggers";

#define INTERVAL 8
static int count;
string *a_str, *na_str;

void setup() {
   set_name("Гарри");
   add_id("надоедливый");
   set_gender("male");
   set_short("Надоедливый Гарри");
   set_long("Очень любопытный молодой человек. Наблюдает за вами не отрываясь.");
   set_r_name("Гарри");
   set_d_name("Гарри");
   set_v_name("Гарри");
   set_t_name("Гарри");
   set_p_name("Гарри");   
   set_race("human");
   set_level(3);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);
   count = 0;

   a_str = ({
      "говорить Не надо драться!",
      "говорить Это больно!",
      "говорить Помогите кто-нибудь!",
      "говорить Почему-бы тебе не обижать слабых в каком-нибудь другом месте?",
      "говорить Нет!",
      "говорить Я не люблю задир!\n",
      "говорить Подонок!\n",
      "говорить Ты - драчун!\n"            
   });

   na_str = ({
      "говорить Чего ты ждешь?",
      "говорить Привет!",
      "говорить Мне не нравится зима.",
      "говорить Мне не нравится снег.",
      "говорить Мне не нравится дождь.",
      "говорить Кто ты?",
      "говорить Почему ты так странно смотришь?",
      "говорить Что ты делаешь здесь?",
      "говорить Прекрасная погода, вы не находите?",
      "smile"
   });
}

void notify(string str) {
   query_environment()->tell_room(this_object(), str);
}

private int check_verb(string str, string verb) {
   return sscanf(str, verb + "%*s") == 1;
}

private int is_harry(string str) {
   return lowercase(str) == "Гарри";
}

/* XXX get harry from vill_road2.c  Needs lots of work... */
private void why_did(string str) {
   string who, what, tmp;

   sscanf(str, "%s %s", who, what);
   if (is_harry(who)) {
      return;
   }
   if (sscanf(what, "продал %*s") == 1) {
      respond("говорить Зачем ты продал " + what);
   }
   if (sscanf(str, "%s пытается убить %s.", who, what) == 2) {
      respond("говорить Почему " + who + " пытается убить " + what + "?");
   }
   if (sscanf(str, "%s покинул игру.", who) == 1) {
      respond("говорить Почему " + who + " вышел из игры?");
   }
   if (sscanf(str, "%s взял %s.\n", who, what) == 2) {
      respond("говорить Почему " + who + " взял " + what + " ?");
   }
   if (sscanf(what, "выбросил %s.", tmp) == 1) {
      respond("говорить Почему " + who + " бросил " + tmp + "?");
   }
}

private void how_does_it_feel(string str) {
   string who, what;
   sscanf(str, "%s %s", who, what);
   if (is_harry(who)) {
      return;
   }
   if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
      respond("говорить How does it feel, being of level " + what + " ?");
   }
}

private void smiles(string str) {
   string who, what;

   sscanf(str, "%s %s", who, what);
   if (is_harry(who)) {
      return;
   }
   if (check_verb(what, "smile") == 1) {
      respond("smile");
   }
}

private void say_hello(string str) {
   string who, what;

   sscanf(str, "%s %s", who, what);
   if (is_harry(who)) {
      return;
   }
   if (check_verb(what, "появился") == 1 || check_verb(what, "пришел") == 1 || check_verb(what, "пришла") == 1 || check_verb(what, "пришло") == 1) {
      respond("говорить Привет, " + who + ", рад видеть тебя!");
   }
}

private int contains(string needle, string hay) {
   return sscanf(hay, "%*s" + needle + "%*s") == 2;
}

void handle_say(string str) {
   string a, b, message;

   sscanf(str, "%s %s", a, b);
   if (is_harry(a)) {
      return;
   }
   if (sscanf(str, "%s говорит: %s\n", a, b) != 2) {
      return;
   }

   str = lowercase(b);

   if (contains("привет", str) || contains("здравствуйте", str) ||
      contains("привет всем", str)) {
      message = "говорить Рад видеть вас!";
   }
   if (contains("заткнись", str)) {
      message = "говорить Почему ты хочешь, чтобы я замолчал?";
   }
   if (contains("стой здесь", str) || contains("не следуй", str) ||
      contains("отстань", str)) {
      message = "говорить Хорошо.";
   }
   if (!message) {
      message = "говорить Зачем ты говоришь '" + str + "'???";
   }
   respond(message);
}

private void follow(string str) {
   string who, where;

   if (sscanf(str, "%s ушел на %s.\n", who, where) == 2) {
      if (!is_harry(who)) {
         respond("идти " + where);
      }
   }
}

private void gives(string str) {
   string who, what;
   int rand;
   object obj, next_obj, who_obj;

   if (sscanf(str, "%s дал %s гарри.", who, what) != 2) {
      return;
   }

   if ((what == "firebreather" || what == "специальное" ||
         what == "пиво" || what == "бутылка") && this_object()->present(what)) {
      rand = random(4);

      if (rand == 0) {
         if (random(10) > 6) {
            respond("sigh");
            respond("говорить Мне кажется, ты пытаешься убить меня.");
            respond("бросить все");
            respond("идти запад");
         }
      }
      if (rand == 1) {
         respond("пить " + what);
      }
      if (rand == 2) {
         respond("бросить " + what);
      }
      if (rand == 3) {
         obj = this_object()->present(what);
         if (obj) {
            respond("дать " + what + " " + who);
         }
      }
   } else if (what == "труп") {
      respond("говорить Эй, таскай свой трупы сам, задница осла.");
      obj = this_object()->present(what);
      if (obj) {
         respond("дать труп " + who);
      }
   } else {
      if (this_object()->present(what)) {
         who_obj = this_object()->query_environment()->present(who);
         /* XXX sir, ma'am, creature... */
         respond("говорить Большое вам спасибо.");
      }
   }
}

/* XXX implement this. */
void monster_died() {
}

int down() {
   call_other(this_player(), "move_player", DIR + "/rooms/station");
   return 1;
}

void do_extra_actions() {
   count++;

   if (count >= INTERVAL) {
      if (is_fighting()) {
         respond(a_str[random(sizeof(a_str))]);
      } else {
         respond(na_str[random(sizeof(na_str))]);
      }
      count = 0;
   }
}

void outside_message(string str) {
   /* XXX some from these can be spoofed with player emotes... */
   if (is_fighting()) {
      return;
   }

   str = ANSI_D->strip_colors(str);
   smiles(str);
   say_hello(str);
   why_did(str);
   follow(str);
   gives(str);
   handle_say(str);
}
