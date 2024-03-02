#include <iostream>

#include "chapter13/Pair.h"

int main() {
    Pair<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

/*
 *
*/
