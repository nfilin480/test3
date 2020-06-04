#ifndef UPDATE_TEST_H
#define UPDATE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <SFML/Graphics.hpp>


extern "C++" {
#include "../app/helper.h"
}

TEST(update, jump){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 32;
    p.rect.top = 416;

    p.dx = 0;
    p.dy = -0.3;
    p.onGround = false;
    float time = 100;
    for (int i = 0; i < 30; i++){
        p.update(time);
        time = time + 100;
    }
    ASSERT_EQ(p.rect.left, 32);

}
TEST(update, negative){
    sf::Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

    sf::Texture a;
    a.loadFromFile(SPRITE"/archer.png");

    PLAYER p(t, a);

    p.rect.left = 32;
    p.rect.top = 416;

    p.dx = 0;
    p.dy = 0.3;
    p.onGround = true;
    alive = true;
    float time = 100;
    for (int i = 0; i < 30; i++){
        p.update(time);
        time = time + 100;
    }
    ASSERT_EQ(p.rect.left, 32);
    ASSERT_EQ(alive, false);

}


#endif // UPDATE_TEST_H
