#pragma once
#include <SFML/Graphics.hpp>
class Pipe
{
public:
	Pipe();
	~Pipe();
	void update();
	sf::RectangleShape getT();
	sf::RectangleShape getB();
	void setTHeight(int height);
	void setBHeight(int height);
	void setX(int xPos);
	void draw(sf::RenderWindow *window_p);
private:
	sf::RectangleShape pipeT;
	sf::RectangleShape pipeB;
	int xVel;
	int xPipe;
	int yPipeT;
	int yPipeB;
};

