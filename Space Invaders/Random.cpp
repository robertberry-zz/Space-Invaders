//
//  Random.cpp
//  Space Invaders
//
//  Created by Robert Berry on 04/01/2014.
//  Copyright (c) 2014 Robert Berry. All rights reserved.
//

#include "Random.h"
#include <stdlib.h>
#include <time.h>

Random::Random() {
    srand(time(NULL));
}

Random &Random::getInstance() {
    static Random instance;
    return instance;
}

int Random::nextInt() {
    return rand();
}

int Random::nextIntLessThan(int n) {
    return rand() % n;
}