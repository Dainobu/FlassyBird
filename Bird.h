#pragma once
#include <SFML/Graphics.hpp>
class Bird
{
public:
	Bird();
	~Bird();
	void jump();
	void updateBird();
	sf::CircleShape getBird();
private:
	sf::CircleShape bird;
	int yVel;
	int xBird;
	int yBird;
	bool jumped;
};

