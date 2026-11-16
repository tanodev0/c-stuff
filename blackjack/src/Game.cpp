#include "../include/Game.hpp"

void Game::start()
{
    dealCard(1);
    dealCard(1);
    dealCard(2);
    bool game = checkIfContinue(player_hand) && checkIfContinue(dealer_hand);
    bool dealer_stand = true;
    printBoard();
    while(game)
    {

        int user_answer = 0;
        printf (" HIT (1) - STAND (2)\n");
        scanf ("%d",&user_answer);
        if( user_answer == 1 )
        {
            dealCard(1);
            printBoard();
            game = checkIfContinue(player_hand) && checkIfContinue(dealer_hand);
            
        }
        if ( user_answer == 2)
        {
            while (dealer_stand)
            {
                if(getTotalHandValue(dealer_hand) < 17) 
                {
                    dealCard(2);
                    printBoard();
                }
                else
                {
                    dealer_stand = false;
                    game = false;
                }
            }
        }
    }
    if (!game)
    {
        if(getTotalHandValue(player_hand) > 21) printf("You lost, over 21!");
        else if (getTotalHandValue(player_hand) == 21) printf("You won, BLACKJACK!!");
        else if (getTotalHandValue(dealer_hand) == 21) printf("You lost, dealer got BLACKJACK!!");
        else if (getTotalHandValue(dealer_hand) > 21)  printf("You won, dealer busted!!");
        else if (getTotalHandValue(player_hand) == getTotalHandValue(dealer_hand)) printf("Tie!, you get your money back!");
        else if (getTotalHandValue(dealer_hand) >= 17 && getTotalHandValue(dealer_hand) < 21) printf("You won, dealer stood soft 17!!");
    }
} 

void Game::printBoard()
{
    stack<int> temp_player(player_hand);
    stack<int> temp_dealer(dealer_hand);
    int player_total_value = getTotalHandValue(player_hand);
    int dealer_total_value = getTotalHandValue(dealer_hand);


    for (int i = 0; i < 15; i++) cout << "-";
    cout<<endl;


    cout<<"Dealer: ";
    while (!temp_dealer.empty())
    {
        cout << temp_dealer.top() << " ";
        temp_dealer.pop();
    }
    cout<<"        Dealer value: " << dealer_total_value;
    cout<<endl;


    cout<<"Player: ";
    while (!temp_player.empty())
    {
        cout << temp_player.top() << " ";
        temp_player.pop();
    }
    cout<<"        Player value: " << player_total_value;
    cout<<endl;
    for (int i = 0; i < 15; i++) cout << "-";
    cout<<endl;

    
}

int Game::getTotalHandValue(stack<int> hand)
{
    int res = 0;
    stack<int> temp(hand);
    while (!temp.empty())
    {
        res += temp.top();
        temp.pop();
    }

    return res;
}

void Game::dealCard(int playerx_hand)
{
    Card card;
    switch (playerx_hand)
    {
    case 1:
        player_hand.push(card.value);
        break;
    case 2:
        dealer_hand.push(card.value);
        break;
    default:
        break;
    }
}


bool Game::checkIfContinue(stack<int> hand)
{
    if(getTotalHandValue(hand) > 21) 
    {
        return false;
    }
    else if (getTotalHandValue(hand) == 21) 
    {
        return false;
    }
    return true;
}