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

struct Season {
    std::string_view name{};
    double averageTemperature{};
};

int main() {
    std::array<Season, 4> seasons{
        {
            { "Spring", 285.0 },
            { "Summer", 296.0 },
            { "Fall", 288.0 },
            { "Winter", 263.0 }
        }
    };

    std::sort(seasons.begin(), seasons.end(),
              [](const auto &a, const auto &b) {
                  return a.averageTemperature < b.averageTemperature;
              });

    for (const auto &season: seasons) {
        std::cout << season.name << '\n';
    }

    return 0;
}

/*
 *
*/
