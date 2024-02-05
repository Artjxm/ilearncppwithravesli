#ifndef AVERAGE_H
#define AVERAGE_H
#include <cstdint>
#include <ostream>


class Average {
    int32_t m_sum = 0;
    int8_t m_amount = 0;

public:
    // конструктор по умолчанию может справиться сам
    // explicit Average() {}

    friend std::ostream &operator<<(std::ostream &out, const Average &average);
    Average &operator+=(int value);

    // оператор присвоения по умолчанию может справиться сам
    // Average &operator=(const Average &source);
};


#endif //AVERAGE_H
