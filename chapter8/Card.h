#ifndef CARD_H
#define CARD_H

class Card {
public:
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

    Card(const Value value = MAX_VALUE,
         const Suit suit = MAX_SUIT) : m_value(value), m_suit(suit) {}


    void printCard() const;


    int getCardValue() const;

private:
    Value m_value;
    Suit m_suit;
};


#endif //CARD_H
