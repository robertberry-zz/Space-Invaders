//
//  PhysicsHelper.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__PhysicsHelper__
#define __Space_Invaders__PhysicsHelper__

#include <SFML/Graphics.hpp>

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
    
    template <typename F> void forAll(sf::FloatRect rect, F f);
    
    /**
     * Whether two Rects overlap
     */
    bool overlaps(sf::FloatRect r1, sf::FloatRect r2);
private:
    PhysicsHelper();
    PhysicsHelper(PhysicsHelper const&);
    void operator=(PhysicsHelper const&);
};

template <typename F> void PhysicsHelper::forAll(sf::FloatRect rect, F f) {
    for (float x = rect.left; x < rect.left + rect.width; x++) {
        for (float y = rect.top; y < rect.top + rect.height; y++) {
            f(x, y);
        }
    }
}

#endif /* defined(__Space_Invaders__PhysicsHelper__) */
