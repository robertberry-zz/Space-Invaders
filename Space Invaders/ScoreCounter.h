//
//  ScoreCounter.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__ScoreCounter__
#define __Space_Invaders__ScoreCounter__

#include <SFML/Graphics.hpp>

class ScoreCounter : public sf::Drawable {
private:
    int mScore;
    sf::Text mText;
    std::string mString;
    std::string makeString(int n);
public:
    ScoreCounter(int x, int y, int score);
    int get();
    void add(int n);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* defined(__Space_Invaders__ScoreCounter__) */
