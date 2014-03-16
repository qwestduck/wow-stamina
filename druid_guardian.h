#ifndef DRUID_GUARDIAN_H
#define DRUID_GUARDIAN_H

#include <math.h>
#include "priest.h"

#define BEAR_FORM_X 1.4
#define LEATHER_SPEC_X 1.05
#define HOTW_X 1.06

class DruidGuardian: public HealthSource {
  public:
    DruidGuardian() {
      isTalented_hotw = true;
    }

    DruidGuardian(int _armory_upper_stamina) {
      isTalented_hotw = true;

      armory_upper_stamina = _armory_upper_stamina;
    }

    double getUpperStamina() {
      if(isTalented_hotw) {
        return ((int) ceil( (double) armory_upper_stamina / HOTW_X ));
      }

      return armory_upper_stamina;
    }

    double getStamina_X() {
      double x;

      x = BEAR_FORM_X * PW_FORTITUDE_X * LEATHER_SPEC_X;
      if(isTalented_hotw) x *= HOTW_X;

      return x;
    }

  private:
    bool isTalented_hotw;
    int armory_upper_stamina;
};
#endif
