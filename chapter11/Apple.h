
#ifndef APPLE_H
#define APPLE_H
#include "Fruit.h"


class Apple : public Fruit {

public:
    explicit Apple(std::string color = "red") : Fruit("apple", color) {}

    Apple(std::string name, std::string color) : Fruit(name, color) {}
};



#endif //APPLE_H
