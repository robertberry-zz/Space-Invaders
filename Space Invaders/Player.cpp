//
//  Player.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Player.h"
#include "Textures.h"
#include "PhysicsHelper.h"

Player::Player(int x, int y) : mVelocity(0, 0) {
    mSprite = sf::Sprite(Textures::getInstance().getPlayer());
    mSprite.setPosition(x, y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite);
}

void Player::onDelta(sf::Time delta) {
    mSprite.move(PhysicsHelper::getInstance().delta(mVelocity, delta));
}

void Player::setVelocity(sf::Vector2f velocity) {
    mVelocity = velocity;
}