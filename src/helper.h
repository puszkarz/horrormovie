#ifndef HORRORMOVIE_HELPER_H
#define HORRORMOVIE_HELPER_H

#include <iostream>
#include <cassert>
#include <memory>

using HealthPoints = int;
using Age = int;
using AttackPower = int;
using Name = std::string;

class Damageable {
private:
    HealthPoints health;
protected:
    void updateHealth(HealthPoints healthUpdated) { health = healthUpdated; };
public:
    Damageable(HealthPoints health) : health(health) {};
    virtual HealthPoints getHealth() const { return health; }
    virtual void takeDamage(AttackPower damage) {
        if (health - damage < 0) health = 0;
        else health -= damage;
    }
    bool isAlive() { return health > 0; }
};

class Attacker {
private:
    AttackPower attackPower;
public:
    Attacker(AttackPower attackPower) : attackPower(attackPower) {};
    virtual AttackPower getAttackPower() const { return attackPower; }
    virtual Name getName() const {};
};

class DamageableAttacker : public Damageable, public Attacker {
public:
    DamageableAttacker(HealthPoints health, AttackPower attackPower) : Damageable(health), Attacker(attackPower) {}
};

#endif //HORRORMOVIE_HELPER_H
