#include "GameplayInfo.h"

GameplayInfo::GameplayInfo()
{
	nextFigure.setTexture(Data::figuresTexture);
	nextFigure.setOrigin(nextFigure.getGlobalBounds().width / 14, nextFigure.getLocalBounds().height / 2);
	nextFigure.setRotation(90);
	nextFigure.setPosition(450, 65);

	createFrames();
	createTexts();
}

void GameplayInfo::draw(sf::RenderTarget & target, sf::RenderStates) const
{
	target.draw(nextFigure);

	for (auto & frame : frames)
	{
		target.draw(frame);
	}

	for (auto & text : texts)
	{
		target.draw(text);
	}
}

void GameplayInfo::update(int points, int lines, int level, int nextFigureIndex)
{
	nextFigure.setTextureRect(sf::IntRect((nextFigureIndex - 1) * 64, 0, 64, 128));
	texts[0].setString("Level : " + std::to_string(level));
	texts[1].setString("Scores : " + std::to_string(points));
	texts[2].setString("Lines : " + std::to_string(lines));
}

void GameplayInfo::createFrames()
{
	for (int i = 0; i < 4; i++)
	{
		frames[i].setSize(sf::Vector2f(200, 100));
		frames[i].setOutlineThickness(1);
		frames[i].setOutlineColor(Color::Blue);
		frames[i].setFillColor(sf::Color::Transparent);
		frames[i].setPosition(350.0f, 15.0f + i * 130.0f);
	}
}

void GameplayInfo::createTexts()
{
	texts[0].setString("Level : 1");
	texts[1].setString("Scores : 0");
	texts[2].setString("Lines : 0");

	for (int i = 0; i < 3; i++)
	{
		texts[i].setFont(Data::font);
		texts[i].setCharacterSize(30);
		texts[i].setFillColor(Color::White);
		texts[i].setOrigin(texts[i].getGlobalBounds().width / 2, texts[i].getGlobalBounds().height / 2);
		texts[i].setPosition(450, 55 + (i + 1) * 130);
	}
}
