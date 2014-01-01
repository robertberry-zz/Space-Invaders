//
//  Shield.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Shield__
#define __Space_Invaders__Shield__

#include <SFML/Graphics.hpp>

class Shield : public sf::Drawable {
private:
    sf::Image mBitmap;
    sf::Texture mTexture;
    sf::Sprite mSprite;
    int mX;
    int mY;
public:
    Shield(int x, int y);
    
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds();
    
    bool getPixel(unsigned int x, unsigned int y);
    void setPixel(unsigned int x, unsigned int y, bool alive);
    
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    
    void updateSprite();
};

#endif /* defined(__Space_Invaders__Shield__) */
