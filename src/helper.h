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
    HealthPoints _health;
protected:
    void updateHealth(HealthPoints healthUpdated);
public:
    Damageable(HealthPoints health);
    virtual HealthPoints getHealth() const;
    /**
     * Take health points from the unit.
     */
    virtual void takeDamage(AttackPower damage);
    bool isAlive() const;
};

class Attacker {
private:
    AttackPower _attackPower;
public:
    Attacker(AttackPower attackPower);
    virtual AttackPower getAttackPower() const;
    virtual Name getName() const;
};

class DamageableAttacker : public Damageable, public Attacker {
public:
    DamageableAttacker(HealthPoints health, AttackPower attackPower);
};

#endif //HORRORMOVIE_HELPER_H
