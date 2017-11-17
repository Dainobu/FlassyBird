#pragma once
#include "Pipe.h"
#include "Config.h"

class Pipes
{
public:
	Pipes();
	~Pipes();
	void update();
	void draw(sf::RenderWindow *window_p);
private:
	const int NUM_PIPES = 3;
	const double DISTANCE = config::SCREEN_WIDTH * 0.4;
	Pipe pipes[3];
};