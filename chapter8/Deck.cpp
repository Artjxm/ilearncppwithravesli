#include "Deck.h"
#include <iostream>
#include <random>


Deck::Deck() {
    int card(0);
    for (int suit = 0; suit < Card::MAX_SUIT; ++suit)
        for (int value = 0; value < Card::MAX_VALUE; ++value) {
            m_deck.at(card) = Card(static_cast<Card::Value>(value), static_cast<Card::Suit>(suit));
            ++card;
        }
}

void Deck::printDeck() const {
    for (auto card: m_deck) {
        card.printCard();
        std::cout << ' ';
    }
    std::cout << '\n';
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 mersenne(rd());

    for (auto card: m_deck) {
        swapCard(card, m_deck[mersenne() % m_deck.size()]);
    }

    m_cardIndex = 0;
}

void Deck::swapCard(Card &card1, Card &card2) {
    std::swap(card1, card2);
}
