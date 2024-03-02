#include <iostream>

template<class T>
class Repository {
    T m_value;

public:
    Repository(T value) : m_value(value) {}

    ~Repository() {}

    void print() { std::cout << m_value << ' '; }
};

template<class T>
class Repository<T*> {
    T* m_value;

public:
    Repository(T* value) { m_value = new T(*value); }

    ~Repository() { delete[] m_value; }

    void print() { std::cout << *m_value << '\n'; }
};

template<>
Repository<char*>::Repository(char* value) {
    int length = 0;

    while (value[length] != '\0') ++length;
    ++length;

    m_value = new char[length];

    for (int i = 0; i < length; ++i) m_value[i] = value[i];
}

template<>
Repository<char*>::~Repository() { delete[] m_value; }

template<>
void Repository<char*>::print() {
    std::cout << m_value;
}

int main() {
    Repository<int> myint(6);
    myint.print();

    int x(8);
    Repository<int*> myintptr(&x);

    x = 222;
    myintptr.print();

    char* name = new char[40]{ "Bebra" };

    Repository<char*> myname(name);

    delete[] name;

    myname.print();

    return 0;
}

/*
 *
*/
