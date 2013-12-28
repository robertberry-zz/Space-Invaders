//
//  LivesCounter.cpp
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "LivesCounter.h"
#include <algorithm>
#include "Textures.h"

const int LIFE_MARGIN = 3;

LivesCounter::LivesCounter(int x, int y, int initial):
        mN(0), mPosition(x, y), mTexture(Textures::getInstance().getPlayer()) {
    for (; initial > 0; initial--) {
        add();
    }
}

void LivesCounter::add() {
    int x = mPosition.x + (mTexture.getSize().x + LIFE_MARGIN) * mN;
    sf::Sprite lifeSprite(mTexture);
    lifeSprite.setPosition(x, mPosition.y);
    mSprites.push_back(lifeSprite);
    mN++;
}

void LivesCounter::remove() {
    mSprites.pop_back();
}

void LivesCounter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for_each(mSprites.begin(), mSprites.end(), [&](sf::Sprite sprite) {
        target.draw(sprite);
    });
}

int LivesCounter::get() {
    return mN;
}