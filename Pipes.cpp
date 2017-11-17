#include "stdafx.h"
#include "Pipes.h"

Pipes::Pipes()
{
	pipes[0].setX(config::SCREEN_WIDTH * 0.2);
	pipes[1].setX(config::SCREEN_WIDTH * 0.6);
	pipes[2].setX(config::SCREEN_WIDTH);
}


Pipes::~Pipes()
{
}


void Pipes::update()
{
	for (int i = 0; i < NUM_PIPES; i++)
	{
		if (pipes[i].getX() == -Pipe::PIPE_WIDTH) {
			int lastPipeIndex = (i + 2) % 3;
			pipes[i].setX(pipes[lastPipeIndex].getX() + DISTANCE);
		}
		
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