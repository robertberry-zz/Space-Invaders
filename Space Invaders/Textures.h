//
//  Textures.h
//  Space Invaders
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Textures__
#define __Space_Invaders__Textures__

#include <SFML/Graphics.hpp>
#include <string>

class Textures {

public:
    static Textures& getInstance();
    
    sf::Texture &getPlayer();
    sf::Texture &getInvader1(int frame);
    sf::Texture &getInvader2(int frame);
    sf::Texture &getInvader3(int frame);
    
    enum Key {
        PLAYER,
        INVADER_1_FRAME_1,
        INVADER_1_FRAME_2,
        INVADER_2_FRAME_1,
        INVADER_2_FRAME_2,
        INVADER_3_FRAME_1,
        INVADER_3_FRAME_2
    };
private:
    Textures();
    Textures(Textures const&);
    void operator=(Textures const&);
    
    sf::Texture mTextures[20];
    
    void loadTexture(Key k, std::string fileName);    
};


#endif /* defined(__Space_Invaders__Textures__) */
