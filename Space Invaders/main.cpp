#include "StateBasedGame.h"
#include "PlayingState.h"
#include "positions.h"

int main(int, char const**)
{
    StateBasedGame game(
        "Space Invaders",
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        FRAMES_PER_SECOND,
        (GameState *) new PlayingState()
    );
    game.run();
    
    return EXIT_SUCCESS;
}
