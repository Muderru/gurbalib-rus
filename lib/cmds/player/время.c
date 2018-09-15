/* time.c */
inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Использование: время [-h] [-к]" });
   lines += ({ "" });
   lines += ({ "Показывает внутриигровое время." });
   lines += ({ "Календарь выглядит следующим образом." });
   lines += ({ "" });
   lines += ({ "В году 17 месяцев, по числу богов." });
   lines += ({ "В каждом месяце 5 недель, по числу Древних Богов." });
   lines += ({ "В каждой неделе 4 дня, по числу стихий." });
   lines += ({ "" });
   lines += ({ "Один год составляет 340 дней. А, в одном месяце 20 дней." });
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\t-к\tПоказывает короткую версию игрового времени." });
   lines += ({ "Примеры:" });
   lines += ({ "\tвремя" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "score");

   add_also("wiz", "date");
   add_also("wiz", "scan");
   add_also("wiz", "status");
}

string get_hour0() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас полночь.";
         break;
      case 11..20:
         return "Около " +
            "полуночи.";
         break;
      case 21..30:
         return "Прошло полчаса с полуночи.";
         break;
      case 31..40:
         return "Сейчас ближе к часу ночи.";
         break;
      case 41..50:
         return "Менее часа с полуночи.";
         break;
      default :
         return "Примерно час ночи.";
         break;
   }
}

string get_hour1() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "С полуночи прошел час.";
         break;
      case 11..20:
         return "Чуть больше " +
            "часа ночи.";
         break;
      case 21..30:
         return "Примерно половина второго " +
            "ночи.";
         break;
      case 31..40:
         return "Сейчас ближе к двум часам ночи.";
         break;
      case 41..50:
         return "Почти два часа ночи.";
         break;
      default:
         return "Прошло около двух часов с полуночи.";
         break;
   }
}

string get_hour2() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас два часа ночи.";
         break;
      case 11..20:
         return "Теперь все должны спать. Все, кроме вас ...";
         break;
      case 21..30:
         return "Судя по положению луны сейчас должно быть " +
            "около половины третьего.";
         break;
      case 31..40:
         return "Сложно сказать сколько сейчас, темно хоть глаз выколи.";
         break;
      case 41..50:
         return "Слишком темно, чтобы определить время.";
         break;
      default:
         return "Сейчас, вероятно, около трех.";
   }
}

string get_hour3() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Вероятно, около трех часов ночи.";
         break;
      case 11..20:
         return "Что вы делаете в этот час? Уже больше трех часов ночи!";
         break;
      case 21..30:
         return "Сейчас между тремя и четырьмя часами ночи, а больше " +
            "ничего интересного.";
         break;
      case 31..40:
         return "Вам кажется, что время почти четыре часа ночи.";
         break;
      case 41..50:
         return "Сейчас почти четыре часа ночи.";
         break;
      default:
         return "Часы с курантами должны скоро пробить " +
            "четыре раза.";
         break;
   }
}

string get_hour4() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Часы с курантами недавно пробили четыре " +
            "раза.";
         break;
      case 11..20:
         return "Прошло примерно пятнадцать минут с четырех часов.";
         break;
      case 21..30:
         return "Прошло примерно полчаса с четырех часов.";
         break;
      case 31..40:
         return "Время начинает приближаться к пяти часам утра.";
         break;
      case 41..50:
         return "Скоро будет пять часов утра.";
         break;
      default :
         return "Часы с курантами должны скоро пробить " +
            "пять раз.";
         break;
   }
}

string get_hour5() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас пять часов утра, " +
            "скоро рассвет.";
         break;
      case 11..20:
         return "С пяти часов прошло примерно двадцать минут.";
         break;
      case 21..30:
         return "Примерно полчаса прошло с пяти часов.";
         break;
      case 31..40:
         return "Небо на горизонте начинает " +
            "светлеть.";
         break;
      case 41..50:
         return "Из-за горизонта начинает появляться солнце.";
         break;
      default:
         return "Сейчас шесть часов утра.";
         break;
   }
}

string get_hour6() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Солнце взошло. Начался новый день.";
         break;
      case 11..20:
         return "Все вокруг начинают просыпаться и " +
            "заниматься своими делами.";
         break;
      case 21..30:
         return "Сейчас примерно половина седьмого.";
         break;
      case 31..40:
         return "Сейчас было бы неплохо позавтракать.";
         break;
      case 41..50:
         return "Прошел почти час после восхода " +
            "солнца.";
         break;
      default:
         return "Часы с курантами бьют семь раз.";
         break;
   }
}

