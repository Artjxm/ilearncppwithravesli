#include "Card.h"
#include <iostream>

void Card::printCard() const {
    switch (m_value) {
        case ACE: std::cout << 'A';
            break;
        case KING: std::cout << 'K';
            break;
        case QUEEN: std::cout << 'Q';
            break;
        case JACK: std::cout << 'J';
            break;
        case TEN: std::cout << 'T';
            break;
        case NINE: std::cout << '9';
            break;
        case EIGHT: std::cout << '8';
            break;
        case SEVEN: std::cout << '7';
            break;
        case SIX: std::cout << '6';
            break;
        case FIVE: std::cout << '5';
            break;
        case FOUR: std::cout << '4';
            break;
        case THREE: std::cout << '3';
            break;
        case TWO: std::cout << '2';
            break;
        default: std::cout << '?';
    }

    switch (m_suit) {
        case CLUBS: std::cout << 'C';
            break;
        case DIAMONDS: std::cout << 'D';
            break;
        case HEARTS: std::cout << 'H';
            break;
        case SPADES: std::cout << 'S';
            break;
        default: std::cout << '?';
    }
}

int Card::getCardValue() const {
    switch (m_value) {
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN:
        case JACK:
        case QUEEN:
        case KING: return 10;
        case ACE: return 11;
        default: std::cout << "Unhandled case";
            return 0;
    }
}
