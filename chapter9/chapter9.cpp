#include "chapter9.h"
#include <iostream>
#include "Average.h"
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

IntArray fillArray()
{
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


void chapter9() {
    // chapter9Task2();
    chapter9Task3();
}
