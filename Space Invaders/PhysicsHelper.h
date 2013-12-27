//
//  PhysicsHelper.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__PhysicsHelper__
#define __Space_Invaders__PhysicsHelper__

#include <SFML/System.hpp>

class PhysicsHelper {
public:
    static PhysicsHelper &getInstance();
    
    /**
     * Calculates the position delta based on the velocity and time delta
     */
    sf::Vector2f delta(sf::Vector2f velocity, sf::Time time);
    
    /**
     * Given a position and velocity (pixels per second) and time delta, returns the new position
     */
    sf::Vector2f nextPosition(sf::Vector2f position, sf::Vector2f velocity, sf::Time time);
    
    /**
     * Adds two vectors
     */
    sf::Vector2f add(sf::Vector2f v1, sf::Vector2f v2);
    
    /**
     * Multiplies a vector by a scalar value
     */
    sf::Vector2f multiply(sf::Vector2f v, float n);
private:
    PhysicsHelper();
    PhysicsHelper(PhysicsHelper const&);
    void operator=(PhysicsHelper const&);
};

#endif /* defined(__Space_Invaders__PhysicsHelper__) */
