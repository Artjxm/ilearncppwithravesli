#ifndef DECK_H
#define DECK_H
#include <array>
#include "Card.h"


class Deck {
    std::array<Card, 52> m_deck;
    int m_cardIndex{ 0 };

    static void swapCard(Card &card1, Card &card2);

public:
    Deck();

    void printDeck() const;

    void shuffleDeck();

    const Card &dealCard() { return m_deck[m_cardIndex++]; }
};


#endif //DECK_H
