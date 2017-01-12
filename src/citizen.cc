#include "citizen.h"

Citizen::Citizen(HealthPoints health, Age age) : Damageable(health), _age(age) {}

Age Citizen::getAge() const { return _age; }

void Citizen::attack(std::shared_ptr<DamageableAttacker> attacker) {
    takeDamage(attacker->getAttackPower());
}

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    assert(this->getAge() >= 18 && this->getAge() <= 100);
};

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    assert(this->getAge() >= 11 && this->getAge() <= 17);
};

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attackPower) : Adult(health, age), Attacker(attackPower) {};
void Sheriff::attack(std::shared_ptr<DamageableAttacker> attacker) {
    takeDamage(attacker->getAttackPower());
    attacker->takeDamage(getAttackPower());
}

std::shared_ptr<Sheriff> createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return std::make_shared<Sheriff>(health, age, attackPower);
}

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age) {
    return std::make_shared<Adult>(health, age);
}

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age) {
    return std::make_shared<Teenager>(health, age);
}