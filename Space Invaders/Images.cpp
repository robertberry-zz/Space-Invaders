//
//  Images.cpp
//  Space Invaders
//
//  Created by Robert Berry on 01/01/2014.
//  Copyright (c) 2014 Robert Berry. All rights reserved.
//

#include "Images.h"
#include "ResourcePath.hpp"

#include <iostream>

Images::Images() {
    mShield.loadFromFile(resourcePath() + "shield.bmp");
}

Images &Images::getInstance() {
    static Images instance;
    return instance;
}

sf::Image &Images::getShield() {
    return mShield;
}