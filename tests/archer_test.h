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

    p.rect.left = 96;
    p.rect.top = 480;

    ASSERT_EQ(p.Collision(0), 1);
    ASSERT_EQ(p.Collision(1), 1);

    ASSERT_EQ(p.rect.top, 416);
    ASSERT_EQ(p.rect.left, 96);
    ASSERT_EQ(alive, true);

}

#endif // ARCHER_TEST_H
