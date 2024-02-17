#ifndef FRUIT_H
#define FRUIT_H
#include <string>


class Fruit {
protected:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string name, std::string color) : m_name(name), m_color(color) {}

    std::string getColor() const { return m_color; }
    std::string getName() const { return m_name; }
};

#endif //FRUIT_H
