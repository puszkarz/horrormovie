//
//  horror_example.cc
//  horror-movie-2
//
//  Created by Patrycja Wegrzynowicz on 12/10/16.
//  Copyright (c) 2016 Patrycja Wegrzynowicz. All rights reserved.
//

#include "citizen.h"
#include "monster.h"
#include "smalltown.h"

int main(int argc, const char * argv[]) {
    auto groupOfMonsters = createGroupOfMonsters({
                                                         createMummy(90, 1),
                                                         createZombie(20, 1),
                                                         createVampire(30, 1)
                                                 });

    auto citiz = createAdult(100, 21);

    auto smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(3)
            .maxTime(27)
            .citizen(createSheriff(100, 35, 20))
            .citizen(citiz)
            .citizen(createTeenager(50, 14))
            .citizen(citiz)
            .build();

    auto status = smallTown.getStatus();

    assert(status.getMonsterName() == "GroupOfMonsters");
    assert(status.getMonsterHealth() == 140);
    assert(status.getAliveCitizens() == 3);

    smallTown.tick(18);
    smallTown.tick(3);

    status = smallTown.getStatus();

    assert(status.getMonsterName() == "GroupOfMonsters");
    assert(status.getMonsterHealth() == 80);
    assert(status.getAliveCitizens() == 3);

    std::cout << "OK!\n";

    return 0;
}
