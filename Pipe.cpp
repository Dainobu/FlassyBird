#include "stdafx.h"
#include "Pipe.h"
#include "Config.h"

Pipe::Pipe()
{
	yPipeT = 0;
	yPipeB = config::SCREEN_HEIGHT * 0.75;
	xPipe = config::SCREEN_WIDTH;

	pipeT.setSize(sf::Vector2f(100, config::SCREEN_HEIGHT * 0.25));
	pipeT.setPosition(xPipe, yPipeT);
	pipeT.setFillColor(sf::Color(255, 0, 0));

	pipeB.setSize(sf::Vector2f(100, config::SCREEN_HEIGHT * 0.25));
	pipeB.setPosition(xPipe, yPipeB);
	pipeB.setFillColor(sf::Color(255, 0, 0));

	xVel = -5;
}


Pipe::~Pipe()
{
}


void Pipe::update()
{
	xPipe += xVel;

	pipeT.setPosition(xPipe, yPipeT);
	pipeB.setPosition(xPipe, yPipeB);
}


sf::RectangleShape Pipe::getT()
{
	return pipeT;
}


sf::RectangleShape Pipe::getB()
{
	return pipeB;
}


void Pipe::setTHeight(int height)
{

}


void Pipe::setBHeight(int height)
{

}


void Pipe::setX(int xPos)
{
	xPipe = xPos;
}


void Pipe::draw(sf::RenderWindow *window_p)
{
	window_p->draw(pipeT);
	window_p->draw(pipeB);
}