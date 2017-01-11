#ifndef HORRORMOVIE_MONSTER_H
#define HORRORMOVIE_MONSTER_H

#include <vector>
#include "helper.h"

class Monster : public DamageableAttacker {
public:
    Monster(HealthPoints health, AttackPower attackPower) : DamageableAttacker(health, attackPower) {};
};

class Zombie : public Monster {
public:
    Zombie(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
    Name getName() { return "Zombie"; }
};

class Vampire : public Monster {
public:
    Vampire(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
    Name getName() { return "Zombie"; }
};

class Mummy : public Monster {
public:
    Mummy(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
    Name getName() { return "Zombie"; }
};

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Zombie>(health, attackPower);
}

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Vampire>(health, attackPower);
}

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Mummy>(health, attackPower);
}


class GroupOfMonsters : public DamageableAttacker  {
private:
    std::vector<std::shared_ptr<Monster> > monsters;
public:
    GroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters) :
            DamageableAttacker(getHealth(), getAttackPower()),
            monsters(monsters) {};

    GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster> > monstersList) :
            DamageableAttacker(getHealth(), getAttackPower()),
            monsters(monstersList) {};

    Name getName() const { return "GroupOfMonsters"; }

    void takeDamage(AttackPower damage) {
        for (auto monster : monsters)
            monster->takeDamage(damage);

        this->updateHealth(getHealth());
    }

    HealthPoints getHealth() const {
        HealthPoints sum = 0;
        for (auto monster : monsters) {
            sum += monster->getHealth();
        }
        return sum;
    }

    AttackPower getAttackPower() const {
        AttackPower sum = 0;
        for (auto monster : monsters) {
            if (monster->isAlive())
                sum += monster->getAttackPower();
        }
        return sum;
    }

};

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::vector<std::shared_ptr<Monster> > monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

#endif //HORRORMOVIE_MONSTER_H
