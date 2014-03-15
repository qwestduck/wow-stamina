#include <math.h>
#include <stdio.h>

#include "druid_guardian.h"

/* Configuration */
/* Hover tooltip for stamina on armory: "Stamina <total_stamina> (<base_stamina> + <nonbase_stamina>)" */
const int armory_base_stamina = 121;
const int armory_nonbase_stamina = 34985;

#if 0

const int isProperArmor = 1;

const int flask_stamina = 1500;
const int food_stamina = 450;

const int isFortitude = 1;

/* Class/Spec specific - Druid_Guardian */
const int isBearForm = 1;
const int isTalented_hotw = 1;

#define DRUID_GUARDIAN_HOTW_X 1.06

int DRUID_GUARDIAN_getBaseStamina();
int DRUID_GUARDIAN_getNonbaseStamina(int stamina);

int DRUID_GUARDIAN_getBaseStamina() {
  return 115;
}

int DRUID_GUARDIAN_getNonbaseStamina(int stamina) {
  if(isTalented_hotw == 1) {
    return ((int) ceil( (double) stamina / DRUID_GUARDIAN_HOTW_X ));
  }

  return stamina;
}


/* Race Specific - Tauren */
const int isTauren = 1;





/* Blizzard stuff */
double getBaseHealth();
double stamina_to_health(double stamina);

double getBaseHealth() {
  int base_health = 146663;
  double tauren_multiplier = 1.05;

  if(isTauren == 1) {
    return (double) tauren_multiplier * base_health;
  }

  return (double) base_health;
}

double stamina_to_health(double stamina) {
  if(stamina > 20) {
    return 20 + 14 * (stamina - 20);
  }

  return stamina;
}



int calculateHealth() {
  int base_stamina = DRUID_GUARDIAN_getBaseStamina();
  int nonbase_stamina = DRUID_GUARDIAN_getNonbaseStamina(armory_nonbase_stamina) + 1500 + 450;

  double stamina_modifiers = 1.4 * 1.1 * 1.06 * 1.05;

  base_stamina = floor((double)base_stamina * stamina_modifiers);
  nonbase_stamina = floor((double)nonbase_stamina * stamina_modifiers);

  int stamina = base_stamina + nonbase_stamina;

  double base_health = getBaseHealth();
  double nonbase_health = stamina_to_health(stamina);

  int health = ((int) (base_health + nonbase_health));

  printf("Base Stamina: %d\n", base_stamina);
  printf("Nonbase Stamina: %d\n", nonbase_stamina);
  printf("Base Health: %f\n", base_health);
  printf("Nonbase Health: %f\n", nonbase_health);
  printf("Health: %d\n", health);
}
#endif

int main() {
  DruidGuardian doge;

  doge.calculateHealth(armory_nonbase_stamina);
  printf("%d\n", doge.getHealth());
}
