#pragma once
#include <iostream>
#include <thread>
#include <stack>

#include "Card.hpp"


using namespace std;

class Game
{
    public:
        void start();
        void dealCard(int playerx_hand);
        void printBoard();
        void printBox();
        int getTotalHandValue(stack<int> hand);
        bool checkIfContinue(stack<int> hand);

    private:
        stack<int> player_hand;
        stack<int> dealer_hand;

};
