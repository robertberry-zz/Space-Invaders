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

const std::string hiScoreText = "S C O R E < 1 >     H I - S C O R E     S C O R E < 2 >";
const std::string creditsText = "C R E D I T      0 0";
const int FONT_SIZE = 8;
const int PLAYER_Y = 208;
const sf::Font &font = Fonts::getInstance().getMainFont();

PlayingState::PlayingState() :
  mPlayer((SCREEN_WIDTH - PLAYER_WIDTH) / 2, PLAYER_Y),
  mTestInvader((SCREEN_WIDTH - 20) / 2, 50, INVADER_2),
  mScoreText(hiScoreText, font, FONT_SIZE),
  mLives(X_MARGIN + 14, SCREEN_HEIGHT - Y_MARGIN - 8, 2),
  mRemainingLivesText(std::to_string(mLives.get()), font, FONT_SIZE),
  mCreditsText(creditsText, font, FONT_SIZE),
  mMaybeBullet(new Nothing<PlayerBullet>)
{
    mScoreText.setColor(sf::Color::White);
    mScoreText.setPosition(X_MARGIN, 0);

    mRemainingLivesText.setColor(sf::Color::White);
    auto remainingLivesBounds = mRemainingLivesText.getGlobalBounds();
    mRemainingLivesText.setPosition(5, SCREEN_HEIGHT - remainingLivesBounds.height - Y_MARGIN);
    
    mCreditsText.setColor(sf::Color::White);
    auto creditsBounds = mCreditsText.getGlobalBounds();
    mCreditsText.setPosition(
        SCREEN_WIDTH - creditsBounds.width - X_MARGIN,
        SCREEN_HEIGHT - creditsBounds.height - Y_MARGIN
    );
    
    mBottomBorder.setPosition(0, SCREEN_HEIGHT - Y_MARGIN - creditsBounds.height - 1);
    mBottomBorder.setSize(sf::Vector2f(SCREEN_WIDTH, 1));
    mBottomBorder.setFillColor(sf::Color::Green);
}

void PlayingState::onStart(StateBasedGame &game) {
    game.getEventBus().addSubscriber(&mPlayer);
    game.getEventBus().addSubscriber(this);
}

void PlayingState::onEnd(StateBasedGame &game) {
    game.getEventBus().removeSubscriber(&mPlayer);
}

void PlayingState::onLogic(StateBasedGame &game, sf::Time delta) {
    auto playerBounds = mPlayer.getGlobalBounds();
    float xVelocity = mPlayer.getVelocity().x;
    
    if ((playerBounds.left <= 0 && xVelocity < 0) ||
        (playerBounds.left + playerBounds.width >= SCREEN_WIDTH && xVelocity > 0)) {
        mPlayer.setVelocity(sf::Vector2f(0, 0));
    }
    
    mPlayer.onDelta(delta);
    if (mMaybeBullet->exists([&](PlayerBullet &bullet) {
        return (bullet.getGlobalBounds().top + bullet.getGlobalBounds().height) < 0;
    })) {
        mMaybeBullet = std::unique_ptr<Nothing<PlayerBullet>>(new Nothing<PlayerBullet>);
    } else {
        mMaybeBullet->forEach([&](PlayerBullet &bullet) {
            bullet.onDelta(delta);
        });
    }
    mRemainingLivesText.setString(std::to_string(mLives.get()));
}

void PlayingState::onRender(StateBasedGame &game, sf::Time delta) {
    auto &window = game.getWindow();
    
    window.draw(mScoreText);
    window.draw(mPlayer);
    window.draw(mTestInvader);
    window.draw(mRemainingLivesText);
    window.draw(mCreditsText);
    window.draw(mBottomBorder);
    window.draw(mLives);
    
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