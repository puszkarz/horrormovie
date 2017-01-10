#ifndef HORRORMOVIE_HELPER_H
#define HORRORMOVIE_HELPER_H

#include <cassert>

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

class Damageable {
private:
    HealthPoints health;
protected:
    void updateHealth(HealthPoints healthUpdated) { health = healthUpdated; };
public:
    Damageable(HealthPoints health) : health(health) {};
    HealthPoints getHealth() { return health; }
    virtual void takeDamage(AttackPower damage) {
        if (health - damage < 0) health = 0;
        else health -= damage;
    }
};

class Attacker {
private:
    AttackPower attackPower;
public:
    virtual Attacker(AttackPower attackPower) : attackPower(attackPower) {};
    AttackPower getAttackPower() { return attackPower; }
};

#endif //HORRORMOVIE_HELPER_H
