#include "monster.h"

Monster::Monster(HealthPoints health, AttackPower attackPower) : DamageableAttacker(health, attackPower) {}

Zombie::Zombie(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
Name Zombie::getName() const { return "Zombie"; }

Vampire::Vampire(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
Name Vampire::getName() const { return "Vampire"; }

Mummy::Mummy(HealthPoints health, AttackPower attackPower) : Monster(health, attackPower) {};
Name Mummy::getName() const { return "Mummy"; }

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Zombie>(health, attackPower);
}

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Vampire>(health, attackPower);
}

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Mummy>(health, attackPower);
}

GroupOfMonsters::GroupOfMonsters(const std::vector<std::shared_ptr<Monster>> &monsters) :
    DamageableAttacker(GroupOfMonsters::calcHealth(monsters), GroupOfMonsters::calcAttackPower(monsters)),
    _monsters(monsters) {};

GroupOfMonsters::GroupOfMonsters(const std::initializer_list<std::shared_ptr<Monster> > &monstersList) :
    DamageableAttacker(GroupOfMonsters::calcHealth(_monsters), GroupOfMonsters::calcAttackPower(_monsters)),
    _monsters(monstersList) {};

Name GroupOfMonsters::getName() const { return "GroupOfMonsters"; }

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (auto monster : _monsters)
        monster->takeDamage(damage);
    this->updateHealth(this->getHealth());
}

HealthPoints GroupOfMonsters::calcHealth(const std::vector<std::shared_ptr<Monster>>& monsters) {
    HealthPoints sum = 0;
    for (auto monster : monsters) {
        sum += monster->getHealth();
    }
    return sum;
}

AttackPower GroupOfMonsters::calcAttackPower(const std::vector<std::shared_ptr<Monster>>& monsters) {
    AttackPower sum = 0;
    for (auto monster : monsters) {
        if (monster->isAlive())
            sum += monster->getAttackPower();
    }
    return sum;
}

HealthPoints GroupOfMonsters::getHealth() const {
    return GroupOfMonsters::calcHealth(_monsters);
}

AttackPower GroupOfMonsters::getAttackPower() const {
    return GroupOfMonsters::calcAttackPower(_monsters);
}

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(const std::vector<std::shared_ptr<Monster> > &monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

