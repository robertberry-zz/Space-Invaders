//
//  PlayerBullet.cpp
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "PlayerBullet.h"
#include "PhysicsHelper.h"

/** Bullet velocity is constant */
const sf::Vector2f bulletVelocity(0, -60);
const int BULLET_WIDTH = 1;
const int BULLET_HEIGHT = 6;

PlayerBullet::PlayerBullet(int x, int y) {
    mShape.setSize(sf::Vector2f(BULLET_WIDTH, BULLET_HEIGHT));
    mShape.setPosition(x, y);
    mShape.setFillColor(sf::Color::Green);
}

void PlayerBullet::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mShape);
}

void PlayerBullet::onDelta(sf::Time delta) {
    mShape.move(PhysicsHelper::getInstance().delta(bulletVelocity, delta));
}