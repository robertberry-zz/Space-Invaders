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
const sf::Vector2f bulletVelocity(0, -80);
const int BULLET_WIDTH = 1;
const int BULLET_HEIGHT = 5;

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

sf::FloatRect PlayerBullet::getGlobalBounds() {
    return mShape.getGlobalBounds();
}

bool PlayerBullet::collidesWith(Shield shield) {
    auto bulletBounds = getGlobalBounds();
    auto shieldBounds = shield.getGlobalBounds();
    
    if (PhysicsHelper::getInstance().overlaps(bulletBounds, shieldBounds)) {
        for (int x = bulletBounds.left; x < bulletBounds.left + bulletBounds.width; x++) {
            for (int y = bulletBounds.top; y < bulletBounds.top + bulletBounds.height; y++) {
                int relX = x - shieldBounds.left;
                int relY = y - shieldBounds.top;
                
                if (relY > 0 && relY < shieldBounds.height && shield.getPixel(relX, relY)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}