
#include "chapter5Task2.h"

int chooseRandomNumber() {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    return mersenne() % 100 + 1;
}

void guessNumber(const int guessingNumber, const int triesAmount) {
    std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";

    for (int tryN = 0; tryN < triesAmount; ++tryN) {
        std::cout << "Guess #" << tryN + 1 << ":";
        int userGuess;
        std::cin >> userGuess;

        if (userGuess > guessingNumber) {
            std::cout << "Your guess is too high.\n";
        }
        else if (userGuess < guessingNumber) {
            std::cout << "Your guess is too low.\n";
        }
        else {
            std::cout << "Correct! You win!\n";
            return;
        }
    }

    std::cout << "Sorry, you lost. The correct number was " << guessingNumber << ".\n";
}

char getOption() {
    char choise;
    std::cin >> choise;
    // Очищаем буфер данных от лишних символов после символа варианта выбора
    std::cin.ignore(32767, '\n');

    if (std::cin.fail()) // если предыдущее извлечение было неудачным,
    {
        std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
        std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
    }
    return choise;
}

bool keepPlaying() {
    char choise;
    do {
        std::cout << "Would you like to play again (y/n)?";
        choise = getOption();
    } while (choise != 'y' && choise != 'n');

    return (choise == 'y');
}

void chapter5Task2() {
    const int guesses = 7;

    do {
        guessNumber(chooseRandomNumber(), guesses);
    } while (keepPlaying());

    std::cout << "Thank you for playing.\n";
}
