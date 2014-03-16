#ifndef HEALTH_SOURCE_H
#define HEALTH_SOURCE_H

class HealthSource {
  public:
    virtual double getBaseHealth() { return 0; }
    virtual double getLowerStamina() { return 0; }
    virtual double getUpperStamina() { return 0; }
    virtual double getStamina_X() { return 1.0; }
};

#endif
