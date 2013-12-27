#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "StateBasedGame.h"
#include "PlayingState.h"

const int FRAME_RATE = 60;

int main(int, char const**)
{
    StateBasedGame game("Space Invaders", 217, 248, 60, (GameState *) new PlayingState());
    game.run();
    
    return EXIT_SUCCESS;
}
