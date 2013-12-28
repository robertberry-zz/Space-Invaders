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
#include "Fonts.h"
#include <string>

const int FONT_SIZE = 8;
const int INITIAL_LIVES = 3;
const sf::Font &font = Fonts::getInstance().getMainFont();

PlayingState::PlayingState() :
  mPlayer((SCREEN_WIDTH - PLAYER_WIDTH) / 2, 200),
  mTestInvader((SCREEN_WIDTH - 20) / 2, 50, INVADER_2),
  mScoreText("S C O R E < 1 >     H I - S C O R E     S C O R E < 2 >", font, FONT_SIZE),
  mRemainingLives(INITIAL_LIVES),
  mRemainingLivesText(std::to_string(INITIAL_LIVES), font, FONT_SIZE),
  mCreditsText("C R E D I T    0 0", font, FONT_SIZE),
  mMaybeBullet(new Nothing<PlayerBullet>)
{
    mScoreText.setColor(sf::Color::White);
    mScoreText.setPosition(X_MARGIN, Y_MARGIN);

    mRemainingLivesText.setColor(sf::Color::White);
    auto remainingLivesBounds = mRemainingLivesText.getGlobalBounds();
    mRemainingLivesText.setPosition(X_MARGIN, SCREEN_HEIGHT - remainingLivesBounds.height - Y_MARGIN);
    
    mCreditsText.setColor(sf::Color::White);
    auto creditsBounds = mCreditsText.getGlobalBounds();
    mCreditsText.setPosition(
        SCREEN_WIDTH - creditsBounds.width - X_MARGIN,
        SCREEN_HEIGHT - creditsBounds.height - Y_MARGIN
    );
}

void PlayingState::onStart(StateBasedGame &game) {
    game.getEventBus().addSubscriber(&mPlayer);
    game.getEventBus().addSubscriber(this);
}

void PlayingState::onEnd(StateBasedGame &game) {
    game.getEventBus().removeSubscriber(&mPlayer);
}

void PlayingState::onLogic(StateBasedGame &game, sf::Time delta) {
    mPlayer.onDelta(delta);
    mMaybeBullet->forEach([&](PlayerBullet &bullet) {
        bullet.onDelta(delta);
    });
}

void PlayingState::onRender(StateBasedGame &game, sf::Time delta) {
    auto &window = game.getWindow();
    
    window.draw(mScoreText);
    window.draw(mPlayer);
    window.draw(mTestInvader);
    window.draw(mRemainingLivesText);
    window.draw(mCreditsText);
    
    mMaybeBullet->forEach([&](PlayerBullet &bullet) {
        window.draw(bullet);
    });
}

void PlayingState::update(sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space && mMaybeBullet->isEmpty()) {
        auto playerBounds = mPlayer.getGlobalBounds();
        
        mMaybeBullet = std::unique_ptr<Maybe<PlayerBullet>>(new Just<PlayerBullet>(PlayerBullet(playerBounds.left + playerBounds.width / 2, playerBounds.top)));
    }
}