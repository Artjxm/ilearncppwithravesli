#include <iostream>

#include "Timer.h"

template<class T>
class DynamicArray {
    T* m_array;
    int m_length;

public:
    DynamicArray(int length) : m_array(new T[length]), m_length(length) {}

    ~DynamicArray() { delete[] m_array; }

    DynamicArray(const DynamicArray& arr) = delete;

    DynamicArray& operator=(const DynamicArray& arr) = delete;

    DynamicArray(DynamicArray&& arr)  noexcept : m_array(arr.m_array), m_length(arr.getLength()) {
        arr.m_length = 0;
        arr.m_array = nullptr;
    }

    DynamicArray& operator=(DynamicArray&& arr)  noexcept {
        if (&arr == this) return *this;

        delete[] m_array;

        m_length = arr.getLength();
        m_array = arr.m_array;

        arr.m_length = 0;
        arr.m_array = nullptr;

        return *this;
    }

    int getLength() const { return m_length; }
    T& operator[](int index) { return m_array[index]; }
    const T& operator[](int index) const { return m_array[index]; }
};

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr) {
    DynamicArray<int> dbl(arr.getLength());
    for (int i(0); i < arr.getLength(); ++i) dbl[i] = arr[i] * 2;

    return dbl;
}

int main() {
    Timer t;

    DynamicArray<int> arr(100'000);

    for (int i = 0; i < arr.getLength(); i++) arr[i] = i;

    arr = cloneArrayAndDouble(arr);

    std::cout << t.elapsed();

    return 0;
}
