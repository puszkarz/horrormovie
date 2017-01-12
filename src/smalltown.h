#ifndef HORRORMOVIE_SMALLTOWN_H
#define HORRORMOVIE_SMALLTOWN_H

#include "helper.h"
#include "citizen.h"
#include <iostream>
#include <vector>
#include <memory>

using Time = int;

class Status {
private:
    std::shared_ptr<DamageableAttacker> _attacker;
    unsigned int _aliveCitizensNumber;
public:
    Status (std::shared_ptr<DamageableAttacker> attacker, unsigned int aliveCitizensNumber);
    Name getMonsterName() const;
    HealthPoints getMonsterHealth() const;
    unsigned int getAliveCitizens() const;
};

class AttackStrategy {
public:
    /**
     * Check if at the given time town is attacked.
     */
    virtual bool attackTime(Time time) = 0;
};

class DefaultStrategy : public AttackStrategy {
public:
    bool attackTime(Time time);
};

class TownClock {
private:
    Time _currentTime;
    Time _maxTime;
public:
    TownClock(Time startTime, Time maxTime);
    void makeStep(Time timeStep);
    Time getCurrentTime() const;
};

class SmallTown {
private:
    std::shared_ptr<DamageableAttacker> _attacker;
    TownClock _clock;
    std::shared_ptr<AttackStrategy> _attackStrategy;
    std::vector<std::shared_ptr<Citizen> > _citizens;
    unsigned int _aliveCitizensNumber;
    /**
     * Simulation of the attack on the town.
     */
    void attackTown();
    SmallTown (std::shared_ptr<DamageableAttacker> attacker,
               Time startTime,
               Time maxTime,
               std::shared_ptr<AttackStrategy> attackStrategy,
               const std::vector<std::shared_ptr<Citizen>> &citizens);
public:
    class Builder;
    /**
     * Return the status class with the information about the name of the attacker, its health points
     * and the population of the town.
     */
    Status getStatus();
    /**
     * Move in time within the timeStep. Check if the town or monster won or there is a draw.
     * If the current time is the attack time, then simulate the attack on the town.
     */
    void tick(Time timeStep);
};


class SmallTown::Builder {
private:
    std::shared_ptr<DamageableAttacker> _attacker;
    std::vector<std::shared_ptr<Citizen>> _citizens;
    Time _t0;
    Time _t1;
    std::shared_ptr<AttackStrategy> _attackStrategy = std::make_shared<DefaultStrategy>();
    /**
     * Strategy - determine the time for the attack.
     */
public:
    Builder& startTime(Time startTime);
    Builder& maxTime(Time maxTime);
    Builder& citizen(std::shared_ptr<Citizen> citizen);
    Builder& monster(std::shared_ptr<DamageableAttacker> attacker);
    Builder& strategy(std::shared_ptr<AttackStrategy> strategy);
    SmallTown build();
};

#endif //HORRORMOVIE_SMALLTOWN_H
