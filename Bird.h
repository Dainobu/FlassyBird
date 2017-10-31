#pragma once
#include <SFML/Graphics.hpp>
class Bird
{
public:
	Bird();
	~Bird();
	void jump();
	void update();
	sf::CircleShape get();
	void draw(sf::RenderWindow *window_p);
private:
	sf::CircleShape bird;
	int yVel;
	int xBird;
	int yBird;
	bool jumped;
};

