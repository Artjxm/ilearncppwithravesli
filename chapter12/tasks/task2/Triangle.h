#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include "Point.h"


class Triangle : public Shape {
    Point m_pointX, m_pointY, m_PointZ;

    std::ostream &print(std::ostream &out) const override {
        out << "Triangle(" << m_pointX << ", " << m_pointY << ", " << m_PointZ << ")";
        return out;
    }

public:
    Triangle(Point x, Point y, Point z) : m_pointX(x), m_pointY(y), m_PointZ(z) {}
};


#endif //TRIANGLE_H
