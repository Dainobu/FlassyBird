#include "stdafx.h"
#include "CollisionManager.h"
#include "Config.h"
#include <cmath>

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::initialize(Bird *bird, Pipes *pipes)
{
	this->bird = bird;
	this->pipes = pipes;
}

bool CollisionManager::checkCollision()
{
	Pipe *pipe = getNearestPipe();
	sf::RectangleShape rect = whichRectangle(pipe);

	return hasCollided(rect);
}

Pipe* CollisionManager::getNearestPipe()
{
	return pipes->getNearestPipe(bird);
}

bool CollisionManager::hasCollided(sf::RectangleShape rect)
{
	std::pair<int, int> closestRectPoint = getNearestRectPoint(rect);

	int x = closestRectPoint.first - bird->getX();
	int y = closestRectPoint.second - bird->getY();

	int distSquared = std::pow(x, 2) + std::pow(y, 2);

	if (distSquared < std::pow(bird->getBirdShape().getRadius(), 2)) {
		return true;
	}

	return false;
}
	
sf::RectangleShape CollisionManager::whichRectangle(Pipe *pipe)
{
	sf::RectangleShape rect = pipe->getT();

	if (std::abs(pipe->getT().getSize().y - bird->getY()) > std::abs(pipe->getB().getPosition().y - bird->getY())) {
		rect = pipe->getB();
	}

	return rect;
}

std::pair<int, int> CollisionManager::getNearestRectPoint(sf::RectangleShape rect)
{
	int xLeft = rect.getPosition().x;
	int xRight = xLeft + rect.getSize().x;
	int yTop = rect.getPosition().y;
	int yBottom = yTop + rect.getSize().y;
	
	int closestX;
	int closestY;

	if (bird->getX() < xLeft) {
		closestX = xLeft;
	} else if (bird->getX() > xLeft && bird->getX() < xRight) {
		closestX = bird->getX();
	}
	else {
		closestX = xRight;
	}

	if (bird->getY() > yBottom) {
		closestY = yBottom;
	}
	else if (bird->getY() < yBottom && bird->getY() > yTop) {
		closestY = bird->getY();
	}
	else {
		closestY = yTop;
	}

	return std::pair<int, int>(closestX, closestY);
}
