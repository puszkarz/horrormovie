#ifndef HORRORMOVIE_HELPER_H
#define HORRORMOVIE_HELPER_H

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

class Damageable {
protected:
    HealthPoints health;
public:
    virtual Damageable() = 0;
    virtual HealthPoints getHealth() { return health; }
    virtual void takeDamage(AttackPower damage) {
        if (health - damage < 0) health = 0;
        else health -= damage;
    }
};

class Attacker {
protected:
    AttackPower attackPower;
public:
    virtual Attacker() = 0;
    AttackPower getAttackPower() { return attackPower; }
};

#endif //HORRORMOVIE_HELPER_H
