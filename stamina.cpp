#include <math.h>
#include <stdio.h>

#include "druid_guardian.h"

/* Configuration */
/* Hover tooltip for stamina on armory: "Stamina <total_stamina> (<base_stamina> + <nonbase_stamina>)" */
const int armory_base_stamina = 121;
const int armory_nonbase_stamina = 34985;

int main() {
  DruidGuardian doge;

  doge.calculateHealth(armory_nonbase_stamina);
  printf("%d\n", doge.getHealth());
}
