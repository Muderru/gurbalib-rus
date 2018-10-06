/* A standard set of banking commands that can be added to any object, room or
 * mobile.  You must call bank_init() in the create() or setup() functions of
 * the object inheriting this module */
 
void add_action(string func, string command);
 
void bank_init(void) {
   add_action("do_balance", "баланс");
   add_action("do_withdraw", "снять");
   add_action("do_deposit", "вложить");
   add_action("do_loan", "занять");
 }
 
int do_balance(varargs string str) {
   int amount;

   amount = this_player()->query_bank();
   write("Ваш текущий баланс: " + amount + " дукатов.\n");
   return 1;
}

int do_withdraw(string str) {
   int amount;

   if (sscanf(str, "%d", amount)) {
      if (amount < 1) {
         write("Должно быть не отрицательное число.\n");
         return 1;
         }
      if (this_player()->withdraw(amount)) {
          write("Вы сняли " + amount + " дукатов с банка.\n");
      } else {
          write("У вас нет " + amount + " дукатов в банке.\n");
      }
      do_balance();
      return 1;
   } else {
      write("Использование: снять (количество)\n");
      return 1;
   }
}

int do_deposit(string str) {
   int amount;

   if (sscanf(str, "%d", amount)) {
      if (amount < 1) {
         write("Должно быть не отрицательное число.\n");
         return 1;
         }
      if (this_player()->deposit(amount)) {
          write("Вы вложили " + amount + " дукатов в банк.\n");
      } else {
          write("У вас нет " + amount + " дукатов.\n");
      }
      do_balance();
      return 1;
   } else {
      write("Использование: снять (количество)\n");
      return 1;
   }
}

int do_loan(string str) {
   int amount;

   if (query_wizard(this_player())) {
      if (sscanf(str, "%d", amount)) {
         this_player()->add_money("дукат", amount);
         write("Банк дает вам взаймы " + amount + " дукатов.\n");
         return 1;
      } else {
         write("Использование: занять (количество)\n");
         return 1;
      }
   } 
   return 0; 
}
