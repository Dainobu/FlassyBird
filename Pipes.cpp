#include "stdafx.h"
#include "Pipes.h"
#include "Config.h"

Pipes::Pipes()
{
	pipes[0].setX(config::SCREEN_WIDTH * 0.5);
	pipes[1].setX(config::SCREEN_WIDTH * 0.6);
	pipes[2].setX(config::SCREEN_WIDTH * 0.7);
}


Pipes::~Pipes()
{
}


void Pipes::update()
{
	for (int i = 0; i < NUM_PIPES; i++)
	{
		pipes[i].update();
	}
}


void Pipes::draw(sf::RenderWindow *window_p)
{
	for (int i = 0; i < NUM_PIPES; i++)
	{
		pipes[i].draw(window_p);
	}
}