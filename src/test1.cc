#include "citizen.h"
#include "monster.h"
#include "smalltown.h"

int main(int argc, const char * argv[]) {
    auto groupOfMonsters = createGroupOfMonsters({
                                                         createMummy(90, 15),
                                                         createZombie(120, 15),
                                                         createVampire(30, 15)
                                                 });
    auto smallTown = SmallTown::Builder()
            .monster(groupOfMonsters)
            .startTime(10)
            .maxTime(20)
            .citizen(createSheriff(100, 20, 35))
            .citizen(createAdult(100, 21))
            .citizen(createTeenager(50, 14))
            .build();

    smallTown.tick(0);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);

    auto status = smallTown.getStatus();
    assert(status.getMonsterName() == "GroupOfMonsters");
    assert(status.getAliveCitizens() == 2);
    assert(status.getMonsterHealth() == 70);
    return 0;
}
