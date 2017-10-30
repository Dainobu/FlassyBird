#include "stdafx.h"
#include "Bird.h"


Bird::Bird()
{
	xBird = 750;
	yBird = 450;

	bird.setRadius(50);
	bird.setPosition(xBird, yBird);
	bird.setFillColor(sf::Color(0, 0, 255));

	yVel = 0;

	jumped = false;
}


Bird::~Bird()
{
}


void Bird::jump()
{
	jumped = true;
}


void Bird::updateBird()
{
	if (yVel != 20 && jumped == false) {
		yVel++;
	}
	else if (jumped == true) {
		yVel = -25;

		jumped = false;
	}

	yBird += yVel;

	bird.setPosition(xBird, yBird);
}


sf::CircleShape Bird::getBird()
{
	return bird;
}