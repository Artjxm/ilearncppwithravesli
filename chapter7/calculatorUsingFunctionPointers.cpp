
#include "calculatorUsingFunctionPointers.h"

int getValue() {
    std::cout << "Enter an integer:";
    int value;
    std::cin >> value;
    return value;
}

char getOperation() {
    char op;
    do {
        std::cout << "Enter a valid operation (+, -, *, /):";
        std::cin >> op;
    }
    while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(const int a, const int b) {
    return a + b;
}

int subtract(const int a, const int b) {
    return a - b;
}

int multiply (const int a, const int b) {
    return a * b;
}

int divide(const int a, const int b) {
    return a / b;
}

// type alias для страшного синтаксиса инициализации указателя на функцию
using arithmeticFn = int (*)(int, int);

struct arithmeticStruct {
    char op;
    arithmeticFn fn;
};

// реализация через std::array
// сделал и ее, потому что думал, что фиксированный массив не будет работать
// в цикле foreach из-за указателя, но видимо static меняет дело, массив ведь
// не передан в функцию через указатель, а взят напрямую из глобальной области видимости
static std::array<arithmeticStruct, 4> arithmeticArray{
        {
            {'+', add},
            {'-', subtract},
            {'*', multiply},
            {'/', divide}
        }
};

// реализация через фиксированный массив
// static arithmeticStruct arithmeticArray[]{
//     {'+', add},
//     {'-', subtract},
//     {'*', multiply},
//     {'/', divide}
// };

arithmeticFn getArithmeticFn(char op) {
    for (const auto &i : arithmeticArray) {
        if (i.op == op)
            return i.fn;
    }

    // функция по умолчанию
    return add;
}

void calculatorUsingFunctionPointers() {
    const int a = getValue();
    const char op = getOperation();
    const int b = getValue();

    const arithmeticFn fn = getArithmeticFn(op);
    std::cout << a << ' ' << op << ' ' << b << " = " << fn(a, b) << '\n';
}