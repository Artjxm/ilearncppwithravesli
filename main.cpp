#include <iostream>
#include "chapter12/tasks/task2/Circle.h"
#include "chapter12/tasks/task2/Triangle.h"
#include <vector>

int getLargestRadius(const std::vector<Shape *> &v) {
    int maxRadius(-1);

    for (const auto &element: v) {
        auto *circle = dynamic_cast<Circle *>(element);
        if (circle) if (circle->getRadius() > maxRadius) maxRadius = circle->getRadius();
    }

    return maxRadius;
}

int main() {
    std::vector<Shape *> v;
    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 3));

    for (const auto &element: v) std::cout << *element << '\n';

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

    for (const auto &element: v) delete element;
}

/*
 *
*/
