#ifndef PAIR_H
#define PAIR_H

template<class T, class T2>
class Pair {
    T m_a;
    T2 m_b;

public:
    Pair(const T& value1, const T& value2) : m_a(value1), m_b(value2) {}

    T& first() { return m_a; }
    T2& second() { return m_b; }
};


#endif //PAIR_H
