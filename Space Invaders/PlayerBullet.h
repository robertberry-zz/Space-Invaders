//
//  PlayerBullet.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__PlayerBullet__
#define __Space_Invaders__PlayerBullet__

#include <SFML/Graphics.hpp>
#include "DeltaListener.h"

class PlayerBullet : public sf::Drawable, public DeltaListener {
private:
    sf::RectangleShape mShape;
    
public:
    PlayerBullet(int x, int y);
    
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void onDelta(sf::Time delta);
};

#endif /* defined(__Space_Invaders__PlayerBullet__) */
