#include "chapter7Task3binarySearch.h"

// функция поиска центрального числа, использована такая версия вместо
// "max + min / 2" для избежания возможного переполнения
int average(int min, int max) {
    return min + (max - min) / 2;
}

// вспомогательная функция поиска наименьшей степени двойки, превышающей число
int maxIteration(const int value) {
    int power(1), sought(0);
    while (true) {
        if (power >= value) return sought;
        power <<= 1;
        ++sought;
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
        int avg = average(min, max);
        if (array[avg] > target) max = avg;
        else if (array[avg] < target) min = avg;
        else return avg;
    }
    return -1;
}

void chapter7Task3binarySearch() {
    int array[] = {4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50};

    std::cout << "Enter a number:";
    int x;
    std::cin >> x;

    const int index = binarySearchIterative(array, x, 0, 14);

    if (array[index] == x && index != -1)
        std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
    else
        std::cout << "Fail! Your value " << x << " isn't in array!\n";
}
