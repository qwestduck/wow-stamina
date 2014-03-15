#ifndef SPEC_H
#define SPEC_H

#include <math.h>

#define BASE_HEALTH 146663.0
#define BASE_HEALTH_TAUREN_X 1.05

class Spec {
  public:
    Spec() {
      isTauren = true;

      flask_stamina = 1500;
      food_stamina = 450;

      base_health = BASE_HEALTH;
      if(isTauren) {
        base_health *= BASE_HEALTH_TAUREN_X;
      }
    }

    void calculateHealth(int _armory_nonbase_stamina) {
      armory_nonbase_stamina = _armory_nonbase_stamina;

      base_stamina = getBaseStamina();
      nonbase_stamina = getNonbaseStamina(armory_nonbase_stamina);
      nonbase_stamina += flask_stamina + food_stamina;

      stamina_x = getStamina_X();

      cpane_base_stamina = floor((double)base_stamina * stamina_x);
      cpane_nonbase_stamina = floor((double)nonbase_stamina * stamina_x);
      cpane_stamina = cpane_base_stamina + cpane_nonbase_stamina;

      nonbase_health = stamina_to_health(cpane_stamina);

      cpane_health = ((int) (base_health + nonbase_health));
    }

    int getHealth() {
      return cpane_health;
    }

    virtual double getBaseStamina() = 0;
    virtual double getNonbaseStamina(int armory_nonbase_stamina) = 0;
    virtual double getStamina_X() = 0;

  private:
    double stamina_to_health(double stamina) {
      if(stamina > 20) {
        return 20 + 14 * (stamina - 20);
      }

      return stamina;
    }

    bool isTauren;

    int flask_stamina;
    int food_stamina;

    double base_health;
    double nonbase_health;

    /* character display on armory
     *
     * This does not account for buffs, debuffs, and consumables.
     */
    int armory_nonbase_stamina;

    /* true initial stamina
     *
     * This removes certain passive effects that inflate armory stamina
     */
    double base_stamina;
    double nonbase_stamina;

    /* in-game character pane display
     *
     * This accounts for all buffs, debuffs, and consumables.
     */
    int cpane_base_stamina;
    int cpane_nonbase_stamina;
    int cpane_stamina;
    int cpane_health;

    /* stamina multiplier */
    double stamina_x;
};
#endif
