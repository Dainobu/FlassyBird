#pragma once
#include "Pipe.h"
class Pipes
{
public:
	Pipes();
	~Pipes();
	void update();
	void draw(sf::RenderWindow *window_p);
private:
	const int NUM_PIPES = 3;
	Pipe pipes[3];
};