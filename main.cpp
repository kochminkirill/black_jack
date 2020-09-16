#include <iostream>
#include "deck.h"
#include "participant.h"
#include <ctime>

enum class ResultGame
{
    PLAYER_WIN,
    DEALER_WIN,
    DRAW
};

std::string chooseAction()
{
    std::string action{" "};
    do
    {
        std::cout << "choose action(take/stand):";
        std::cin >> action;
    } while(action != "take" && action != "stand");

    return action;
}

ResultGame playBlackJack()
{
    std::cout << "Let's play Black Jack\n\n";

    Deck deck;
    deck.shuffleDeck();

    std::cout << "Dealer got a card\n";
    Participant dealer;
    dealer.takeCard(deck.getCard());
    std::cout << "Dealer's sum of cards:" << dealer.getSumCards() << "\n\n";

    std::cout << "Player got two cards\n";
    Participant player;
    player.takeCard(deck.getCard()).takeCard(deck.getCard());
    std::cout << "Player's sum of cards:" << player.getSumCards() << "\n\n";

    //player action
    std::string action{" "};
    do
    {
        if(player.getSumCards() > 21)
        {
            if(player.getCountTyz() > 0)
                player.changeSumCards("Player");
            else
                return ResultGame::DEALER_WIN;
        }

        action = chooseAction();
        if(action == "take")
        {
            player.takeCard(deck.getCard());
            std::cout << "Player's sum of cards:" << player.getSumCards() << '\n';
        }

    } while(action == "take");

    std::cout << '\n';

    //dealer action
    while(dealer.getSumCards() < 17)
    {
        dealer.takeCard(deck.getCard());
        std::cout << "Dealer's sum of cards:" << dealer.getSumCards() << '\n';

        if(dealer.getSumCards() > 21)
        {
            if(dealer.getCountTyz() > 0)
                dealer.changeSumCards("Dealer");
            else
                return ResultGame::PLAYER_WIN;
        }
    }

    if(player.getSumCards() > dealer.getSumCards())
        return ResultGame::PLAYER_WIN;
    else if(dealer.getSumCards() > player.getSumCards())
        return ResultGame::DEALER_WIN;
    else if(dealer.getSumCards() == player.getSumCards())
        return ResultGame::DRAW;
}

void printResultGame(ResultGame result)
{
    switch (result)
    {
        case ResultGame::DEALER_WIN: std::cout << "Dealer won\n"; break;
        case ResultGame::PLAYER_WIN: std::cout << "Player won\n"; break;
        case ResultGame::DRAW:       std::cout << "It's draw\n" ; break;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    ResultGame result = playBlackJack();
    printResultGame(result);

    return 0;
}
