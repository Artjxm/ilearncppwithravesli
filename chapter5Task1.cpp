
#include "chapter5Task1.h"

double getInitialHeight()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;
    return initialHeight;
}

double calculateHeight(double initialHeight, int seconds)
{
    // Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
    double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
    double currentHeight = initialHeight - distanceFallen;

    return currentHeight;
}

// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(double height, int seconds)
{
    if (height > 0.0)
    {
        std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
            " meters\n";
    }
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(double initialHeight, int seconds)
{
    double height = calculateHeight(initialHeight, seconds);
    printHeight(height, seconds);
}

void chapter5Task1() {
    const double initialHeight = getInitialHeight();

    int secondsPassed = 0;

    do {
        calculateAndPrintHeight(initialHeight, secondsPassed);
        ++secondsPassed;
    } while (calculateHeight(initialHeight, secondsPassed) > 0.0);

    calculateAndPrintHeight(initialHeight, secondsPassed);
}