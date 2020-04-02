#include <iostream>
#include "Game.h"
int main() {
    Game game;

    game.draw();

    while(game.is_game_on())
    {
        game.update();
    }
    return 0;
}
