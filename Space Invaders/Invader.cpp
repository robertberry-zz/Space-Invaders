//
//  Invader.cpp
//  Space Invaders
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Invader.h"
#include "Textures.h"

Invader::Invader(int x, int y, InvaderType type) : mX(x), mY(y), mType(type), mFrame(0) {
    mSprite.setPosition(x, y);
    refreshTexture();
}

sf::Sprite &Invader::getSprite() {
    return mSprite;
}

void Invader::refreshTexture() {
    Textures &textures = Textures::getInstance();
    
    switch (mType) {
        case INVADER_1:
            mSprite.setTexture(textures.getInvader1(mFrame));
            break;
        case INVADER_2:
            mSprite.setTexture(textures.getInvader2(mFrame));
            break;
        case INVADER_3:
            mSprite.setTexture(textures.getInvader3(mFrame));
            break;
        default:
            break;
    }
}

void Invader::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite);
}