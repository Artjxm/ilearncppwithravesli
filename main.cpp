#include <iostream>
#include <memory>

class Fraction {
    int m_numerator = 0;
    int m_denominator = 1;

public:
    explicit Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator),
                                                       m_denominator(denominator) {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }
};

void printFraction(const Fraction* const ptr) {
    if (ptr) std::cout << *ptr;
}

int main() {
    const auto ptr(std::make_unique<Fraction>(7, 9));

    printFraction(ptr.get());

    return 0;
}

/*
 * Задание №1:
 * В данном случае умный указатель не сможет предотвратить очистку памяти, если сам будет
 * некорректно удален
 * Ответ автора: Умные указатели в качестве членов класса удаляют свой ресурс только в том случае,
 * если объект класса выходит из области видимости. Если мы выделим объект класса динамически и не
 * удалим его должным образом, то объект класса никогда не выйдет из области видимости, и умный
 * указатель не сможет очистить ресурс, который он хранит.
 */
