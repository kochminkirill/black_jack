#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include "card.h"
#include <string>

class Participant
{
public:
    Participant() : m_sum_cards{ 0 }, m_count_tyz{ 0 } {}

    Participant& takeCard(const Card&);
    int getSumCards() const { return m_sum_cards; }
    int getCountTyz() const { return m_count_tyz; }
    void changeSumCards(const std::string&);

private:
    int m_sum_cards;
    int m_count_tyz;
};

#endif
