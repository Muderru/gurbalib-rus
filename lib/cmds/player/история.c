/* history.c */
inherit M_COMMAND;
inherit M_GETOPT;

#define REMOVE_OPTION "remove"

string *usage(void) {
   string *lines;

   lines = ({ "Использование: история [-h|-r [диапазон]]" });
   lines += ({ "" });
   lines += ({ "Сохраняются последние двадцать успешных команд.  Вы сможете " +
      "повторить любую команду " });
   lines += ({ "в вашей истории.  Также вы можете удалить любую команду из " +
      "вашей истории." });
   lines += ({ "Вы можете использовать следующие горячие клавиши:" });
   lines += ({ "!\tПоказывает сохраненную историю." });
   lines += ({ "!!\tПовторяет последнюю команду в вашей истории." });
   lines += ({ "!drink\tПовторяет последнюю команду в вашей истории со " +
       "словом \"drink\"" });
   lines += ({ "" });
   lines += ({ "Если вы хотите удалить команду из вашей истории используйте " +
      "флаг -у (русская буква у). " });
   lines += ({ "Этот флаг также работает с диапазонами." });
   lines += ({ "Чтобы удалить третью команду из истории наберите: история -у 3" });
   lines += ({ "" });
   lines += ({ "Если не будет указано аргументов, то будет показана ваша " +
      "история команд." });
   
   lines += ({ "" });
   lines += ({ "Опции:" });
   lines += ({ "\t-h\tПомошь, вызывает эту справку." });
   lines += ({ "\t-у\tУдаляет команду или диапазон команд." });
   lines += ({ "" });
   lines += ({ "Примеры:" });
   lines += ({ "\tистория" });
   lines += ({ "\tистория -h" });
   lines += ({ "\tистория -у 1-3,5,7-10" });
   lines += ({ "\t!!" });
   lines += ({ "\t!" });

   return lines;
}

static void main(string str) {
   string opt;
   int *range, i, dim;

   if (empty_str(str)) {
	write(this_player()->list_history());
	return;
   } else if (sscanf(str, "-у %s", opt)) {
         range = parse_range(opt);
         dim = sizeof(range);
         for (i = 0; i < dim; i++) {
            this_player()->remove_history(range[i]);
         }
         this_player()->compress_history();
         write(this_player()->list_history());
      return;
   }

   this_player()->more(usage());
}

