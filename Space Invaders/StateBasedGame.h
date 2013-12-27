//
//  StateBasedGame.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__StateBasedGame__
#define __Space_Invaders__StateBasedGame__

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

class GameState;

class StateBasedGame {
private:
    sf::RenderWindow mWindow;
    std::string mTitle;
    int mScreenWidth;
    int mScreenHeight;
    std::unique_ptr<GameState> mState;
public:
    StateBasedGame(std::string title, int screenWidth, int screenHeight, GameState *initialState);
    void setState(GameState *state);
    sf::RenderWindow &getWindow();
    void run();
};

#endif /* defined(__Space_Invaders__StateBasedGame__) */
