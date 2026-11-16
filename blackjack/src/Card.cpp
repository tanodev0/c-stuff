#include "../include/Card.hpp"

    int Card::n_cards[13] = {0};

    Card::Card()
    {
        value = getRandomCardValue();
    }

    void Card::setCardHasAppeared(int val)
    {
        n_cards[val]++;
    }

    int Card::getRandomCardValue()
    {
        bool max_appears = false;
        int card_value = rand() % 11 + 1;
        while(!max_appears)
        {
            if(getTimesHasAppeared(card_value) >= 4)
            {
                card_value = rand() % 11 + 1;
            }
            else
            {
                setCardHasAppeared(card_value);
                max_appears = true;
            }
        }        
        if (card_value == 1) card_value = 10;
        return card_value;
    }

    int Card::getTimesHasAppeared(int val)
    {   
        return n_cards[val];
    }
