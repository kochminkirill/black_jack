#include "card.h"
#include <iostream>

void Card::printCard() const
{
    switch (m_rank)
    {
        case Card::Rank::RANK_2:    std::cout << "2";  break;
        case Card::Rank::RANK_3:    std::cout << "3";  break;
        case Card::Rank::RANK_4:    std::cout << "4";  break;
        case Card::Rank::RANK_5:    std::cout << "5";  break;
        case Card::Rank::RANK_6:    std::cout << "6";  break;
        case Card::Rank::RANK_7:    std::cout << "7";  break;
        case Card::Rank::RANK_8:    std::cout << "8";  break;
        case Card::Rank::RANK_9:    std::cout << "9";  break;
        case Card::Rank::RANK_10:   std::cout << "10"; break;
        case Card::Rank::VALET:     std::cout << "V";  break;
        case Card::Rank::QUEEN:     std::cout << "Q";  break;
        case Card::Rank::KOROL:     std::cout << "K";  break;
        case Card::Rank::TYZ:       std::cout << "T";  break;
        case Card::Rank::MAX_RANK:  std::cout << "incorrect rank"; break;
    }

    switch (m_suit)
    {
        case Card::Suit::BUBNU:    std::cout << "B"; break;
        case Card::Suit::CHERVU:   std::cout << "C"; break;
        case Card::Suit::PIKI:     std::cout << "P"; break;
        case Card::Suit::TREFU:    std::cout << "T"; break;
        case Card::Suit::MAX_SUIT: std::cout << "incorrect suit"; break;
    }

    std::cout << " ";
}

int Card::getCardValue() const
{
    switch (m_rank)
    {
        case Card::Rank::RANK_2:   return 2;
        case Card::Rank::RANK_3:   return 3;
        case Card::Rank::RANK_4:   return 4;
        case Card::Rank::RANK_5:   return 5;
        case Card::Rank::RANK_6:   return 6;
        case Card::Rank::RANK_7:   return 7;
        case Card::Rank::RANK_8:   return 8;
        case Card::Rank::RANK_9:   return 9;
        case Card::Rank::RANK_10:  return 10;
        case Card::Rank::VALET:    return 10;
        case Card::Rank::QUEEN:    return 10;
        case Card::Rank::KOROL:    return 10;
        case Card::Rank::TYZ:      return 11;
        case Card::Rank::MAX_RANK: return 0;
    }

    return 0;
}
