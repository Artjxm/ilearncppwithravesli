#ifndef POINT_H
#define POINT_H
#include <cmath>


class Point {
    double m_a;
    double m_b;

public:
    Point(const double a = 0.0, const double b = 0.0) : m_a{ a }, m_b{ b } {}

    void print() const;

    friend double distanceFrom(const Point &one, const Point &other);
};


#endif //POINT_H
