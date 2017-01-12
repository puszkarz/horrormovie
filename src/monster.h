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
    Name getName() const override;
};

class Vampire : public Monster {
public:
    Vampire(HealthPoints health, AttackPower attackPower);
    Name getName() const override;
};

class Mummy : public Monster {
public:
    Mummy(HealthPoints health, AttackPower attackPower);
    Name getName() const override;
};

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower);


class GroupOfMonsters : public DamageableAttacker  {
private:
    std::vector<std::shared_ptr<Monster> > _monsters;
    static HealthPoints calcHealth(const std::vector<std::shared_ptr<Monster>>& monsters);
    static AttackPower calcAttackPower(const std::vector<std::shared_ptr<Monster>>& monsters);

public:
    GroupOfMonsters(const std::vector<std::shared_ptr<Monster>> &monsters);
    GroupOfMonsters(const std::initializer_list<std::shared_ptr<Monster> > &monstersList);

    Name getName() const override;

    void takeDamage(AttackPower damage) override;

    HealthPoints getHealth() const override;

    AttackPower getAttackPower() const override;
};

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(const std::vector<std::shared_ptr<Monster> > &monsters);
#endif //HORRORMOVIE_MONSTER_H
