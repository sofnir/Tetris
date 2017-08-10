#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

GameStateMenu::GameStateMenu(Game* game)
{
	this->game = game;

	createTitle();
	createButtons();
}

void GameStateMenu::createTitle()
{
	title.setTexture(Data::titleTexture);				
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(Config::windowSize.x / 2.0f, 140.0f);
}

void GameStateMenu::createButtons()
{
	buttons[0] = TextButton("PLAY", Data::font, 55);
	buttons[1] = TextButton("EXIT", Data::font, 55);

	for (int i = 0; i < 2; i++)
	{
		buttons[i].setOrigin(buttons[i].getGlobalBounds().width / 2.0f, buttons[i].getGlobalBounds().height / 2.0f);
		buttons[i].setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, 300.0f + i * 150.0f));
		buttons[i].setFillColor(Color::White);
		buttons[i].setHoverColor(Color::Green);		
	}
}

void GameStateMenu::playGame()
{
	game->pushState(new GameStatePlay(game));
}

void GameStateMenu::draw()
{
	game->window.clear(Color::Grey);
	game->window.draw(title);

	for (auto & button : buttons)
	{
		game->window.draw(button);
	}

	game->window.display();
}

void GameStateMenu::update()
{
	for (auto & button : buttons)
	{
		button.update(game->mousePosition);
	}
}

void GameStateMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->window.close();
			}
			else if (event.key.code == sf::Keyboard::Return)
			{
				playGame();
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttons[0].isHover(game->mousePosition))
				{
					playGame();
				}
				else if (buttons[1].isHover(game->mousePosition))
				{
					game->window.close();
				}
			}
		default:
			break;
		}
	}

	return;
}
