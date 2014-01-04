//
//  Random.h
//  Space Invaders
//
//  Created by Robert Berry on 04/01/2014.
//  Copyright (c) 2014 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__Random__
#define __Space_Invaders__Random__

class Random {
public:
    static Random &getInstance();
    
    int nextInt();
    int nextIntLessThan(int n);
private:
    Random();
    Random(Random const &);
    Random operator=(Random const &);
};

#endif /* defined(__Space_Invaders__Random__) */
