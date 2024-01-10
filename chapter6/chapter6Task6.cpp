
#include "chapter6Task6.h"

namespace CardScope {
    enum Suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES,
        MAX_SUIT
    };

    enum Value {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
        MAX_VALUE
    };
}

struct Card {
    CardScope::Value value;
    CardScope::Suit suit;
};

void printCard(const Card &card) {
    switch (card.value) {
        case CardScope::ACE:
            std::cout << 'A';
            break;
        case CardScope::KING:
            std::cout << 'K';
            break;
        case CardScope::QUEEN:
            std::cout << 'Q';
            break;
        case CardScope::JACK:
            std::cout << 'J';
            break;
        case CardScope::TEN:
            std::cout << 'T';
            break;
        case CardScope::NINE:
            std::cout << '9';
            break;
        case CardScope::EIGHT:
            std::cout << '8';
            break;
        case CardScope::SEVEN:
            std::cout << '7';
            break;
        case CardScope::SIX:
            std::cout << '6';
            break;
        case CardScope::FIVE:
            std::cout << '5';
            break;
        case CardScope::FOUR:
            std::cout << '4';
            break;
        case CardScope::THREE:
            std::cout << '3';
            break;
        case CardScope::TWO:
            std::cout << '2';
            break;
        default:
            std::cout << '?';
    }

    switch (card.suit) {
        case CardScope::CLUBS:
            std::cout << 'C';
            break;
        case CardScope::DIAMONDS:
            std::cout << 'D';
            break;
        case CardScope::HEARTS:
            std::cout << 'H';
            break;
        case CardScope::SPADES:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
    }
}

void initializeDeck(std::array<Card, 52> &deck) {
    int card(0);
    for (int suit = 0; suit < CardScope::MAX_SUIT; ++suit)
        for (int value = 0; value < CardScope::MAX_VALUE; ++value) {
            deck[card].suit = static_cast<CardScope::Suit>(suit);
            deck[card].value = static_cast<CardScope::Value>(value);
            ++card;
        }
}

void printDeck(const std::array<Card, 52> &deck) {
    for (auto card: deck) {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void swapCard(Card &card1, Card &card2) {
    std::swap(card1, card2);
}

void shuffleDeck(std::array<Card, 52> &deck) {
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 52; ++i) {
        swapCard(deck[i], deck[rand() % 52]);
    }
}

int getCardValue(const Card &card) {
    switch (card.value) {
        case CardScope::TWO: return 2;
        case CardScope::THREE: return 3;
        case CardScope::FOUR: return 4;
        case CardScope::FIVE: return 5;
        case CardScope::SIX: return 6;
        case CardScope::SEVEN: return 7;
        case CardScope::EIGHT: return 8;
        case CardScope::NINE: return 9;
        case CardScope::TEN:
        case CardScope::JACK:
        case CardScope::QUEEN:
        case CardScope::KING: return 10;
        case CardScope::ACE: return 11;
        default:
            std::cout << "Unhandled case";
            return 0;
    }
}

char getPlayerChoice() {
    std::cout << "Hit (1) or stand (2):";
    char choice;
    do
        std::cin >> choice;
    while (choice != '1' && choice != '2');
    return choice;
}

bool playBlackjack(std::array<Card, 52> &deck) {
    Card *cardPtr = &deck[0];
    int playerScore(0), dealerScore(0);

    // До первого хода игрока
    dealerScore += getCardValue(*cardPtr++);
    std::cout << "The dealer starts with " << dealerScore << " points.\n";

    // Первые две карты игрока
    playerScore += getCardValue(*cardPtr++);
    playerScore += getCardValue(*cardPtr++);
    std::cout << "You start with " << playerScore << " points.\n";
    if (playerScore > 21)
        return false;

    // Ход игрока
    while (true) {
        if (getPlayerChoice() == '1') {
            playerScore += getCardValue(*cardPtr++);
            std::cout << "You have " << playerScore << " points now.\n";
            if (playerScore > 21)
                return false;
        }
        else {
            std::cout << "You keep " << playerScore << " points.\n";
            break;
        }
    }

    // Ход дилера
    while (dealerScore < 17) {
        dealerScore += getCardValue(*cardPtr++);
        std::cout << "The dealer now has " << dealerScore << " points.\n";
    }

    // Если дилер перебрал
    if (dealerScore > 21)
        return true;

    return (playerScore > dealerScore);
}

void chapter6Task6() {
    std::array<Card, 52> deck{};
    initializeDeck(deck);
    shuffleDeck(deck);

    if (playBlackjack(deck))
        std::cout << "You won!";
    else
        std::cout << "You lost! :(";
}
