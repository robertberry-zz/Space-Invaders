//
//  PhysicsHelper.cpp
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "PhysicsHelper.h"

PhysicsHelper &PhysicsHelper::getInstance() {
    static PhysicsHelper instance;
    return instance;
}

PhysicsHelper::PhysicsHelper() {}

sf::Vector2f PhysicsHelper::add(sf::Vector2f v1, sf::Vector2f v2) {
    return sf::Vector2f(v1.x + v2.x, v1.y + v2.y);
}

sf::Vector2f PhysicsHelper::multiply(sf::Vector2f v, float n) {
    return sf::Vector2f(v.x * n, v.y * n);
}

sf::Vector2f PhysicsHelper::nextPosition(sf::Vector2f position, sf::Vector2f velocity, sf::Time time) {
    return add(position, delta(velocity, time));
}

sf::Vector2f PhysicsHelper::delta(sf::Vector2f velocity, sf::Time time) {
    return multiply(velocity, time.asSeconds());
}

bool PhysicsHelper::overlaps(sf::FloatRect r1, sf::FloatRect r2) {
    float r1Right = r1.left + r1.width;
    float r1Bottom = r1.top + r1.height;
    float r2Right = r2.left + r2.width;
    float r2Bottom = r2.top + r2.height;
    
    bool intersectsX = (r1Right >= r2.left && r1Right <= r2Right) || (r1.left <= r2Right && r1.left >= r2.left);
    bool intersectsY = (r1Bottom >= r2.top && r1Bottom <= r2Bottom) || (r1.top <= r2Bottom && r1.top >= r2.top);
    
    return intersectsX && intersectsY;
}