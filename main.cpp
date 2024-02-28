#include <iostream>

template<class T, int size>
class StaticArray {
    T m_array[size];

public:
    T* getArray();

    T& operator[](int index) { return m_array[index]; }
};

template<class T, int size>
T* StaticArray<T, size>::getArray() {
    return m_array;
}

int main() {
    StaticArray<int, 10> intArr;

    for (int i = 0; i < 10; ++i) intArr[i] = i;

    for (int i = 9; i >= 0; --i) std::cout << intArr[i] << ' ';
    std::cout << '\n';

    StaticArray<double, 5> doubleArr;

    for (int i = 0; i < 5; ++i) doubleArr[i] = 5.5 + .1 * i;

    for (int i = 0; i < 5; ++i) std::cout << doubleArr[i] << ' ';
}

/*
 *
*/
