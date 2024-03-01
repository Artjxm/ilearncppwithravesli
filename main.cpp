#include <iostream>

template<class T>
class Repository8 {
    T m_array[8];

public:
    void set(int index, const T& value) { m_array[index] = value; }

    T& get(int index) { return m_array[index]; }
};

template<>
class Repository8<bool> {
    unsigned char m_data;

public:
    Repository8() : m_data(0) {}

    void set(int index, bool value) {
        unsigned char mask = 1 << index;

        if (value)
            m_data |= mask;
        else
            m_data &= ~mask;
    }

    bool get(int index) {
        unsigned char mask = 1 << index;

        return (m_data & mask) != 0;
    }
};

int main() {
    Repository8<int> intRepository;

    for (int count=0; count<8; ++count)
        intRepository.set(count, count);

    for (int count=0; count<8; ++count)
        std::cout << intRepository.get(count) << '\n';

    Repository8<bool> boolRepository;

    for (int count=0; count<8; ++count)
        boolRepository.set(count, count % 5);

    for (int count=0; count<8; ++count)
        std::cout << (boolRepository.get(count) ? "true" : "false") << '\n';

    return 0;
}

/*
 *
*/
