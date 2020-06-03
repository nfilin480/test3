#ifndef HELPER_H
#define HELPER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "global_vars.h"

using namespace std;
using namespace sf;

class PLAYER {

public:

    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite hero;
    Sprite archer;
    float currentFrame;
    float frame_archer;
    vector<float> dx_arrows;
    vector<float> dy_arrows;
    vector<FloatRect> index_arrows;
    vector<float> angle;

    float dx_knives;
    float dy_knives;

    PLAYER(Texture& image, Texture& a)
    {
        hero.setTexture(image);
        rect = FloatRect(32, 32, 32, 64);
        archer.setTexture(a);
        dx = dy = 0.1;
        currentFrame = 0;
        frame_archer = 0;
    }


    void update(float time)
    {

        rect.left += dx * time;
        Collision(0);

        if (!onGround) {
            dy = dy + 0.0005 * time;
        }
        rect.top += dy * time;
        onGround = false;

        Collision(1);

        currentFrame += 0.01 * time;
        if (currentFrame > 10) currentFrame -= 10;

        if (dx > 0) hero.setTextureRect(IntRect(32 * int(currentFrame), 64, 32, 64));
        if (dx < 0) hero.setTextureRect(IntRect(32 * int(currentFrame) + 32, 64, -32, 64));
        if (dx == 0) hero.setTextureRect(IntRect(32 * int(currentFrame), 0, 32, 64));
        if (dy < 0 && dx > 0) hero.setTextureRect(IntRect(32 * int(currentFrame), 128, 32, 64));
        if (dy < 0 && dx < 0) hero.setTextureRect(IntRect(32 * int(currentFrame) + 32, 128, -32, 64));

        if (alive == false) {
            currentFrame -= 0.008 * time;
            hero.setTextureRect(IntRect(32 * int(currentFrame), 192, 32, 64));
        }
        hero.setPosition(rect.left - offsetX, rect.top);


        dx = 0;
    }



    int Collision(int dir)
    {
        for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
            for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
            {
                if(i < 0 || j < 0 || i > 22 || j > 202 || m[i][j] == -1){
                    alive = false;
                    return 0;
                }
                if (m[i][j] == 1)
                {
                    if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
                    if ((dx < 0) && (dir == 0)) rect.left = j * 32 + rect.width;
                    if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
                    if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
                }

            }
        return 1;
    }

    void enemy_archer(float time,int i) {
        int flag = 0;
        frame_archer += 0.001 * time;
        if (frame_archer >= 10) {
            frame_archer -= 10;
            flag = 1;
        }
        if (abs(place_archers[i].left - rect.left) < 380 && place_archers[i].left - rect.left > 0) {
            if (frame_archer + 0.003 * time > 10) flag = 2;
            archer.setTextureRect(IntRect(32 * int(frame_archer), 64, 32, 64));
        }
        if (abs(place_archers[i].left - rect.left) < 380 && place_archers[i].left - rect.left < 0) {
            if (frame_archer + 0.003 * time > 10) flag = 2;
            archer.setTextureRect(IntRect(32 * int(frame_archer) + 32, 64, -32, 64));
        }
        if (abs(place_archers[i].left - rect.left) > 380) archer.setTextureRect(IntRect(32 * int(frame_archer), 0, 32, 64));
        archer.setPosition(place_archers[i].left - offsetX, place_archers[i].top);

        if (flag == 2) {
            index_arrows.push_back(FloatRect(place_archers[i].left, place_archers[i].top, 32, 16));
            dx_arrows.push_back((rect.left / 32 - place_archers[i].left / 32) * 1 * 0.005);
            dy_arrows.push_back((rect.top / 32 - place_archers[i].top / 32) * 1 * 0.005);
            angle.push_back((place_archers[i].left - rect.left)/ (rect.top - place_archers[i].top));
        }

    }
};

#endif // HELPER_H
