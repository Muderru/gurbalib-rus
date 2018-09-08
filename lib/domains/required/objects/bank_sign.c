inherit "/std/sign";
inherit "/std/modules/m_bank_teller";

void setup(void) {
   bank_init();
   set_message("Вы можете выполнить следующие действия в банке:\n" +
      "\tbalance    : Узнать свой баланс.\n" +
      "\tdeposit #  : Вложить # монет в банк.\n" +
      "\twithdraw # : Снять # монет из банка.\n");
}