string get_hour7() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас семь утра. Пора заняться чем-нибудь " +
            "полезным.";
         break;
      case 11..20:
         return "Примерно двадцать минут прошло с семи утра.";
         break;
      case 21..30:
         return "Сейчас примерно половина восьмого. " +
            "Все окончательно проснулись.";
         break;
      case 31..40:
         return "Торговцы готовятся открыть их " +
            "магазины и лавки в городе.";
         break;
      case 41..50:
         return "Почти восемь утра и даже знать начала " +
            "просыпаться.";
         break;
      default:
         return "Сейчас восемь утра и город начинает гудеть, как " +
            "встревоженный улей.";
         break;
   }
}

string get_hour8() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Восемь утра - вставать пора.";
         break;
      case 11..20:
         return "Уже минут двадцать, как нужно заняться чем-нибудь " +
            "полезным.";
         break;
      case 21..30:
         return "Сейчас примерно половина девятого.";
         break;
      case 31..40:
         return "Время приближается к девяти часам утра.";
         break;
      case 41..50:
         return "Сейчас почти девять часов утра.";
         break;
      default:
         return "Скоро часы с курантами начнут бить девять раз.";
         break;
   }
}

string get_hour9() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас девять часов утра.";
         break;
      case 11..20:
         return "С девяти часов утра прошло примерно десять минут.";
         break;
      case 21..30:
         return "Сейчас примерно половина десятого утра.";
         break;
      case 31..40:
         return "Без двадцати минут десять утра.";
         break;
      case 41..50:
         return "Почти десять часов утра.";
         break;
      case 51..60:
         return "Сейчас должно быть десять часов утра.";
         break;
   }
}

string get_hour10() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Все еще утро, десять утра.";
         break;
      case 11..20:
         return "С десяти утра прошло примерно четверть часа.";
         break;
      case 21..30:
         return "Судя по положению солнца, сейчас должно быть " +
            "половина одиннадцатого утра.";
         break;
      case 31..40:
         return "Солнце еще далеко от зенита, время приближается" +
            "к одиннадцати часов утра.";
         break;
      case 41..50:
         return "Сейчас почти одиннадцать часов утра.";
         break;
      default:
         return "Солнечные часы показывают одиннадцать часов утра.";
         break;
   }
}

string get_hour11() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас одиннадцать часов.";
         break;
      case 11..20:
         return "Примерно сорок пять минут до полудня.";
         break;
      case 21..30:
         return "Солнце почти в зените, сейчас половина двенадцатого.";
         break;
      case 31..40:
         return "Сейчас ближе к двенадцати часам дня, чем к одиннадцати.";
         break;
      case 41..50:
         return "Почти полдень.";
         break;
      default:
         return "Сейчас полдень. Солнце находится на пике активности.";
         break;
   }
}

string get_hour12() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас полдень.";
         break;
      case 11..20:
         return "Время приближается к " +
            "обеду.";
         break;
      case 21..30:
         return "Пора заканчивать все дела и начинать приступать " +
            "к обеду.";
         break;
      case 31..40:
         return "Торговцы начинают закрывать их магазины " +
            "на обед.";
         break;
      case 41..50:
         return "Время приближается к часу " +
            "дня.";
         break;
      default:
         return "Улицы города пустеют, все ушли на " +
            "обед.";
         break;
   }
}

string get_hour13() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Час дня. Время обеда.";
         break;
      case 11..20:
         return "Четверть часа прошла с часа дня, пора возвращаться " +
            "к работе.";
         break;
      case 21..30:
         return "Судя по положению солнца, сейчас должно быть " +
            "половина второго дня.";
         break;
      case 31..40:
         return "Ваша тень говорит вам, что время приближается к двум часам дня.";
         break;
      case 41..50:
         return "Сейчас без пятнадцати минут два, вроде.";
         break;
      default:
         return "Почти два часа дня.";
         break;
   }
}

