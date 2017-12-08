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
	int getYPipeTop();
	int getYPipeBottom();
	int getX();
	void setX(int xPos);
	void draw(sf::RenderWindow *window_p);
	static const int PIPE_WIDTH = 100;
private:
	sf::RectangleShape pipeTop;
	sf::RectangleShape pipeBottom;
	int xVel;
	int xPipe;
	int yPipeTop;
	int yPipeBottom;
};

