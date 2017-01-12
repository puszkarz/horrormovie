#ifndef HORRORMOVIE_MONSTER_H
#define HORRORMOVIE_MONSTER_H

#include <vector>
#include "helper.h"

class Monster : public DamageableAttacker {
public:
    Monster(HealthPoints health, AttackPower attackPower);
};

class Zombie : public Monster {
public:
    Zombie(HealthPoints health, AttackPower attackPower);
    Name getName() const;
};

class Vampire : public Monster {
public:
    Vampire(HealthPoints health, AttackPower attackPower);
    Name getName() const;
};

class Mummy : public Monster {
public:
    Mummy(HealthPoints health, AttackPower attackPower);
    Name getName() const;
};

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower);


class GroupOfMonsters : public DamageableAttacker  {
private:
    std::vector<std::shared_ptr<Monster> > monsters;
    static HealthPoints calcHealth(const std::vector<std::shared_ptr<Monster>> monsters);
    static AttackPower calcAttackPower(const std::vector<std::shared_ptr<Monster>> monsters);

public:
    GroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters);
    GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster> > monstersList);

    Name getName() const;

    void takeDamage(AttackPower damage);

    HealthPoints getHealth() const;

    AttackPower getAttackPower() const;
};

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::vector<std::shared_ptr<Monster> > monsters);
#endif //HORRORMOVIE_MONSTER_H
