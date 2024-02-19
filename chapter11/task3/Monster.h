#ifndef MONSTER_H
#define MONSTER_H
#include "Creature.h"


class Monster : public Creature {
    struct MonsterData {
        const char *name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

public:
    enum MonsterType {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    static MonsterData monsterData[MAX_TYPES];

    explicit Monster(MonsterType type) : Creature(monsterData[type].name,
                                                  monsterData[type].symbol,
                                                  monsterData[type].health,
                                                  monsterData[type].damage,
                                                  monsterData[type].gold) {}

    static Monster getRandomMonster();
};

#endif //MONSTER_H
