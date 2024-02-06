#include "FixedPoint.h"
#include <istream>
#include <cmath>

std::ostream &operator<<(std::ostream &out, const FixedPoint &value) {
    out << static_cast<double>(value);

    return out;
}

FixedPoint operator+(const FixedPoint &first, const FixedPoint &second) {
    return FixedPoint(static_cast<double>(first) + static_cast<double>(second));
}

std::istream &operator>>(std::istream &in, FixedPoint &value) {
    double d;
    in >> d;
    value = FixedPoint(d);

    return in;
}

FixedPoint::FixedPoint(const double dValue) {
    m_whole = static_cast<int16_t>(dValue);
    m_frac = static_cast<int8_t>(round((dValue - m_whole) * 100));
}

void FixedPoint::setSign() {
    if (m_whole < 0.0 || m_frac < 0.0) {
        if (m_whole > 0.0) {
            m_whole = -m_whole;
        }
        if (m_frac > 0.0) {
            m_frac = -m_frac;
        }
    }
}

FixedPoint FixedPoint::operator-() const {
    return FixedPoint(-m_whole, -m_frac);
}

bool operator==(const FixedPoint &first, const FixedPoint &second) {
    return first.m_whole == second.m_whole && first.m_frac == second.m_frac;
}

FixedPoint::operator double() const {
    return m_whole + static_cast<double>(m_frac) / 100;
}
