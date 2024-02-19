#include "Monster.h"

#include "../../URNG.h"

Monster::MonsterData Monster::monsterData[MAX_TYPES]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

Monster Monster::getRandomMonster() {
    int monsterID = URNG(0,2);

    return Monster(static_cast<MonsterType>(monsterID));
}
