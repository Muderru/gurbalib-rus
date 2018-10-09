string gender;

void set_gender(string gen) {
   gender = gen;
}

string query_gender(void) {
   switch (gender) {
      case "male":
         return "male";
      case "female":
         return "female";
      case "neuter":
         return "neuter";
      default:
         return "неизвестный";
   }
}

string query_gender_pronoun(void) {
   switch (gender) {
      case "male":
         return "он";
      case "female":
         return "она";
      default:
         return "оно";
   }
}

string query_gender_determiner(void) {
   switch (gender) {
      case "male":
         return "его";
      case "female":
         return "ее";
      default:
         return "его";
   }
}

string query_gender_possessive(void) {
   switch (gender) {
      case "male":
         return "его";
      case "female":
         return "ее";
      default:
         return "его";
   }
}

string query_gender_reflexive(void) {
   switch (gender) {
      case "male":
         return "себя";
      case "female":
         return "себя";
      default:
         return "себя";
   }
}
