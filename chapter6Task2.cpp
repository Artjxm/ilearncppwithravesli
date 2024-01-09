
#include "chapter6Task2.h"

struct Student {
    std::string name;
    int mark{};
};

void insertStudents(Student *students, const int &totalStudents) {
    for (int i = 0; i < totalStudents; ++i) {
        std::string newName;
        std::cin >> newName;
        (students+i)->name = newName;
        int newMark;
        std::cin >> newMark;
        (students+i)->mark = newMark;
    }
}

void sortStudents(Student *students, const int &totalStudents) {
    for (int startIndex = 0; startIndex < totalStudents - 1; ++startIndex) {
        int highestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < totalStudents; ++currentIndex) {
            if ((students + currentIndex)->mark > (students + highestIndex)->mark)
                highestIndex = currentIndex;
        }
        std::swap(students[startIndex], students[highestIndex]);
    }
}

void printStudents(const Student *students, const int &totalStudents) {
    for (int i = 0; i < totalStudents; ++i)
        std::cout << (students+i)->name << " has " << (students+i)->mark << '\n';
}

void chapter6Task2() {
    std::cout << "How many students do you want to enter?";
    int totalStudents;
    std::cin >> totalStudents;

    auto *students = new Student[totalStudents];

    insertStudents(students, totalStudents);
    sortStudents(students, totalStudents);
    printStudents(students, totalStudents);

    delete[] students;
    students = nullptr;
}
