#ifndef ARCHER_TEST_H
#define ARCHER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <SFML/Graphics.hpp>


extern "C++" {
#include "../app/helper.h"
#include "../app/global_vars.h"
}



TEST(arrow_of_archer, onDistance){
    alive = true;
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 516;
    p.rect.top = 96;

    float time = 10;
    for (int i = 0; i < 10; i++){
        p.enemy_archer(time, 0);
        time = time + 10;
    }
    ASSERT_EQ((int)p.index_arrows.size(), 0);
    ASSERT_EQ(alive, true);
}

TEST(arrow_of_archer, shots){
    alive = true;
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);


    p.rect.left = 608;
    p.rect.top = 256;

    float time = 100;
    for (int i = 0; i < 30; i++){
        p.enemy_archer(time, 0);
        time = time + 100;
    }

    ASSERT_EQ((int)p.index_arrows.size(), 11);
    ASSERT_EQ(alive, true);

}

TEST(arrow_of_archer, negative){
    alive = true;
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);


    p.rect.left = 608;
    p.rect.top = 256;

    float time = -100;
    for (int i = 0; i < 30; i++){
        p.enemy_archer(time, 0);
        time = time - 100;
    }

    ASSERT_EQ((int)p.index_arrows.size(), 0);
    ASSERT_EQ(alive, true);

}
#endif // ARCHER_TEST_H
