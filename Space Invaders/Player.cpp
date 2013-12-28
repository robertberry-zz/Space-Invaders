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

const float PLAYER_PIXELS_PER_SECOND = 60;

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

void Player::update(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Right) {
            setVelocity(sf::Vector2f(PLAYER_PIXELS_PER_SECOND, 0));
        } else if (event.key.code == sf::Keyboard::Left) {
            setVelocity(sf::Vector2f(-PLAYER_PIXELS_PER_SECOND, 0));
        }
    } else if (event.type == sf::Event::KeyReleased &&
               ((event.key.code == sf::Keyboard::Left && mVelocity.x < 0) ||
                (event.key.code == sf::Keyboard::Right && mVelocity.x > 0))) {
        setVelocity(sf::Vector2f(0, 0));
    }
}

sf::Vector2f Player::getPosition() {
    return mSprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds() {
    return mSprite.getGlobalBounds();
}