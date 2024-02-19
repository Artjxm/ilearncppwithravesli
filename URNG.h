#ifndef URNG_H
#define URNG_H
#include <random>


class URNG {
    int m_min;
    int m_maxIncl;
    int m_randValue;

public:
    URNG(int min, int maxIncl) : m_min(min), m_maxIncl(maxIncl) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution dist(m_min, m_maxIncl);
        m_randValue = dist(mt);
    }

    // Конструктор по умолчанию генерит случайное число от 0 до 100 включительно
    URNG() : URNG(0, 100) {}

    // Перегрузка оператора и для rollTheDice (int) и для flipTheCoin (bool)
    operator int() const {
        return m_randValue;
    }

    // Статические методы выводят одинаковое значение, поэтому используется объект класса URNG
    int rollTheDice(int sides) { return URNG(1, sides); }

    bool flipTheCoin() { return URNG(0, 1); }
};


#endif //URNG_H
