//
//  DeltaListener.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__DeltaListener__
#define __Space_Invaders__DeltaListener__

#include <SFML/System.hpp>

class DeltaListener {
public:
    virtual void onDelta(sf::Time delta) = 0;
};

#endif /* defined(__Space_Invaders__DeltaListener__) */
