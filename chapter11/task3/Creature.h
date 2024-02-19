#ifndef CREATURE_H
#define CREATURE_H
#include <string>


class Creature {
protected:
    std::string m_name;
    char m_symbol;
    int m_healthPoints;
    int m_damage;
    int m_gold;

public:
    Creature(std::string name, char symbol, int hp, int dmg, int gold) : m_name(name),
        m_symbol(symbol), m_healthPoints(hp), m_damage(dmg), m_gold(gold) {}

    std::string getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_healthPoints; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int damage) { m_healthPoints -= damage; }
    bool isDead() const { return m_healthPoints <= 0; }
    void addGold(int gold) { m_gold += gold; }
};


#endif //CREATURE_H
