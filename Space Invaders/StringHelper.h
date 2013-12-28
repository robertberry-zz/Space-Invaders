//
//  StringHelper.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__StringHelper__
#define __Space_Invaders__StringHelper__

#include <string>

class StringHelper {
public:
    static StringHelper &getInstance();
    
    /** Intersperses string s with character ch */
    std::string intersperse(std::string s, char ch);
private:
    StringHelper();
    StringHelper(StringHelper const&);
    void operator=(StringHelper const&);
};

#endif /* defined(__Space_Invaders__StringHelper__) */
