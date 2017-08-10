#include "Dialog.h"

Dialog::Dialog() 
{
	createShape();
	createTexts();
}

void Dialog::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(frame);

	for (int i = 0; i < 2; i++)
	{
		target.draw(text[i]);
	}
}

void Dialog::createShape()
{
	frame.setSize(sf::Vector2f(10 * 32, 20 * 32));
	frame.setFillColor(sf::Color(22, 27, 32, 200));
	frame.setPosition(15.0f, 15.0f);
	frame.setOutlineThickness(1);
	frame.setOutlineColor(Color::Blue);
}

void Dialog::createTexts()
{
	text[0].setString("GAME OVER!");
	text[0].setFillColor(Color::Orange);
	text[0].setCharacterSize(45);
	text[1].setString("Press \"Spacebar\"");
	text[1].setFillColor(Color::Blue);
	text[1].setCharacterSize(25);

	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(Data::font);
		text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height / 2);
		text[i].setPosition(sf::Vector2f(frame.getGlobalBounds().left + frame.getGlobalBounds().width / 2, 
			frame.getGlobalBounds().top + 100 * (i + 1)));
	}
}