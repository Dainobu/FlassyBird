#include "stdafx.h"
#include "App.h"


App::App()
{
	// create the window
	window_p = new sf::RenderWindow(sf::VideoMode(1600, 1000), "My window");
	window_p->setFramerateLimit(60);
}


App::~App()
{
}


void App::run()
{
	// run the program as long as the window is open
	while (window_p->isOpen())
	{
		handleInput();
		updateGame();
		renderGame();
	}
}

void App::handleInput()
{
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (window_p->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			window_p->close();

		// "jump requested" event: the bird jumps
		if (event.type == sf::Event::KeyPressed) {
			bird.jump();
		}
	}
}


void App::updateGame()
{
	// update
	bird.updateBird();
}


void App::renderGame()
{
	// clear the window with black color
	window_p->clear(sf::Color::Black);

	// draw everything here...
	window_p->draw(bird.getBird()); // TODO (DVU): wtf?

	// end the current frame
	window_p->display();
}