#include <cassert>

#include "chapter5/chapter5Task1.h"
#include "chapter5/chapter5Task2.h"
#include "chapter6/chapter6Task1.h"
#include "chapter6/chapter6Task2.h"
#include "chapter6/chapter6Task3.h"
#include "chapter6/chapter6Task4.h"
#include "chapter6/chapter6Task6.h"
#include "chapter7/calculatorUsingFunctionPointers.h"
#include "chapter7/chapter7Task3binarySearch.h"

void chapter5() {
    chapter5Task1();
    chapter5Task2();
}

void chapter6() {
    chapter6Task1();
    chapter6Task2();
    chapter6Task3();
    chapter6Task4();
    chapter6Task6();
}

void chapter7() {
    calculatorUsingFunctionPointers();
    chapter7Task3binarySearch();
}

class Stack {
    int m_array[10];
    int m_length{0};

public:
    void reset() {
        m_length = 0;
        for (auto&i: m_array) {
            i = 0;
        }
    }

    bool push(const int value) {
        if (m_length == 10)
            return false;

        m_array[m_length++] = value;
        return true;
    }

    int pop() {
        assert(m_length > 0 && "Error trying to pop an element from empty stack");
        return m_array[--m_length];
    }

    void print() {
        std::cout << "( ";
        for (int i = 0; i < m_length; ++i)
            std::cout << m_array[i] << ' ';
        std::cout << ")\n";
    }
};

int main() {
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}

/*
 *
*/
