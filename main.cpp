#include "chapter5/chapter5Task1.h"
#include "chapter5/chapter5Task2.h"
#include "chapter6/chapter6Task1.h"
#include "chapter6/chapter6Task2.h"
#include "chapter6/chapter6Task3.h"
#include "chapter6/chapter6Task4.h"
#include "chapter6/chapter6Task6.h"
#include "chapter7/calculatorUsingFunctionPointers.h"
#include "chapter7/chapter7Task3binarySearch.h"
#include <algorithm>
#include <cstring>
#include <functional>

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

struct Student {
    std::string name;
    int score;
};

// И обычные функции справляются вроде...
bool less4(const Student &a, const Student &b) {
    return a.score < b.score;
}

int main() {
    std::array<Student, 8> arr{
        {
            { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 }, // Dan имеет больше всего баллов (8)
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 }
        }
    };

    // Первая версия
    bool (*less)(const Student &, const Student &){
        [](const Student &a, const Student &b) {
            return (a.score < b.score);
        }
    };

    // Вторая версия
    std::function less2{
        [](const Student &a, const Student &b) {
            return (a.score < b.score);
        }
    };

    // Третья версия
    auto less3{
        [](const Student &a, const Student &b) {
            return (a.score < b.score);
        }
    };

    // Вложенная лямбда
    // const auto bestStudentIndex{
    //     std::max_element(arr.begin(),
    //                      arr.end(),
    //                      [](const Student &a, const Student &b) {
    //                          return (a.score < b.score);
    //                      })
    // };

    // С применением одной из четырех* лямбда-переменных
    const auto bestStudentIndex{
        std::max_element(arr.begin(),
                         arr.end(),
                         less4)
    };

    std::cout << bestStudentIndex->name << " is the best student";

    return 0;
}

/*
 *
*/
