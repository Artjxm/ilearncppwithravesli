#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class Fraction {
    int m_numerator;
    int m_denominator;

public:
    Fraction(const int num = 0, const int denom = 1) : m_numerator(num), m_denominator(denom) {
        if (!m_denominator) throw std::runtime_error("Your fraction has and invalid denominator.");
    }

    void print() { std::cout << "Fraction: " << m_numerator << '/' << m_denominator << '\n'; }
};


#endif //FRACTION_H
