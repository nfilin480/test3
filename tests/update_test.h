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
    for (float time = 100; time < 3000; time+=100)
        p.update(time);
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
    for (float time = 100; time < 3000; time+=100)
        p.update(time);
    ASSERT_EQ(p.rect.left, 32);
    ASSERT_EQ(alive, false);

}


#endif // UPDATE_TEST_H
