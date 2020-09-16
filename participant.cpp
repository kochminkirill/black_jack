#include "participant.h"
#include <iostream>

 Participant& Participant::takeCard(const Card &card)
 {
    if(card.getCardValue() == 11)
        ++m_count_tyz;

    m_sum_cards += card.getCardValue();

    return *this;
 }

 void Participant::changeSumCards(const std::string &p_n)
 {
     std::cout << '\n' << p_n << "'s sum of cards > than 21 but he has tyz\n";
     std::cout << "it means that tyz value = 1 insist of 21\n";

     do
     {
        m_sum_cards -= 10;
        --m_count_tyz;
     } while(m_count_tyz > 0);

     std::cout << '\n' << p_n << " has sum of cards:" << m_sum_cards << '\n';
 }
