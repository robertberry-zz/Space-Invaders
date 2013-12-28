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
#include "EventSubscriber.h"

class Player : public sf::Drawable, public DeltaListener, public EventSubscriber<sf::Event> {
public:
    Player(int x, int y);
    void setVelocity(sf::Vector2f velocity);
    void onDelta(sf::Time delta);
    void update(sf::Event event);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
private:
    sf::Vector2f mVelocity;
    sf::Sprite mSprite;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* defined(__Space_Invaders__Player__) */
