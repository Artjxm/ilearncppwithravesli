#include "chapter11.h"

#include <iostream>

#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"

void chapter11Task2() {
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

void chapter11Task3() {}

void chapter11() {
    chapter11Task2();
}
