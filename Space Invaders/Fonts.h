//
//  Fonts.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Fonts__
#define __Space_Invaders__Fonts__

#include <SFML/Graphics.hpp>

class Fonts {
public:
    static Fonts &getInstance();
    
    sf::Font &getMainFont();
    
private:
    sf::Font mMainFont;
    Fonts();
    Fonts(Fonts const&);
    void operator=(Fonts const&);
};

#endif /* defined(__Space_Invaders__Fonts__) */
