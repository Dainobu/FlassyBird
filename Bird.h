#pragma once
#include <SFML/Graphics.hpp>
class Bird
{
public:
	Bird();
	~Bird();
	void jump();
	void update();
	sf::CircleShape getBirdShape();
	void draw(sf::RenderWindow *window_p);
	int getX();
	int getY();
private:
	sf::CircleShape bird;
	int yVel;
	int xBird;
	int yBird;
	bool jumped;
	const int RADIUS = 50;
};

