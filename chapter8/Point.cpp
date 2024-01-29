#include "Point.h"

#include <iostream>

void Point::print() const {
    std::cout << "Point(" << m_a << ", " << m_b << ")\n";
}

double distanceFrom(const Point &one, const Point &other) {
    return sqrt((one.m_a - other.m_a) * (one.m_a - other.m_a) +
                (other.m_b - one.m_b) * (other.m_b - one.m_b));
}
