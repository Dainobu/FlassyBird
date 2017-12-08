#pragma once
#include "Bird.h"
#include "Pipes.h"
#include "Pipe.h"
#include <SFML/Graphics.hpp>
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void initialize(Bird *bird, Pipes *pipes);
	bool checkCollision();
	Pipe *getNearestPipe();
	bool hasCollided(sf::RectangleShape rect);
	sf::RectangleShape whichRectangle(Pipe *pipe);
	std::pair<int, int> getNearestRectPoint(sf::RectangleShape rect);
private:
	Bird *bird;
	Pipes *pipes;
};

