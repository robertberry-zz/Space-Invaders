//
//  Player.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Player__
#define __Space_Invaders__Player__

#include <SFML/Graphics.hpp>
#include "DeltaListener.h"

class Player : public sf::Drawable, public DeltaListener {
public:
    Player(int x, int y);
    void setVelocity(sf::Vector2f velocity);
    void onDelta(sf::Time delta);
private:
    sf::Vector2f mVelocity;
    sf::Sprite mSprite;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* defined(__Space_Invaders__Player__) */
