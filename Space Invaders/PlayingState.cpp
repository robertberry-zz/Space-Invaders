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
#include "PhysicsHelper.h"

const int N_SHIELDS = 1;
const std::string hiScoreText = "S C O R E < 1 >     H I - S C O R E     S C O R E < 2 >";
const std::string creditsText = "C R E D I T      0 0";
const sf::Font &font = Fonts::getInstance().getMainFont();

PlayingState::PlayingState() :
  mPlayer((SCREEN_WIDTH - PLAYER_WIDTH) / 2, PLAYER_Y),
  mTestInvader((SCREEN_WIDTH - 20) / 2, 50, INVADER_2),
  mScoreText(hiScoreText, font, FONT_SIZE),
  mLives(X_MARGIN + 14, SCREEN_HEIGHT - Y_MARGIN - 8, 2),
  mRemainingLivesText(std::to_string(mLives.get()), font, FONT_SIZE),
  mCreditsText(creditsText, font, FONT_SIZE),
  mMaybeBullet(new Nothing<PlayerBullet>),
  mPlayer1Score(25, 16, 0),
  mShield(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 80)
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
    
    /*for (int i = 0; i < N_SHIELDS; i++) {
        mShields.push_back(Shield(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 80));
    }*/
}

void PlayingState::onStart(StateBasedGame &game) {
    EventBus<sf::Event> &eventBus = game.getEventBus();
    eventBus.addSubscriber(&mPlayer);
    eventBus.addSubscriber(this);
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
        cleanUpBullet();
    }
    mMaybeBullet->forEach([&](PlayerBullet &bullet) {
        bullet.onDelta(delta);
        
        if (bullet.collidesWith(mShield)) {
            auto bulletBounds = bullet.getGlobalBounds();
            auto shieldBounds = mShield.getGlobalBounds();
            
            PhysicsHelper::getInstance().forAll(bulletBounds, [&](float x, float y) {
                int sX = static_cast<int>(x - shieldBounds.left);
                int sY = static_cast<int>(y - shieldBounds.top);
                
                if (sY >= 0 && sY < shieldBounds.height) {
                    mShield.setPixel(sX, sY, false);
                }
            });
            mShield.updateSprite();
            cleanUpBullet();
        }
    });
    mRemainingLivesText.setString(std::to_string(mLives.get()));
}

void PlayingState::cleanUpBullet() {
    mMaybeBullet = std::unique_ptr<Nothing<PlayerBullet>>(new Nothing<PlayerBullet>);
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
    window.draw(mPlayer1Score);
    window.draw(mShield);
    
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