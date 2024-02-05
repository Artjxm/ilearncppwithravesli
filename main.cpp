#include "headers.h"
#include <cassert>
#include <cstring>

class SomeString {
    char *m_data;
    int m_length;

public:
    // default constructor
    SomeString(const char *source = "") {
        assert(source);

        m_length = strlen(source) + 1;

        for (int i = 0; i < m_length; ++i) m_data[i] = source[i];

        m_data[m_length + 1] = '\0';
    }

    // copy constructor
    SomeString(const SomeString &source) {
        m_length = source.m_length;

        if (source.m_data) {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else m_data = nullptr;
    }

    SomeString &operator=(const SomeString &source);

    ~SomeString() {
        delete[] m_data;
    }

    char *getString() { return m_data; }
    int getLength() { return m_length; }
};

SomeString &SomeString::operator=(const SomeString &source) {
    if (this == &source)
        return *this;

    delete[] m_data;

    m_length = source.m_length;

    if (source.m_data) {
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else m_data = nullptr;

    return *this;
}

int main() {
    return 0;
}

/*
 *
*/
