#pragma once
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Data.h"

class GameplayInfo : public sf::Drawable
{
public:
	GameplayInfo();
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates) const override;
	void update(int points, int lines, int level, int nextFigureIndex);

private:

	sf::RectangleShape frames[4];
	sf::Text texts[4];
	sf::Sprite nextFigure;

	void createFrames();
	void createTexts();
};

