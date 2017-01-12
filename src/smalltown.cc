#include "smalltown.h"

Status::Status(std::shared_ptr<DamageableAttacker> attacker, unsigned int aliveCitizensNumber) : _attacker(attacker), _aliveCitizensNumber(aliveCitizensNumber) {}
unsigned int Status::getAliveCitizens() const { return _aliveCitizensNumber; }
HealthPoints Status::getMonsterHealth() const { return _attacker->getHealth(); }
Name Status::getMonsterName() const { return _attacker->getName(); }

Status SmallTown::getStatus() {
    return Status(_attacker, _aliveCitizensNumber);
}

void SmallTown::tick(Time timeStep) {
    if (_attackStrategy->attackTime(_currentTime)) {
        Status status = getStatus();

        if (status.getAliveCitizens() == 0 && status.getMonsterHealth() == 0)
            std::cout << "DRAW" << std::endl;
        else if (status.getAliveCitizens() == 0)
            std::cout << "MONSTER WON" << std::endl;
        else if (status.getMonsterHealth() == 0)
            std::cout << "CITIZENS WON" << std::endl;
        else
            attackTown();
    }
    _currentTime = (_currentTime + timeStep) % _maxTime;
}

void SmallTown::attackTown() {
    for (auto citizen : _citizens) {
        citizen->attack(_attacker);
        if (!citizen->isAlive())
            _aliveCitizensNumber--;
    }
}

SmallTown::SmallTown(std::shared_ptr<DamageableAttacker> attacker, Time startTime, Time maxTime, std::shared_ptr<AttackStrategy> attackStrategy,
                     std::vector<std::shared_ptr<Citizen> > citizens) : _attacker(attacker), _currentTime(startTime), _maxTime(maxTime),
                                                                        _attackStrategy(attackStrategy), _citizens(citizens),
                                                                        _aliveCitizensNumber(static_cast<unsigned int>(citizens.size())) {}

SmallTown::Builder& SmallTown::Builder::citizen(std::shared_ptr<Citizen> citizen) {
    this->_citizens.push_back(citizen);
    return *this;
}
SmallTown::Builder& SmallTown::Builder::maxTime(Time maxTime) {
    this->_t1 = maxTime;
    return *this;
}
SmallTown::Builder& SmallTown::Builder::startTime(Time startTime) {
    this->_t0 = startTime;
    return *this;
}
SmallTown::Builder& SmallTown::Builder::monster(std::shared_ptr<DamageableAttacker> attacker) {
    this->_attacker = std::shared_ptr<DamageableAttacker>(attacker);
    return *this;
}
SmallTown SmallTown::Builder::build() {
    return SmallTown(_attacker, _t0, _t1, _attackStrategy, _citizens);
}

SmallTown::Builder & SmallTown::Builder::strategy(std::shared_ptr<AttackStrategy> strategy) {
    this->_attackStrategy = std::shared_ptr<AttackStrategy>(strategy);
    return *this;
}

bool DefaultStrategy::attackTime(Time time) {
    return (time % 7 != 0) && (time % 3 == 0 || time % 13 == 0);
}