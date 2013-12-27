//
//  PlayingState.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "PlayingState.h"

const int SCREEN_WIDTH = 217;
const int SCREEN_HEIGHT = 248;
const int PLAYER_WIDTH = 25;
const int FRAMES_PER_SECOND = 60;
const float PLAYER_PIXELS_PER_SECOND = 1;

PlayingState::PlayingState() : mPlayer((SCREEN_WIDTH - PLAYER_WIDTH) / 2, 200),
  mTestInvader((SCREEN_WIDTH - 20) / 2, 50, INVADER_2) {
    
}

void PlayingState::onLogic(StateBasedGame &game) {
    sf::RenderWindow &window = game.getWindow();
    
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
        // Escape pressed : exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                mPlayer.setVelocityX(PLAYER_PIXELS_PER_SECOND);
            } else if (event.key.code == sf::Keyboard::Left) {
                mPlayer.setVelocityX(-PLAYER_PIXELS_PER_SECOND);
            }
        }
    }
}

void PlayingState::onRender(StateBasedGame &game) {
    sf::RenderWindow &window = game.getWindow();
    
    window.draw(mPlayer);
    window.draw(mTestInvader);
}