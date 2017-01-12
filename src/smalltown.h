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

class SmallTown {
private:
    std::shared_ptr<DamageableAttacker> _attacker;
    Time _currentTime;
    Time _maxTime;
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
               std::vector<std::shared_ptr<Citizen>> citizens);
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
    /**
     * Strategy - determine the time for the attack.
     */
    std::shared_ptr<AttackStrategy> _attackStrategy = std::make_shared<DefaultStrategy>();
public:
    Builder& startTime(Time startTime);
    Builder& maxTime(Time maxTime);
    Builder& citizen(std::shared_ptr<Citizen> citizen);
    Builder& monster(std::shared_ptr<DamageableAttacker> attacker);
    Builder& strategy(std::shared_ptr<AttackStrategy> strategy);
    SmallTown build();
};


//Klasa SmallTown tworzona za pomocą klasy Builder, dla której można ustawić co
//        najmniej:
//* potwora, który atakuje miasto,
//* czas startowy t0 typu Time,
//* czas maksymalny t1 typu Time,
//* obywateli miasteczka.
//
//Klasa SmallTown ma metody publiczne:
//        Status getStatus() – zwraca nazwę typu potwora, liczbę jego punktów życia oraz
//liczbę pozostałych przy życiu mieszkańców;
//void tick(Time timeStep) – na początku sprawdza aktualny czas; jeśli jest to czas
//ataku, to następuje atak na wszystkich mieszkańców; na koniec czas w miasteczku
//        przesuwa się o timeStep.
//
//SmallTown operuje zgodnie z wewnętrznym zegarem. Czas liczony jest w godzinach,
//od godziny 0 do godziny t1 i potem znów od godziny 0, i tak cyklicznie. Pierwsze
//        odliczanie zaczyna się od godziny t0. Potwór atakuje tylko o godzinach
//        podzielnych  przez 3 lub 13, a niepodzielnych przez 7.
//Śmierć mieszkańca bądź potwora następuje w momencie, gdy jego liczba punktów
//życia osiągnie zero. Wywołanie tick() na miasteczku z martwym potworem i co
//        najmniej jednym żywym mieszkańcem powoduje wypisanie na standardowe wyjście
//komunikatu "CITIZENS WON". Wywołanie tick() na miasteczku z martwymi
//mieszkańcami i żywym potworem powoduje wypisanie na standardowym wyjściu napisu
//"MONSTER WON". Jeśli zarówno mieszańcy, jak i potwór są martwi, to tick()
//wypisuje na standardowe wyjście "DRAW".

#endif //HORRORMOVIE_SMALLTOWN_H
