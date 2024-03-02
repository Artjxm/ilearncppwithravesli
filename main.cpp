#include <iostream>

#include "chapter13/Pair.h"

int main() {
    StringValuePair<int> svp("Amazing", 7);

    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    StringValuePair<double> svp2("Mild", 2.5);

    std::cout << "Pair: " << svp2.first() << ' ' << svp2.second() << '\n';

    return 0;
}

/*
 *
*/
