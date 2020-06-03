#ifndef LOCATION_TEST_H
#define LOCATION_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <SFML/Graphics.hpp>


extern "C++" {
#include "../app/helper.h"
}



TEST(location, start_position){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 32;
    p.rect.top = 416;


    ASSERT_EQ(p.Collision(0), 1);
    ASSERT_EQ(p.Collision(1), 1);
    ASSERT_EQ(alive, true);
}

TEST(location, insideTexture){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 96;
    p.rect.top = 480;

    ASSERT_EQ(p.Collision(1), 1);

    ASSERT_EQ(p.rect.top, 416);
    ASSERT_EQ(p.rect.left, 96);
    ASSERT_EQ(alive, true);

}

TEST(location, colRight){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 1504;
    p.rect.top = 672;

    ASSERT_EQ(p.Collision(0), 1);
    ASSERT_EQ(p.rect.left, 1408);

}

TEST(location, negative){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = -33;
    p.rect.top = -60;

    ASSERT_EQ(p.Collision(0), 0);
    ASSERT_EQ(p.Collision(1), 0);
    ASSERT_EQ(alive, false);
}

#endif // LOCATION_TEST_H
