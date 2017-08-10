#include "Data.h"

sf::Font Data::font;
sf::Texture Data::titleTexture;
sf::Texture Data::blocksTexture;
sf::Texture Data::figuresTexture;

Data::Data()
{
	font.loadFromFile("Data/font.ttf");

	titleTexture.loadFromFile("Data/title.png");
	titleTexture.setSmooth(true);

	blocksTexture.loadFromFile("Data/blocks.png");
	blocksTexture.setSmooth(true);

	figuresTexture.loadFromFile("Data/figures.png");
	figuresTexture.setSmooth(true);
}