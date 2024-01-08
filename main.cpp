#include <algorithm>

#include "chapter5Task1.h"
#include "chapter5Task2.h"

void chapter5() {
    chapter5Task1();
    chapter5Task2();
}

int getNameAmount() {
    std::cout << "How many names would you like to enter?";
    int namesCounter;
    std::cin >> namesCounter;
    return namesCounter;
}

void insertNames(std::string *names, const int namesCounter) {
    std::string newName("hello");
    for (int counter = 0; counter < namesCounter; ++counter) {
        std::cout << "Enter name #" << counter + 1 << ':';
        std::cin >> names[counter];
    }
}

void sortNames(std::string *names, const int namesCounter) {
    for (int startIndex(0); startIndex < namesCounter - 1; ++startIndex) {
        int smallestIndex = startIndex;
        for (int currentIndex(startIndex + 1); currentIndex < namesCounter; ++currentIndex) {
            if (names[currentIndex] < names[smallestIndex])
                smallestIndex = currentIndex;
        }
        std::swap(names[startIndex], names[smallestIndex]);
    }
}

void sortNames2(std::string *names, const int namesCounter) {
    std::sort(names, names+namesCounter);
}

void printNames(std::string *names, const int namesCounter) {
    std::cout << "\nHere is your sorted list:\n";
    for (int counter = 0; counter < namesCounter; ++counter) {
        std::cout << "Name #" << counter + 1 << ':' << names[counter] << '\n';
    }
}

int main()
{
    const int namesCounter(getNameAmount());

    std::string *names = new std::string[namesCounter];

    insertNames(names, namesCounter);
    sortNames(names, namesCounter);
    printNames(names, namesCounter);

    delete[] names;
    names = nullptr;

    return 0;
}

/*

*/
