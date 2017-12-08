#include "stdafx.h"
#include "Pipe.h"
#include "Config.h"

Pipe::Pipe()
{
	yPipeTop = 0;
	yPipeBottom = config::SCREEN_HEIGHT * 0.75;
	xPipe = config::SCREEN_WIDTH;

	pipeTop.setSize(sf::Vector2f(PIPE_WIDTH, config::SCREEN_HEIGHT * 0.25));
	pipeTop.setPosition(xPipe, yPipeTop);
	pipeTop.setFillColor(sf::Color(255, 0, 0));

	pipeBottom.setSize(sf::Vector2f(PIPE_WIDTH, config::SCREEN_HEIGHT * 0.25));
	pipeBottom.setPosition(xPipe, yPipeBottom);
	pipeBottom.setFillColor(sf::Color(255, 0, 0));

	xVel = -5;
}


Pipe::~Pipe()
{
}


void Pipe::update()
{
	xPipe += xVel;

	pipeTop.setPosition(xPipe, yPipeTop);
	pipeBottom.setPosition(xPipe, yPipeBottom);
}


sf::RectangleShape Pipe::getT()
{
	return pipeTop;
}


sf::RectangleShape Pipe::getB()
{
	return pipeBottom;
}

int Pipe::getX()
{
	return xPipe;
}



void Pipe::setX(int xPos)
{
	xPipe = xPos;
}


void Pipe::draw(sf::RenderWindow *window_p)
{
	window_p->draw(pipeTop);
	window_p->draw(pipeBottom);
}