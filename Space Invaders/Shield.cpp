//
//  Shield.cpp
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Shield.h"
#include "Images.h"

Shield::Shield(int left, int top): mX(left), mY(top), mBitmap(Images::getInstance().getShield()) {
    updateSprite();
}

/** This should be called after manipulating the raw bitmap */
void Shield::updateSprite() {
    mTexture.loadFromImage(mBitmap);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(mX, mY);
}

void Shield::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

sf::FloatRect Shield::getGlobalBounds() {
    return sf::FloatRect(mX, mY, getWidth(), getHeight());
}

bool Shield::getPixel(unsigned int x, unsigned int y) {
    auto px = mBitmap.getPixel(x, y);
    return !(+px.r == 0 && +px.g == 0 && +px.b == 0);
}

void Shield::setPixel(unsigned int x, unsigned int y, bool alive) {
    if (!alive) mBitmap.setPixel(x, y, sf::Color(0, 0, 0, 255));
}

int Shield::getX() {
    return mX;
}

int Shield::getY() {
    return mY;
}

int Shield::getWidth() {
    return mBitmap.getSize().x;
}

int Shield::getHeight() {
    return mBitmap.getSize().y;
}