//
//  PlayingState.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "PlayingState.h"
#include "EventSubscriber.h"
#include "positions.h"

template class EventBus<sf::Event>;
template class EventSubscriber<sf::Event>;

PlayingState::PlayingState() : mPlayer((SCREEN_WIDTH - PLAYER_WIDTH) / 2, 200),
  mTestInvader((SCREEN_WIDTH - 20) / 2, 50, INVADER_2) {
}

void PlayingState::onStart(StateBasedGame &game) {
    /** TODO: add onShutDown event to remove this subscriber? Otherwise could get memory corruption errors. */
    game.getEventBus().addSubscriber(&mPlayer);
}

void PlayingState::onEnd(StateBasedGame &game) {
    game.getEventBus().removeSubscriber(&mPlayer);
}

void PlayingState::onLogic(StateBasedGame &game, sf::Time delta) {
    mPlayer.onDelta(delta);
}

void PlayingState::onRender(StateBasedGame &game, sf::Time delta) {
    sf::RenderWindow &window = game.getWindow();
    
    window.draw(mPlayer);
    window.draw(mTestInvader);
}