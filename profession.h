#ifndef PROFESSION_H
#define PROFESSION_H

class Profession : public HealthSource {
  public:
    Profession() {
      level_mining = 0;
    }

    double getLowerStamina() {
      if(level_mining >= 600) return 480.0;
      if(level_mining >= 525) return 120.0;
      if(level_mining >= 450) return 48.0;
      if(level_mining >= 375) return 24.0;
      if(level_mining >= 300) return 10.0;
      if(level_mining >= 225) return 7.0;
      if(level_mining >= 150) return 5.0;
      if(level_mining >= 75) return 3.0;

      return 0.0;
    }

  private:
    int level_mining;
};

#endif
