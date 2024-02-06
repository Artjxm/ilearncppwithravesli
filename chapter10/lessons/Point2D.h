#ifndef POINT2D_H
#define POINT2D_H
#include <ostream>


class Point2D {
    int m_x;
    int m_y;

public:
    Point2D() : m_x(0), m_y(0) {}

    Point2D(const int  x, const int y) : m_x(x), m_y(y) {}

    friend std::ostream &operator<<(std::ostream &out, const Point2D &point) {
        out << "(" << point.m_x << ", " << point.m_y << ")";
        return out;
    }

    void setPoint(const int x, const int y) {
        m_x = x;
        m_y = y;
    }


};


#endif //POINT2D_H
