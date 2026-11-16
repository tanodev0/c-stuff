#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Card
{
    public:
        int value;
        Card();
        int getRandomCardValue();
        int getTimesHasAppeared(int val);
        void setCardHasAppeared(int val);
    private:
        static int n_cards[13];
};
