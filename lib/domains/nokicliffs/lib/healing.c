static object doctor, patient;

void set_doctor(object obj) {
   doctor = obj;
}

void set_patient(object obj) {
   patient = obj;
}

object query_doctor() {
   return doctor;
}

object query_patient() {
   return patient;
}

nomask int can_heal() {
   return !nilp(patient) && patient->is_living();
}

int hp_needed() {
   return can_heal() && patient->query_hp() < patient->query_max_hp();
}

int mana_needed() {
   return can_heal() && patient->query_mana() < patient->query_max_mana();
}

int end_needed() {
   return can_heal() && patient->query_end() < patient->query_max_end();
}

int should_heal_hp() {
   return 1;
}

int should_heal_mana() {
   return 1;
}

int should_heal_end() {
   return 1;
}

void show_healing_message(string msg) {
   if (!nilp(doctor) && !nilp(patient) && !empty_str(msg)) {
      doctor->targeted_action(msg, patient);
   }
}

int recover_hp(int amt, string msg) {
   if (should_heal_hp()) {
      patient->increase_hp(amt);
      show_healing_message(msg);
      return 1;
   }
   return 0;
}

int recover_mana(int amt, string msg) {
   if (should_heal_mana()) {
      patient->increase_mana(amt);
      show_healing_message(msg);
      return 1;
   }
   return 0;
}

int recover_end(int amt, string msg) {
   if (should_heal_end()) {
      patient->increase_end(amt);
      show_healing_message(msg);
      return 1;
   }
   return 0;
}
