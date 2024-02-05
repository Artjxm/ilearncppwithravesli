#include "Average.h"
Average & Average::operator+=(const int value) {
    ++m_amount;
    m_sum += value;

    return *this;
}

std::ostream & operator<<(std::ostream &out, const Average &average) {
    out << average.m_sum / average.m_amount;

    return out;
}
