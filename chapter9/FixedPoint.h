#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H
#include <cstdint>
#include <ostream>


class FixedPoint {
    using wholeType = std::int16_t;
    using fracType = std::int8_t;
    wholeType m_whole;
    fracType m_frac;

public:
    FixedPoint(wholeType whole = 0, fracType frac = 0) : m_whole(whole), m_frac(frac) {
        setSign();
    }

    FixedPoint(double dValue);

    void setSign();

    friend std::ostream &operator<<(std::ostream &out, const FixedPoint &value);

    friend std::istream &operator>>(std::istream &in, FixedPoint &value);

    FixedPoint operator-() const;

    friend bool operator==(const FixedPoint &first, const FixedPoint &second);

    friend FixedPoint operator+(const FixedPoint &first, const FixedPoint &second);

    explicit operator double() const;
};


#endif //FIXEDPOINT_H
