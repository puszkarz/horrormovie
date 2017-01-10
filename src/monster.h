#ifndef HORRORMOVIE_MONSTER_H
#define HORRORMOVIE_MONSTER_H

#include <vector>
#include "helper.h"

class Monster : public Damageable, public Attacker {
public:
    Monster(HealthPoints health, AttackPower attackPower) : Damageable(health), Attacker(attackPower) {};
};

class Zombie : public Monster {
public:
    Zombie(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
};

class Vampire : public Monster {
public:
    Vampire(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
};

class Mummy : public Monster {
public:
    Mummy(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
};

Zombie* createZombie(HealthPoints health, AttackPower attackPower) {
    return new Zombie(health, attackPower);
}

Vampire* createVampire(HealthPoints health, AttackPower attackPower) {
    return new Vampire(health, attackPower);
}

Mummy* createMummy(HealthPoints health, AttackPower attackPower) {
    return new Mummy(health, attackPower);
}

HealthPoints healthSum(std::vector<Monster*> monsters) {
    HealthPoints sum = 0;
    for (Monster* monster : monsters) {
        sum += monster->getHealth();
    }
    return sum;
}

AttackPower attackSum(std::vector<Monster*> monsters) {
    AttackPower sum = 0;
    for (Monster* monster : monsters) {
        sum += monster->getAttackPower();
    }
    return sum;
}

class GroupOfMonsters : public Damageable, public Attacker {
    std::vector<Monster*> monsters;
public:
    GroupOfMonsters(std::vector<Monster*> monsters) : Damageable(healthSum(monsters)), Attacker(attackSum(monsters)), monsters(monsters) {};
    // TODO: albo listę inicjującą (std::initializer_list)

    void takeDamage(AttackPower damage) {
        for (Monster* monster : monsters)
            monster->takeDamage(damage);
        this->updateHealth(healthSum(monsters));
    }
};

GroupOfMonsters* createGroupOfMonsters(std::vector<Monster*> monsters) {
    return new GroupOfMonsters(monsters);
}

#endif //HORRORMOVIE_MONSTER_H
