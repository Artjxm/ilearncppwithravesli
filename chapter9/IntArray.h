#ifndef INTARRAY_H
#define INTARRAY_H
#include <ostream>


class IntArray {
    int *m_data;
    int m_length;

public:
    explicit IntArray(const int length = 0) : m_length(length) {
        m_data = new int[m_length];
    }

    IntArray(const IntArray &source);

    IntArray &operator=(const IntArray &source);

    friend std::ostream &operator<<(std::ostream &out, const IntArray &arr);

    int &operator[](int index);

    ~IntArray() {
        delete[] m_data;
    }
};


#endif //INTARRAY_H
