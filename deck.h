#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <array>
#include "constants.h"

class Deck
{
public:
    Deck();

    void printDeck()    const;
    Deck& shuffleDeck();
    const Card& getCard() { return m_deck[m_current_card++]; }

private:
    std::array<Card, ConstantsBlackJack::count_cards> m_deck;
    int m_current_card;

private:
    static void swapCard(Card&, Card&);
    static int getRandomNumber(int, int);
};

#endif
