#ifndef PAIR_H
#define PAIR_H

template<class T>
class Pair {
    T m_pair[2];

public:
    Pair(const T& value1, const T& value2) {
        m_pair[0] = value1;
        m_pair[1] = value2;
    }

    T& first() { return m_pair[0]; }
    T& second() { return m_pair[1]; }
};


#endif //PAIR_H
