//
//  Player.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Player.h"
#include "Textures.h"

Player::Player(int x, int y) : mX(x), mY(y), mVelocityX(0) {
    mSprite = sf::Sprite(Textures::getInstance().getPlayer());
    mSprite.setPosition(x, y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite);
}

void Player::setX(int x) {
    mX = x;
    mSprite.setPosition(mX, mY);
}

int Player::getX() {
    return mX;
}

void Player::onDelta(sf::Time delta) {
    setX(getX() + mVelocityX * delta.asSeconds());
}

void Player::setVelocityX(float velocityX) {
    mVelocityX = velocityX;
}

float Player::getVelocityX() {
    return mVelocityX;
}