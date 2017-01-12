#include "helper.h"

void Damageable::updateHealth(HealthPoints healthUpdated) { health = healthUpdated; };

Damageable::Damageable(HealthPoints health) : health(health) {};

HealthPoints Damageable::getHealth() const { return health; }

void Damageable::takeDamage(AttackPower damage) {
    if (health - damage < 0) health = 0;
    else health -= damage;
}

bool Damageable::isAlive() const { return health > 0; }

Attacker::Attacker(AttackPower attackPower) : attackPower(attackPower) {};

AttackPower Attacker::getAttackPower() const { return attackPower; }

Name Attacker::getName() const { return "Attacker"; };

DamageableAttacker::DamageableAttacker(HealthPoints health, AttackPower attackPower) : Damageable(health), Attacker(attackPower) {}

