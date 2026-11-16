#include "./include/Game.hpp"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Game game;
    game.start();
    return 0;
}
