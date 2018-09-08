/* Created by Fudge */
inherit "/std/object";

string text, currency;
int amount;

int set_currency(string str) {
   if (MONEY_D->is_currency(str)) {
      currency = str;
      return 1;
   }
   return 0;
}

string query_currency(void) {
   if (!currency) {
      return "дукат";
   }
   return currency;
}

int query_amount(void) {
   return amount;
}

void set_amount(int amt) {
   amount = amt;
   if (amt == 1) {
      set_short("Один " + currency);
      set_long("Один единственный " + currency + " лежит здесь.");
   } else if (amt < 10) {
      set_short("Несколько " + currency + "ов");
      set_long("Несколько " + currency + "ов лежат здесь.");
   } else if (amt < 20) {
      set_short("Немного " + currency + "ов");
      set_long("Немного " + currency + "ов лежат здесь.");
   } else if (amt < 40) {
      set_short("Горстка " + currency + "ов");
      set_long("Горстка " + currency + "ов лежит здесь.");
   } else if (amt < 80) {
      set_short("Кучка " + currency + "ов");
      set_long("Кучка " + currency + "ов лежит здесь.");
   } else if (amt < 150) {
      set_short("Куча " + currency + "ов");
      set_long("Куча " + currency + "ов лежит здесь.");
   } else {
      set_short("Гора " + currency + "ов");
      set_long("Гора " + currency +
         "ов возвышается тут.");
   }
}

int query_weight(void) {
   return 0;
}

int query_value(void) {
   int x;

   x = ::query_value();
   x *= amount;
   return x;
}

int is_money(void) {
   return 1;
}

/* Setup some reasonable defaults.... */
void create(void) {
   ::create();
   set_currency("дукат");
   set_amount(1);

   set_id("монета");
   add_id("монеты");
   set_obj_i_name("монета");
   set_obj_r_name("монеты");
   set_obj_d_name("монете");
   set_obj_v_name("монету");
   set_obj_t_name("монетой");
   set_obj_p_name("монете");
   set_obj_gender("female");
   set_gettable(1);
   set_value(1);
}

