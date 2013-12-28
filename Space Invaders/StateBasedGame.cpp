//
//  StateBasedGame.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "StateBasedGame.h"
#include "GameState.h"

StateBasedGame::StateBasedGame(std::string title, int width, int height, int frameRate, GameState *initialState) :
  mTitle(title), mScreenWidth(width), mScreenHeight(height), mState(std::unique_ptr<GameState>(initialState)),
  mWindow(sf::VideoMode(width, height), title)
{
    mWindow.setFramerateLimit(frameRate);
}

void StateBasedGame::setState(GameState *state) {
    
    mState = std::unique_ptr<GameState>(state);
    mState->onStart(*this);
}

/** Starts the game loop */
void StateBasedGame::run() {
    sf::Clock clock;
    
    mState->onStart(*this);
    
    while (mWindow.isOpen()) {
        // Process events
        sf::Event event;
        while (mWindow.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                mWindow.close();
            }
            
            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                mWindow.close();
            }
            
            mEventBus.publish(event);
        }
        sf::Time delta = clock.restart();
        mState->onLogic(*this, delta);
        mWindow.clear();
        mState->onRender(*this, delta);
        mWindow.display();
    }
}

sf::RenderWindow &StateBasedGame::getWindow() {
    return mWindow;
}

EventBus<sf::Event> &StateBasedGame::getEventBus() {
    return mEventBus;
}