#ifndef SHAPE_H
#define SHAPE_H
#include <ostream>


class Shape {
public:
    virtual std::ostream &print(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Shape &shape) {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};


#endif //SHAPE_H
