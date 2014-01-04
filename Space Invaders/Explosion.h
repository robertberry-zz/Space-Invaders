//
//  Explosion.h
//  Space Invaders
//
//  Created by Robert Berry on 04/01/2014.
//  Copyright (c) 2014 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Explosion__
#define __Space_Invaders__Explosion__

#include "SFML/Graphics.hpp"

class Explosion : public sf::Drawable {
private:
    sf::Image mImage;
    sf::Texture mTexture;
    sf::Sprite mSprite;
    int mX;
    int mY;
    
    unsigned int mWidth;
    unsigned int mHeight;
    
    void updateSprite();
    
public:
    Explosion(int x, int y, unsigned int width, unsigned int height);
    Explosion(Explosion const &);
    bool get(int x, int y);
    
    int getX();
    int getY();
    
    sf::FloatRect getGlobalBounds();
    
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif /* defined(__Space_Invaders__Explosion__) */
