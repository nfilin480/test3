#ifndef ARCHER_TEST_H
#define ARCHER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <SFML/Graphics.hpp>


extern "C++" {
#include "../app/helper.h"
}



TEST(arrow_of_archer, onDistance){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 516;
    p.rect.top = 96;

    for ( float time = 10; time < 100; time+=5){
        p.enemy_archer(time, 0);
    }
    ASSERT_EQ((int)p.index_arrows.size(), 0);
    ASSERT_EQ(alive, true);
}

TEST(arrow_of_archer, shots){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);


    p.rect.left = 608;
    p.rect.top = 256;

    for ( float time = 100; time < 3000; time+=100){
        p.enemy_archer(time, 0);
    }

    ASSERT_EQ((int)p.index_arrows.size(), 11);
    ASSERT_EQ(alive, true);

}

#endif // ARCHER_TEST_H
