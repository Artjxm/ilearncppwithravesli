#include "chapter9.h"
#include <iostream>
#include "Average.h"
#include "FixedPoint.h"
#include "IntArray.h"

void chapter9Task2() {
    Average avg;

    avg += 5;
    std::cout << avg << '\n'; // 5 / 1 = 5

    avg += 9;
    std::cout << avg << '\n'; // (5 + 9) / 2 = 7

    avg += 19;
    std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

    avg += -9;
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

    (avg += 7) += 11; // выполнение цепочки операций
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

    Average copy = avg;
    std::cout << copy << '\n';
}

IntArray fillArray() {
    IntArray a(6);
    a[0] = 6;
    a[1] = 7;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 8;

    return a;
}

void chapter9Task3() {
    IntArray a = fillArray();
    std::cout << a << '\n';

    IntArray b(1);
    a = a;
    b = a;

    std::cout << b << '\n';
}

void SomeTest() {
    std::cout << std::boolalpha;
    std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) <<
            '\n'; // оба значения положительные, никакого переполнения
    std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) <<
            '\n'; // оба значения положительные, переполнение
    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) <<
            '\n'; // оба значения отрицательные, никакого переполнения
    std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) <<
            '\n'; // оба значения отрицательные, переполнение
    std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) <<
            '\n'; // второе значение отрицательное, никакого переполнения
    std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) <<
            '\n'; // второе значение отрицательное, возможно переполнение
    std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) <<
            '\n'; // первое значение отрицательное, никакого переполнения
    std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) <<
            '\n'; // первое значение отрицательное, возможно переполнение
}

void chapter9Task4() {
    SomeTest();

    FixedPoint a(-0.48);
    std::cout << a << '\n';

    std::cout << -a << '\n';

    // std::cout << "Enter a number: "; // введите 5.678
    // std::cin >> a;
    //
    // std::cout << "You entered: " << a << '\n';
}


void chapter9() {
    // chapter9Task2();
    // chapter9Task3();
    chapter9Task4();
}
