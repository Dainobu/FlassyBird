#include "stdafx.h"
#include "App.h"
#include "Config.h"

App::App()
{
	// create the window
	window_p = new sf::RenderWindow(sf::VideoMode(config::SCREEN_WIDTH, config::SCREEN_HEIGHT), "My window");
	window_p->setFramerateLimit(60);

	collisionManager.initialize(&bird, &pipes);

	pause = false;
}


App::~App()
{
	if (window_p != nullptr)
		delete window_p;

}


void App::run()
{
	// run the program as long as the window is open
	while (window_p->isOpen())
	{
		handleInput();

		if (!pause) {
			updateGame();
			renderGame();
		}
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
			if (event.key.code == sf::Keyboard::P) {
				pause = !pause;
			}

			if (!pause && event.key.code == sf::Keyboard::Space) {
				bird.jump();
			}
		}
	}
}


void App::updateGame()
{
	// update
	bird.update();
	pipes.update();

	if (collisionManager.checkCollision()) {
		pause = true;
	}
}


void App::renderGame()
{
	// clear the window with black color
	window_p->clear(sf::Color::Black);

	// draw everything here...
	bird.draw(window_p);
	pipes.draw(window_p);

	// end the current frame
	window_p->display();
}
