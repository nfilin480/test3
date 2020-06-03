#ifndef ARCHER_TEST_H
#define ARCHER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <SFML/Graphics.hpp>


extern "C++" {
#include "../app/helper.h"
}



TEST(arrow_of_archer, first){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);



}

#endif // ARCHER_TEST_H
