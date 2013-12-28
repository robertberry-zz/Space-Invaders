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
#include "EventSubscriber.h"
#include "PlayerBullet.h"
#include <memory>
#include "Maybe.h"
#include "LivesCounter.h"

class PlayingState : public GameState, public EventSubscriber<sf::Event> {
private:
    sf::Text mScoreText;
    sf::Text mRemainingLivesText;
    sf::Text mCreditsText;
    int mRemainingLives;
    Player mPlayer;
    Invader mTestInvader;
    LivesCounter mLives;
    sf::RectangleShape mBottomBorder;
    std::unique_ptr<Maybe<PlayerBullet>> mMaybeBullet;
public:
    PlayingState();
    void onStart(StateBasedGame &game);
    void onEnd(StateBasedGame &game);
    void onLogic(StateBasedGame &game, sf::Time delta);
    void onRender(StateBasedGame &game, sf::Time delta);
    
    void update(sf::Event event);
};

#endif /* defined(__Space_Invaders__PlayingState__) */
