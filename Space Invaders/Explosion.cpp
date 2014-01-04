//
//  Explosion.cpp
//  Space Invaders
//
//  Created by Robert Berry on 04/01/2014.
//  Copyright (c) 2014 Robert Berry. All rights reserved.
//

#include "Explosion.h"
#include "Random.h"

Explosion::Explosion(int xPos, int yPos, unsigned int width, unsigned int height): mX(xPos), mY(yPos), mWidth(width), mHeight(height) {
    mImage.create(width, height);
    /** Randomly initialize the explosion's bits */
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if ((x > 0 && x < width - 1 && y > 0 && y < height - 1) ||
                Random::getInstance().nextIntLessThan(100) < 50) {
                mImage.setPixel(x, y, sf::Color::Green);
            } else {
                mImage.setPixel(x, y, sf::Color::Black);
            }
        }
    }
    mImage.createMaskFromColor(sf::Color::Black);
    updateSprite();
}

/** Copy constructor to copy the whole image */
Explosion::Explosion(Explosion const & e): mX(e.mX), mY(e.mY), mWidth(e.mWidth), mHeight(e.mHeight) {
    mImage.create(e.mWidth, e.mHeight);
    mImage.copy(e.mImage, 0, 0);
    updateSprite();
}

void Explosion::updateSprite() {
    mTexture.loadFromImage(mImage);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(mX, mY);
}

bool Explosion::get(int x, int y) {
    return x >= 0 && x < mWidth && y >= 0 && y < mHeight && mImage.getPixel(x, y) == sf::Color::Green;
}

void Explosion::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite);
}

int Explosion::getX() {
    return mX;
}

int Explosion::getY() {
    return mY;
}

sf::FloatRect Explosion::getGlobalBounds() {
    return sf::FloatRect(mX, mY, mWidth, mHeight);
}