string get_hour14() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас два часа дня.";
         break;
      case 11..20:
         return "Недавно было два часа дня.";
         break;
      case 21..30:
         return "Сейчас почти половина третьего дня.";
         break;
      case 31..40:
         return "Время приближается к трем часам дня.";
         break;
      case 41..50:
         return "Скоро будет три часа дня.";
         break;
      default:
         return "Судя по положению солнца, сейчас почти три часа дня.";
         break;
   }
}

string get_hour15() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Три часа дня, как пить дать!";
         break;
      case 11..20:
         return "Жизнь вокруг бурлит, с трех часов дня " +
            "прошло примерно пятнадцать минут.";
         break;
      case 21..30:
         return "Сейчас половина четвертого.";
         break;
      case 31..40:
         return "Сейчас ближе к четырем часа дня.";
         break;
      case 41..50:
         return "Вроде сейчас без пятнадцати минут четыре часа дня.";
         break;
      default:
         return "Уже почти четыре часа дня.";
         break;
   }
}

string get_hour16() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Сейчас уже четыре часа дня.";
         break;
      case 11..20:
         return "Солнце продвинулось еще дальше на запад, с " +
            "с четырех часов прошло примерно пятнадцать минут.";
         break;
      case 21..30:
         return "Скоро будет половина пятого часа дня.";
         break;
      case 31..40:
         return "Люди начинают готовиться к ужину, " +
            "скоро пять часов дня.";
         break;
      case 41..50:
         return "Магазины начинают закрываться и торговцы готовятся " +
            "к уходу домой, время приближается к пяти часам дня.";
         break;
      default:
         return "Самое время для ужина. Уже пять часов дня.";
         break;
   }
}

string get_hour17() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Время ужина.";
         break;
      case 11..20:
         return "Сейчас все люди ужинают, время чуть позже пяти часов дня.";
         break;
      case 21..30:
         return "Судя по заканчивающим работать людям, " +
            "сейчас половина шестого.";
         break;
      case 31..40:
         return "Все начинают возвращаться с работы домой, " +
            "время приближается к шести часам вечера.";
         break;
      case 41..50:
         return "Сейчас почти шесть часов вечера, солнце начинает заходить за горизонт.";
         break;
      default:
         return "Шесть часов вечера, солнце почти скрылось за горизонтом.";
         break;
   }
}

string get_hour18() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Солнечный диск почти скрылся за горизонтом, " +
            "сейчас должно быть чуть больше шести часов вечера.";
         break;
      case 11..20:
         return "Совсем недавно было шесть часов вечера, сейчас уже совсем стемнело.";
         break;
      case 21..30:
         return "Уже довольно темно, сейчас должно быть половина седьмого вечера.";
         break;
      case 31..40:
         return "Торговцы начинают выгонять из магазинов последних " +
            "покупателей, скоро будет семь часов вечера.";
         break;
      case 41..50:
         return "Торговцы начинают закрывать их магазины, сейчас почти семь часов вечера.";
         break;
      default:
         return "Все магазины закрыты, уже семь часов вечера.";
         break;
   } 
}

string get_hour19() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "все магазины закрыты, а торговцы ушли домой.  " +
            "Сейчас семь часов вечера.";
         break;
      case 11..20:
         return "Солнце зашло за горизонт, сейчас примерно пятнадцать " +
            "минут восьмого часа вечера.";
         break;
      case 21..30:
         return "Начинает пробуждаться ночная жизнь.  " +
            "Сейчас половина восьмого.";
         break;
      case 31..40:
         return "Прошло примерно полтора часа после захода солнца.";
         break;
      case 41..50:
         return "Стрелка часов приближается к восьми.";
         break;
      default:
         return "Сейчас восемь часов вечера.";
         break;
   }
}

string get_hour20() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Часы с курантами пробили двадцать раз. " +
            "Это значит восемь часов вечера.";
         break;
      case 11..20:
         return "С восьми часов вечера прошло примерно пятнадцать минут.";
         break;
      case 21..30:
         return "Сейчас примерно половина девятого вечера.";
         break;
      case 31..40:
         return "Кажется, сейчас между половиной девятого и девятью часами вечера.";
         break;
      case 41..50:
         return "Скоро будет девять часов вечера.";
         break;
      default:
         return "сейчас почти девять часов вечера.";
         break;
   }
}

