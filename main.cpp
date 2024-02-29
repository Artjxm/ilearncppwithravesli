#include <iostream>

template<class T>
class Repository {
    T m_value;

public:
    Repository(T value) : m_value(value) {}

    ~Repository() {}

    void print() {
        std::cout << m_value << '\n';
    }
};

template<>
void Repository<double>::print() {
    std::cout << std::scientific << m_value << '\n';
}

template<>
void Repository<int>::print() {
    std::cout << "Int value: " << m_value << '\n';
}

template<>
void Repository<char*>::print() {
    std::cout << "You entered: " << m_value << '\n';
}

// Выполняем глубокое копирование, чтобы получить значение строки, а не просто указатель
template<>
Repository<char*>::Repository(char* value) {
    int length(0);

    while (value[length] != '\0') ++length;
    ++length;

    m_value = new char[length];

    for (int count = 0; count < length; ++count) m_value[count] = value[count];
}

template<>
Repository<char*>::~Repository() { delete[] m_value; }

int main() {
    Repository nValue(5);

    Repository dValue(2.5);

    nValue.print();
    dValue.print();

    char *str = new char[40];
    std::cin >> str;

    Repository repo(str);
    delete[] str;

    repo.print();
}

/*
 *
*/
