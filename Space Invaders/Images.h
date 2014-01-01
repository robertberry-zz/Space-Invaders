//
//  Images.h
//  Space Invaders
//
//  Created by Robert Berry on 01/01/2014.
//  Copyright (c) 2014 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Images__
#define __Space_Invaders__Images__

#include <SFML/Graphics.hpp>

class Images {
public:
    static Images &getInstance();
    
    sf::Image &getShield();
private:
    sf::Image mShield;
    
    Images();
    Images(Images const&);
    void operator=(Images const&);
};

#endif /* defined(__Space_Invaders__Images__) */
