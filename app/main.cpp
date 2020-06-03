#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
#include "helper.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Test!");

	Texture t;
    t.loadFromFile(SPRITE"/ninja.png");

	Sprite ground;
	Texture g;
    g.loadFromFile(SPRITE"/ground_2.png");
	ground.setTexture(g);

	Sprite background;
	Texture b;
    b.loadFromFile(SPRITE"/BG.png");
	background.setTexture(b);

	Texture a;
    a.loadFromFile(SPRITE"/archer.png");

	Sprite arrow;
	Texture arrows;
    arrows.loadFromFile(SPRITE"/arrow.png");
	arrow.setTexture(arrows);

	Sprite k;
	Texture ks;
    ks.loadFromFile(SPRITE"/knife.png");
	k.setTexture(ks);
	vector<Vector2i> knife;
	vector<float> dx_knife;
	vector<float> dy_knife;
	vector<float> angle_knife;

	PLAYER p(t, a);
	p.onGround = false;

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 700;

		if (time > 20) time = 20;

		if (alive == false) {
            //if(p.currentFrame > 9)
			window.close();
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			p.dx = -0.15;

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			p.dx = 0.15;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (p.onGround) { p.dy = -0.3; p.onGround = false; }
		}

		if (Mouse::isButtonPressed(Mouse::Left)) {

			auto a = Mouse::getPosition(window);
            //float x = p.rect.left;
            //float y = p.rect.top;
            //Vector2i hero = { x, y };
            knife.push_back(a);

			dx_knife.push_back((p.rect.left / 32 - a.x / 32) * 1 * 0.005);
			dy_knife.push_back((p.rect.top / 32 - a.y / 32) * 1 * 0.005);
			angle_knife.push_back((a.x - p.rect.left) / (a.y - p.rect.top));
			knives--;
		}

		p.update(time);

		

		if (p.rect.left > 640) offsetX = p.rect.left - 640; 
		if (p.rect.top > 360) offsetY = p.rect.top - 360;

		window.clear(Color::White);
		ground.setPosition(-offsetX, 0);

		
		window.draw(background);
		window.draw(ground);
        for (int j = 0; j < (int)place_archers.size();j++) {
			p.enemy_archer(time, j);
			window.draw(p.archer);



			if (p.index_arrows.size() > 0) {
                for (int i = 0;i < (int)p.index_arrows.size();i++) {
					arrow.setPosition((p.index_arrows[i].left += p.dx_arrows[i]) - offsetX, (p.index_arrows[i].top += p.dy_arrows[i]));
					arrow.setRotation(atan(p.angle[i]) * 180.0 / 3.14 + 270);
					if (int((p.index_arrows[i].left + 16) / 32) == int((p.rect.left + 16) / 32) && int((p.index_arrows[i].top + 8) / 32) == int((p.rect.top + 16) / 32)) alive = false;

					if (p.index_arrows[i].top > 720) {
						auto it = p.index_arrows.begin();
						for(int g = 0; g < i - 1;g++)
							*it++;
						p.index_arrows.erase(it);
						auto it_1 = p.dx_arrows.begin();
						for (int g = 0; g < i - 1;g++)
							*it_1++;
						p.dx_arrows.erase(it_1);
						auto it_2 = p.dy_arrows.begin();
						for (int g = 0; g < i - 1;g++)
							*it_2++;
						p.dy_arrows.erase(it_2);
						auto it_3 = p.angle.begin();
						for (int g = 0; g < i - 1;g++)
							* it_3++;
						p.angle.erase(it_3);
					}
					window.draw(arrow);
				}
			}
		}

        for (int i = 0;i < (int)dx_knife.size();i++) {
			k.setPosition((knife[i].x += dx_knife[i]) - offsetX, (knife[i].y += dx_knife[i]));
			k.setRotation(atan(angle_knife[i]) * 180.0 / 3.14 + 270);
			window.draw(k);
		}




		window.draw(p.hero);
		window.display();
	}

	return 0;
}
