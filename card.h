#ifndef CARD_H
#define CARD_H

class Card
{
public:
    enum class Rank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        VALET,
        QUEEN,
        KOROL,
        TYZ,
        MAX_RANK
    };
    enum class Suit
    {
        TREFU,
        BUBNU,
        CHERVU,
        PIKI,
        MAX_SUIT
    };

public:
    Card(Suit suit = Suit::MAX_SUIT, Rank rank = Rank::MAX_RANK) : m_suit{ suit }, m_rank{ rank }{}
    void printCard()   const;
    int getCardValue() const;

private:
    Suit m_suit;
    Rank m_rank;
};

#endif
