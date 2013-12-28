//
//  StringHelper.cpp
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "StringHelper.h"
#include <sstream>

StringHelper::StringHelper() {}

StringHelper &StringHelper::getInstance() {
    static StringHelper instance;
    return instance;
}

std::string StringHelper::intersperse(std::string s, char ch) {
    std::ostringstream out;
    
    for (int i = 0; i < s.length(); i++) {
        out << s[i];
        if (i != s.length() - 1) out << ch;
    }
    
    return out.str();
}