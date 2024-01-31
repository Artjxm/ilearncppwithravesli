#ifndef MONSTER_H
#define MONSTER_H
#include <string>


class Monster {
public:
    enum MonsterType {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_monsterType;
    std::string m_name{};
    int m_hp{ 1 };

    std::string getTypeString() const;

public:
    Monster(MonsterType monsterType, std::string name, int hp) : m_monsterType(monsterType),
                                                                 m_name(name),
                                                                 m_hp(hp) {}

    void print() const;
};


#endif //MONSTER_H
