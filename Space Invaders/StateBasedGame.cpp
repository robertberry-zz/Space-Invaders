//
//  StateBasedGame.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "StateBasedGame.h"
#include "GameState.h"

StateBasedGame::StateBasedGame(std::string title, int width, int height, GameState *initialState) :
  mTitle(title), mScreenWidth(width), mScreenHeight(height), mState(std::unique_ptr<GameState>(initialState)),
  mWindow(sf::VideoMode(width, height), title)
{
}

void StateBasedGame::setState(GameState *state) {
    mState = std::unique_ptr<GameState>(state);
}

/** Starts the game loop */
void StateBasedGame::run() {
    sf::Clock clock;
    
    while (mWindow.isOpen())
    {
        sf::Time elapsed = clock.restart();
        
        /** TODO implement logic to pause till frame is over */
        
        mState->onLogic(*this);
        mWindow.clear();
        mState->onRender(*this);
        mWindow.display();
    }
}

sf::RenderWindow &StateBasedGame::getWindow() {
    return mWindow;
}