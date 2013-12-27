
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "StateBasedGame.h"
#include "PlayingState.h"

int main(int, char const**)
{
    StateBasedGame game("Space Invaders", 217, 248, (GameState *) new PlayingState());
    game.run();
    
    return EXIT_SUCCESS;
}
