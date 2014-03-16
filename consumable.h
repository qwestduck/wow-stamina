#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Consumable: public HealthSource {
  public:
    Consumable() {
      stamina_flask = 1500;
      stamina_food = 450;
    }

    double getUpperStamina() {
      return (double) stamina_flask + stamina_food;
    }

  private:
    int stamina_flask;
    int stamina_food;
};

#endif
