#include "chapter7Task3binarySearch.h"

// функция поиска центрального числа, использована такая версия вместо
// "max + min / 2" для избежания возможного переполнения
int average(int min, int max) {
    return min + (max - min) / 2;
}

// вспомогательная функция поиска наименьшей степени двойки, превышающей число
int maxIteration(const int value) {
    int power(1), notFound(0);
    while (true) {
        if (power >= value) return notFound;
        power <<= 1;
        ++notFound;
    }
}

// array - это массив, в котором мы проводим поиски.
// target - это искомое значение.
// min - это индекс минимальной границы массива, в котором мы осуществляем поиск.
// max - это индекс максимальной границы массива, в котором мы осуществляем поиск.
// Функция binarySearch() должна возвращать индекс искомого значения, если он обнаружен.
// в противном случае, возвращаем -1
int binarySearchIterative(int* array, int target, int min, int max) {
    if (target < array[min] || target > array[max])
        return -1;

    // Находим максимальное возможное число итераций для поиска значения
    int max_i = maxIteration(max - min + 1);

    for (int i = min; i < max_i; ++i) {
        int midPoint = average(min, max);
        if (array[midPoint] > target) max = midPoint;
        else if (array[midPoint] < target) min = midPoint;
        else return midPoint;
    }
    return -1;
}

int binarySearchRecursive(int* array, const int target, const int min, const int max) {
    int notFound(-1);

    // проверка искомого вне диапазона массива
    if (target < array[min] || target > array[max])
        return notFound;

    const int midPoint = average(min, max);

    if (array[midPoint] > target) return binarySearchRecursive(array, target, min, midPoint - 1);
    else if (array[midPoint] < target) return binarySearchRecursive(array, target, midPoint + 1, max);
    else if (array[midPoint] == target) return midPoint;
    else return notFound;
}

// авто-тест работы функции, а то лень вводить каждый раз
void test(int* array) {
    int testArr[]{3, 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 45, 47, 50, 51};

    for (const auto&i: testArr) {
        const int index = binarySearchRecursive(array, i, 0, 14);
        if (array[index] == i && index != -1)
            std::cerr << i << ":\tpassed.";
        else
            std::cerr << i << ":\tfailed";

        if (i == 3 || i == 45 || i == 51)
            std::cerr << " as it should be.";

        std::cerr << '\n';
    }
}

void chapter7Task3binarySearch() {
    int array[] = {4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50};

    // std::cout << "Enter a number:";
    // int x;
    // std::cin >> x;

    // const int index = binarySearchRecursive(array, x, 0, 14);

    // if (array[index] == x && index != -1)
    //     std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
    // else
    //     std::cout << "Fail! Your value " << x << " isn't in array!\n";

    test(array);
}
