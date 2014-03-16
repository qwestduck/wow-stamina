#ifndef RACE_CLASS_H
#define RACE_CLASS_H

enum { NELF, TAUREN, TROLL, WORGEN };
enum { DRUID };

class RaceClass: public HealthSource {
  public:
    RaceClass() {
      race = TAUREN;
      classy = DRUID;
    }

    double getBaseHealth() {
      if( race == TAUREN ) return 146663.0 * 1.05;
    
      return 146663.0;
    }

    double getLowerStamina() {
      if( classy == DRUID ) {
        if( race == TAUREN ) return 115.0;
        return 114.0;
      }
    }

  private:
    int race;
    int classy;
};

#endif
