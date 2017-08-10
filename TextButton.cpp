#include "TextButton.h"

TextButton::TextButton()
	: sf::Text(), basicColor(sf::Color::Black), newColor(sf::Color::Red), basicCharacterSize(30), resizing(true)
{
	;
}

TextButton::TextButton(const sf::String & string, const sf::Font & font, unsigned int characterSize)
	: sf::Text(string, font, characterSize), basicCharacterSize(characterSize), resizing(true),
	basicColor(sf::Color::White), newColor(sf::Color::Red)
{
	;
}

void TextButton::update(const sf::Vector2f & mousePosition)
{
	if (getGlobalBounds().contains(mousePosition))
	{
		sf::Text::setFillColor(newColor);

		if (resizing)
		{
			sf::Text::setCharacterSize(basicCharacterSize * 1.2);
			setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
		}
	}
	else
	{
		sf::Text::setFillColor(basicColor);

		if (resizing)
		{
			sf::Text::setCharacterSize(basicCharacterSize);
			setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
		}
	}
}

bool TextButton::isHover(const sf::Vector2f & mousePosition) const
{
	return (getGlobalBounds().contains(mousePosition));
}

void TextButton::setCharacterSize(unsigned int size)
{
	sf::Text::setCharacterSize(size);
	basicCharacterSize = size;
}

void TextButton::setFillColor(const sf::Color & color)
{
	sf::Text::setFillColor(color);
	basicColor = color;
}

void TextButton::setHoverColor(const sf::Color & color)
{
	newColor = color;
}

void TextButton::setResizing(bool resize)
{
	resizing = resize;
}
