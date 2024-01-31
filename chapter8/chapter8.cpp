#include "chapter8.h"

#include <iostream>

#include "Point.h"
#include "Welcome.h"
#include "Monster.h"
#include "MonsterGenerator.h"

void chapter8Task1() {
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}

void chapter8Task2() {
    Welcome hello;
    hello.print();
}

// генерим тысячу случайных монстров
void chapter8Task3() {
    for (auto i = 0; i < 1000; ++i) {
        Monster monster = MonsterGenerator::generateMonster();
        monster.print();
    }
}


void chapter8() {
    // chapter8Task1();
    // chapter8Task2();
    chapter8Task3();
}
