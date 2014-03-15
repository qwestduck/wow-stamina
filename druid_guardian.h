#ifndef DRUID_GUARDIAN_H
#define DRUID_GUARDIAN_H

#include <math.h>
#include "spec.h"
#include "priest.h"

#define DRUID_GUARDIAN_BASE_STAMINA 115.0

#define BEAR_FORM_X 1.4
#define LEATHER_SPEC_X 1.05
#define HOTW_X 1.06

class DruidGuardian: public Spec {
  public:
    DruidGuardian() {
      isTalented_hotw = true;
    }

    double getBaseStamina() {
      return DRUID_GUARDIAN_BASE_STAMINA;
    }

    double getNonbaseStamina(int armory_nonbase_stamina) {
      if(isTalented_hotw) {
        return ((int) ceil( (double) armory_nonbase_stamina / HOTW_X ));
      }

      return armory_nonbase_stamina;
    }

    double getStamina_X() {
      double x;

      x = BEAR_FORM_X * PW_FORTITUDE_X * LEATHER_SPEC_X;
      if(isTalented_hotw) x *= HOTW_X;

      return x;
    }

  private:
    bool isTalented_hotw;
};
#endif
