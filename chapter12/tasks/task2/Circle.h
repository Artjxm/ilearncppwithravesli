#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include "Shape.h"

class Circle : public Shape {
    Point m_point;
    int m_radius;

    std::ostream &print(std::ostream &out) const override {
        out << "Circle(" << m_point << ", radius " << m_radius << ")";
        return out;
    }

public:
    Circle(Point point, int radius = 0) : m_point(point), m_radius(radius) {}
    int getRadius() const { return m_radius; }
};


#endif //CIRCLE_H