string get_hour21() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Похоже, что сейчас девять часов вечера";
         break;
      case 11..20:
         return "Сейчас слишком темно, чтобы говорить точно, но кажется " +
            "с девяти часов прошло пятнадцать минут.";
         break;
      case 21..30:
         return "Судя по запираемым на засов дверям сейчас половина десятого вечера.";
         break;
      case 31..40:
         return "Судя по крикам из ближайшей таверны, время приближается к десяти часам вечера.";
         break;
      case 41..50:
         return "Сейчас почти десять часов вечера, деткам пора в кроватку.";
         break;
      default:
         return "Десять часов вечера, все ложатся спать. " +
            "И вам тоже пора.";
         break;
   }
}

string get_hour22() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Недавно пробило десять часов вечера. Началась ночь.";
         break;
      case 11..20:
         return "судя по положению луны, сейчас пятнадцать минут одиннадцатого.";
         break;
      case 21..30:
         return "Похоже, что сейчас половина одиннадцатого ночи.";
         break;
      case 31..40:
         return "Так темно, что хоть глаз выколи. " +
            "Кажется, что скоро наступит одиннадцать часов ночи.";
         break;
      case 41..50:
         return "Сейчас почти одиннадцать часов ночи..";
         break;
      default:
         return "До одиннадцати часов ночи осталась пара минут.";
         break;
   }
}

string get_hour23() {
   switch (TIME_D->query_minute()) {
      case 0..10:
         return "Часы с курантами пробили двадцать три раза.";
         break;
      case 11..20:
         return "Сейчас больше одиннадцати часов ночи, но меньше " +
            "двенадцати.";
         break;
      case 21..30:
         return "Кажется сейчас одиннадцать тридцать ночи, но это не точно.";
         break;
      case 31..40:
         return "Слишком темно чтобы что-то утверждать с уверенностью, " +
            "но сейчас почти полночь.";
         break;
      case 41..50:
         return "Судя по вою волков, сейчас около полуночи.";
         break;
      default:
         return "Сейчас точно полночь.";
         break;
   }
}

static void main(string str) {
   int day;
   string txt, datetxt, *days, *hours, *years;

   if (!alsos) {
      setup_alsos();
   }

   if (!empty_str(str)) {
      if ((str == "-s") || (str == "-S")) {
         write(TIME_D->query_time());
      } else {
         this_player()->more(usage());
      }
      return;
   }

   switch (TIME_D->query_hour()) {
      case 0:
         txt = get_hour0();
         break;
      case 1:
         txt = get_hour1();
         break;
      case 2:
         txt = get_hour2();
         break;
      case 3:
         txt = get_hour3();
         break;
      case 4:
         txt = get_hour4();
         break;
      case 5:
         txt = get_hour5();
         break;
      case 6:
         txt = get_hour6();
         break;
      case 7:
         txt = get_hour7();
         break;
      case 8:
         txt = get_hour8();
         break;
      case 9:
         txt = get_hour9();
         break;
      case 10:
         txt = get_hour10();
         break;
      case 11:
         txt = get_hour11();
         break;
      case 12:
         txt = get_hour12();
         break;
      case 13:
         txt = get_hour13();
         break;
      case 14:
         txt = get_hour14();
         break;
      case 15:
         txt = get_hour15();
         break;
      case 16:
         txt = get_hour16();
         break;
      case 17:
         txt = get_hour17();
         break;
      case 18:
         txt = get_hour18();
         break;
      case 19:
         txt = get_hour19();
         break;
      case 20:
         txt = get_hour20();
         break;
      case 21:
         txt = get_hour21();
         break;
      case 22:
         txt = get_hour22();
         break;
      default:
         txt = get_hour23();
         break;
   }

   days = ({
      "первый", "второй", "третий", "четвертый", "пятый", "шестой", "седьмой",
      "восьмой", "девятый", "десятый", "одиннадцатый", "двенадцатый", "тринадцатый",
      "четырнадцатый", "пятнадцатый", "шестнадцатый", "семнадцатый", "восемнадцатый",
      "девятнадцатый", "последний" });

   datetxt = days[TIME_D->query_day()];

   years = ({
      "Волка", "Льва", "Воробья", "Лошади", "Ящерицы", "Кугуара", "Медведя", "Рыбы",
      "Крокодила", "Мотылька", "Оленя" });

   write("Сегодня день " + TIME_D->query_weekday_name() + ", " + datetxt +
      " месяц " + TIME_D->query_month_name() + ", год " +
      years[TIME_D->query_year() % 11] + ".\n");
   write(txt + "\n");
}
