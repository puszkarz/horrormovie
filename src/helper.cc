#include "helper.h"

void Damageable::updateHealth(HealthPoints healthUpdated) { health = healthUpdated; };

Damageable::Damageable(HealthPoints health) : health(health) { assert(health > 0); };

HealthPoints Damageable::getHealth() const { return health; }

void Damageable::takeDamage(AttackPower damage) {
    if (health - damage < 0) health = 0;
    else health -= damage;
}

bool Damageable::isAlive() const { return health > 0; }

Attacker::Attacker(AttackPower attackPower) : attackPower(attackPower) {
    assert(attackPower >= 0);
};

AttackPower Attacker::getAttackPower() const { return attackPower; }

Name Attacker::getName() const { return "Attacker"; };

DamageableAttacker::DamageableAttacker(HealthPoints health, AttackPower attackPower) : Damageable(health), Attacker(attackPower) {}

