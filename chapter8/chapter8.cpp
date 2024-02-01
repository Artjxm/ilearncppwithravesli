#include "chapter8.h"

#include <iostream>
#include "Point.h"
#include "Welcome.h"
#include "Monster.h"
#include "MonsterGenerator.h"
#include "Deck.h"

void chapter8Task1() {
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}

void chapter8Task2() {
    Welcome hello;
    hello.print();
}

// генерим тысячу случайных монстров
void chapter8Task3() {
    for (auto i = 0; i < 1000; ++i) {
        Monster monster = MonsterGenerator::generateMonster();
        monster.print();
    }
}

char getPlayerChoice2() {
    std::cout << "Hit (1) or stand (2):";
    char choice;
    do std::cin >> choice;
    while (choice != '1' && choice != '2');
    return choice;
}

bool playBlackjack() {
    Deck deck;
    deck.shuffleDeck();
    int playerScore(0), dealerScore(0);

    // До первого хода игрока
    dealerScore += deck.dealCard().getCardValue();
    std::cout << "The dealer starts with " << dealerScore << " points.\n";

    // Первые две карты игрока
    playerScore += deck.dealCard().getCardValue();
    playerScore += deck.dealCard().getCardValue();
    std::cout << "You start with " << playerScore << " points.\n";
    if (playerScore > 21) return false;

    // Ход игрока
    while (true) {
        if (getPlayerChoice2() == '1') {
            playerScore += deck.dealCard().getCardValue();
            std::cout << "You have " << playerScore << " points now.\n";
            if (playerScore > 21) return false;
        }
        else {
            std::cout << "You keep " << playerScore << " points.\n";
            break;
        }
    }

    // Ход дилера
    while (dealerScore < 17) {
        dealerScore += deck.dealCard().getCardValue();
        std::cout << "The dealer now has " << dealerScore << " points.\n";
    }

    // Если дилер перебрал
    if (dealerScore > 21) return true;

    return (playerScore > dealerScore);
}

void chapter8Task4() {
    if (playBlackjack()) std::cout << "You won!";
    else std::cout << "You lost! :(";
}


void chapter8() {
    // chapter8Task1();
    // chapter8Task2();
    // chapter8Task3();
    chapter8Task4();
}
