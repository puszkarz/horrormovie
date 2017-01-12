#include "helper.h"

void Damageable::updateHealth(HealthPoints healthUpdated) { _health = healthUpdated; };

Damageable::Damageable(HealthPoints health) : _health(health) { assert(health > 0); };

HealthPoints Damageable::getHealth() const { return _health; }

void Damageable::takeDamage(AttackPower damage) {
    if (_health - damage < 0) _health = 0;
    else _health -= damage;
}

bool Damageable::isAlive() const { return _health > 0; }

Attacker::Attacker(AttackPower attackPower) : _attackPower(attackPower) {
    assert(attackPower >= 0);
};

AttackPower Attacker::getAttackPower() const { return _attackPower; }

Name Attacker::getName() const { return "Attacker"; };

DamageableAttacker::DamageableAttacker(HealthPoints health, AttackPower attackPower) : Damageable(health), Attacker(attackPower) {}

