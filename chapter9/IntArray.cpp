#include "IntArray.h"
#include <cassert>

IntArray::IntArray(const IntArray &source) : m_length(source.m_length) {
    if (source.m_data) {
        m_data = new int[m_length];

        for (int i = 0; i < m_length; ++i) m_data[i] = source.m_data[i];
    }
    else m_data = nullptr;
}

IntArray &IntArray::operator=(const IntArray &source) {
    m_length = source.m_length;
    // проверка на самоприсваивание
    if (this == &source) return *this;

    // удаление предыдущие данные для предотвращения утечки памяти
    delete[] m_data;

    if (source.m_data) {
        m_data = new int[m_length];

        for (int i = 0; i < m_length; ++i) m_data[i] = source.m_data[i];
    }
    else m_data = nullptr;

    return *this;
}

int &IntArray::operator[](const int index) {
    assert(index >= 0 && index < m_length);

    return m_data[index];
}

std::ostream &operator<<(std::ostream &out, const IntArray &arr) {
    for (int i = 0; i < arr.m_length; ++i) out << arr.m_data[i] << ' ';

    return out;
}
