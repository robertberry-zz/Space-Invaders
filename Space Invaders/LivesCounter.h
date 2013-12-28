//
//  LivesCounter.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__LivesCounter__
#define __Space_Invaders__LivesCounter__

#include <SFML/Graphics.hpp>
#include <vector>

class LivesCounter : public sf::Drawable {
private:
    int mN;
    sf::Vector2f mPosition;
    std::vector<sf::Sprite> mSprites;
    sf::Texture &mTexture;
public:
    LivesCounter(int x, int y, int initial);
    void add();
    void remove();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* defined(__Space_Invaders__LivesCounter__) */
