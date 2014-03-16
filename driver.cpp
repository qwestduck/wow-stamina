#include <stdio.h>

#include "health_source.h"
#include "druid_guardian.h"
#include "race_class.h"
#include "consumable.h"
#include "profession.h"

const int armory_upper_stamina = 34985;

double stamina_to_health(double stamina) {
  if(stamina > 20) { 
    return 20 + 14 * (stamina - 20);
  }
     
  return stamina;
}

int main() {
  const int hs_size = 4;
  HealthSource* hs[hs_size];

  hs[0] = new DruidGuardian(armory_upper_stamina);
  hs[1] = new RaceClass();
  hs[2] = new Consumable(); 
  hs[3] = new Profession();

  double upper_stamina = 0.0;
  double lower_stamina = 0.0;
  double base_health = 0.0;
  double stamina_x = 1.0;

  for(int i = 0; i < hs_size; i++) {
    lower_stamina += hs[i]->getLowerStamina();
    upper_stamina += hs[i]->getUpperStamina();
    base_health += hs[i]->getBaseHealth();
    stamina_x *= hs[i]->getStamina_X();
  }

  upper_stamina = floor(upper_stamina * stamina_x);
  lower_stamina = floor(lower_stamina * stamina_x);

  printf("Upper Stamina: %d\n", (int) upper_stamina);
  printf("Lower Stamina: %d\n", (int) lower_stamina);

  printf("\nHealth %d\n", (int) floor(base_health + stamina_to_health(lower_stamina + upper_stamina)));
}
