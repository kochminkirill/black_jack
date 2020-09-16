#include "deck.h"
#include <iostream>

Deck::Deck() : m_current_card{ 0 }
{
    int card{ 0 };
    for(int suit{ 0 }; suit < static_cast<int>(Card::Suit::MAX_SUIT); ++suit)
        for(int rank{ 0 }; rank < static_cast<int>(Card::Rank::MAX_RANK); ++rank)
            m_deck[card++] = Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
}

void Deck::printDeck() const
{
    for(int card{ 0 }; card < ConstantsBlackJack::count_cards; ++card)
    {
        if(card % 13 == 0)
            std::cout << '\n';

        m_deck[card].printCard();
    }

    std::cout << "\n\n";
}

Deck& Deck::shuffleDeck()
{
    for(int card{ 0 }; card < ConstantsBlackJack::count_cards; ++card)
    {
        int random_card{ Deck::getRandomNumber(0, ConstantsBlackJack::count_cards - 1) };
        Deck::swapCard(m_deck[card], m_deck[random_card]);
    }

    return *this;
}

//support functions
void Deck::swapCard(Card &c_1, Card &c_2)
{
    Card tmp_card{ c_1 };
    c_1 = c_2;
    c_2 = tmp_card;
}

int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

