
#include "chapter6Task4.h"

void printCStyleString(const char *strPtr) {
    while (*strPtr != '\0') {
        std::cout << *strPtr;
        ++strPtr;
    }
}

void chapter6Task4() {
    const char myString[] = {"Hello, world!"};

    printCStyleString(myString);
}