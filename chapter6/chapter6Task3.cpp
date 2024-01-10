
#include "chapter6Task3.h"

void mySwap(int &value1, int &value2) {
    const int temp(value1);
    value1 = value2;
    value2 = temp;
}

void chapter6Task3() {
    int value1(3), value2(5);
    std::cout << value1 << ' ' << value2 << std::endl;
    mySwap(value1, value2);
    std::cout << value1 << ' ' << value2 << std::endl;
}
