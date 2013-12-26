//
//  Textures.cpp
//  Space Invaders
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Textures.h"
#include "ResourcePath.hpp"

Textures::Textures() {
    loadTexture(PLAYER, "player.png");
    loadTexture(INVADER_2_FRAME_1, "invader-2-frame-1.png");
    loadTexture(INVADER_2_FRAME_2, "invader-2-frame-2.png");
}

sf::Texture &Textures::getPlayer() {
    return mTextures[PLAYER];
}

sf::Texture &Textures::getInvader1(int frame) {
    if (frame == 0) {
        return mTextures[INVADER_1_FRAME_1];
    } else {
        return mTextures[INVADER_1_FRAME_2];
    }
}

sf::Texture &Textures::getInvader2(int frame) {
    if (frame == 0) {
        return mTextures[INVADER_2_FRAME_1];
    } else {
        return mTextures[INVADER_2_FRAME_2];
    }
}

sf::Texture &Textures::getInvader3(int frame) {
    if (frame == 0) {
        return mTextures[INVADER_3_FRAME_1];
    } else {
        return mTextures[INVADER_3_FRAME_2];
    }
}

void Textures::loadTexture(Textures::Key k, std::string fileName) {
    mTextures[k].loadFromFile(resourcePath() + fileName);
}

Textures& Textures::getInstance() {
    static Textures instance;
    return instance;
}