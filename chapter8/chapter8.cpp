#include "chapter8.h"

#include <iostream>

#include "Point.h"

void chapter8Task1() {
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}

void chapter8() {
    chapter8Task1();
}
