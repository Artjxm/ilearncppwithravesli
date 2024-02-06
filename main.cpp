#include "headers.h"

class Car {
    std::string m_name;
    int m_id;

public:
    Car(std::string name, int id) : m_name(name), m_id(id) {}

    std::string getName() { return m_name; }
    int getId() { return m_id; }
};

class Carlot {
    static Car s_carLot[4];

public:
    Carlot() = delete;

    static Car *getCar(int id) {
        for (auto &count: s_carLot) if (count.getId() == id) return &count;

        return nullptr;
    }
};

Car Carlot::s_carLot[4] = {
    Car("Camry", 3),
    Car("Honda", 4),
    Car("Focus", 6),
    Car("Mercedes", 3)
};

class Driver {
    std::string m_name;
    int m_carId;

public:
    Driver(std::string name, int carId) : m_name(name), m_carId(carId) {}

    std::string getName() { return m_name; }
    int getCarId() { return m_carId; }
};

int main() {
    Driver d("Oleg", 3);

    Car *car = Carlot::getCar(d.getCarId());

    if (car) std::cout <<  d.getName() << " is driving a " << car->getName() << '\n';
    else std::cout <<  d.getName() << " couldn't find his car\n";

    return 0;
}

/*
 *
*/
