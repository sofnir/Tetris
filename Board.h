#pragma once
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Data.h"
#include "Logic.h"

class Figure;

class Board
{
	friend Figure;

public:
	Board();

	void draw(sf::RenderWindow & window);
	void checkIsRowsFully(Logic & gameLogic);
	void reset();

private:
	sf::RectangleShape frame;
	sf::Sprite block;
	static const int WIDTH = 10;
	static const int HEIGHT = 20;
	const float blockSize = 32.0f;
	int logic[HEIGHT][WIDTH] = { 0 };

	void createFrame();
};