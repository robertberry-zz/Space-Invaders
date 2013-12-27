//
//  Invader.h
//  Space Invaders
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Invader__
#define __Space_Invaders__Invader__

#include <SFML/Graphics.hpp>

enum InvaderType { INVADER_1, INVADER_2, INVADER_3 };

class Invader : public sf::Drawable {
public:
    
    Invader(int x, int y, InvaderType type);
    
    sf::Sprite &getSprite();
private:
    sf::Sprite mSprite;
    InvaderType mType;
    int mX;
    int mY;
    int mFrame;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    void refreshTexture();
};

#endif /* defined(__Space_Invaders__Invader__) */
