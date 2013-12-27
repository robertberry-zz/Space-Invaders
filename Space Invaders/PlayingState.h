//
//  PlayingState.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__PlayingState__
#define __Space_Invaders__PlayingState__

#include "GameState.h"
#include "Player.h"
#include "Invader.h"

class PlayingState : public GameState {
private:
    Player mPlayer;
    Invader mTestInvader;
public:
    PlayingState();
    void onLogic(StateBasedGame &game, sf::Time delta);
    void onRender(StateBasedGame &game, sf::Time delta);
};

#endif /* defined(__Space_Invaders__PlayingState__) */
