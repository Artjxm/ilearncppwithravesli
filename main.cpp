#include "chapter14/Fraction.h"

int main() {
    std::cout << "Enter the numerator:";
    int numerator;
    std::cin >> numerator;

    std::cout << "Enther the denominator:";
    int denominator;
    std::cin >> denominator;

    try {
        Fraction fraction(numerator, denominator);
        fraction.print();
    } catch (std::exception &exception) {
        std::cout << exception.what();
    }

    return 0;
}

/*
 *
*/
