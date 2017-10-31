#pragma once
#include "Bird.h"
#include "Pipes.h"
#include <SFML/Graphics.hpp>
class App
{
public:
	App();
	~App();
	void run();
	void handleInput();
	void jump();
	void updateGame();
	void renderGame();
	
private:
	sf::RenderWindow *window_p;
	Bird bird;
	Pipes pipes;
};