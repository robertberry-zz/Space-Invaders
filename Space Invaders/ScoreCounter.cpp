//
//  ScoreCounter.cpp
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "ScoreCounter.h"
#include "positions.h"
#include <string>
#include <iomanip>
#include <sstream>
#include "Fonts.h"
#include "StringHelper.h"

int MAX_SCORE = 10000;

ScoreCounter::ScoreCounter(int x, int y, int score):
    mText(makeString(score), Fonts::getInstance().getMainFont(), FONT_SIZE) {
    mText.setPosition(sf::Vector2f(x, y));
}

void ScoreCounter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mText);
}

void ScoreCounter::add(int n) {
    mScore += n;
    mText.setString(makeString(n));
}

std::string ScoreCounter::makeString(int n) {
    n %= MAX_SCORE;
    std::ostringstream scoreString;
    scoreString << std::setw(4) << std::setfill('0') << n;
    return StringHelper::getInstance().intersperse(scoreString.str(), ' ');
}