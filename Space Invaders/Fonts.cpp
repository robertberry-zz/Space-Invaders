//
//  Fonts.cpp
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Fonts.h"
#include "ResourcePath.hpp"

Fonts &Fonts::getInstance() {
    static Fonts instance;
    return instance;
}

Fonts::Fonts() {
    mMainFont.loadFromFile(resourcePath() + "space_invaders.ttf");
}

sf::Font &Fonts::getMainFont() {
    return mMainFont;
}