#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;	

	createButton();	
	startGame();
}

void GameStatePlay::draw()
{
	game->window.clear(Color::Grey);		
	board.draw(game->window);
	game->window.draw(info);
	game->window.draw(backButton);	

	if (dialog)
	{
		game->window.draw(*dialog);
	}

	game->window.display();
}

void GameStatePlay::update()
{
	backButton.update(game->mousePosition);

	if (logic.getState() == Logic::State::PLAYING)
	{
		if (game->clock.getElapsedTime().asMilliseconds() > delay)
		{
			// move
			currentFigure->move(board, Figure::Direction::Down);

			// create new figures
			if (currentFigure->isDownCollision())
			{
				logic.randNextFigure();
				info.update(logic.getPoints(), logic.getLines(), logic.getLevel(), logic.getNextFigure());
				currentFigure = factory.create(logic.getCurrentFigure());

				// add figure to the board
				if (!currentFigure->addToTheBoard(board))
				{
					// if can't add figure - game over
					logic.setState(Logic::State::END);
					dialog = new Dialog();
				}				
			}

			// check are any lines fully
			board.checkIsRowsFully(logic);
			game->clock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			delay = 20.0f;
		}
		else
		{
			delay = 500.0f;
		}
	}
}

void GameStatePlay::handleInput()
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
				game->popState();
				return;
			}
			else if (event.key.code == sf::Keyboard::Space && logic.getState() == Logic::State::END)
			{
				dialog = nullptr;

				logic.reset();
				board.reset();				
				startGame();
				info.update(logic.getPoints(), logic.getLines(), logic.getLevel(), logic.getNextFigure());
			}

			if (logic.getState() == Logic::State::PLAYING && currentFigure)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					currentFigure->move(board, Figure::Direction::Left);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					currentFigure->move(board, Figure::Direction::Right);
				}
				else if (event.key.code == sf::Keyboard::Up)
				{
					currentFigure->rotate(board);
				}
			}			
			break;
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{							
				if (backButton.isHover(game->mousePosition))
				{
					game->popState();
					return;
				}
			}
		}
		default: break;
		}
	}

	return;
}

void GameStatePlay::createButton()
{
	backButton = TextButton("BACK", Data::font, 30);			
	backButton.setOrigin(backButton.getGlobalBounds().width / 2, backButton.getGlobalBounds().height);
	backButton.setPosition(450, 55 + 4 * 130);
	backButton.setFillColor(Color::White);
	backButton.setHoverColor(Color::Green);
}

void GameStatePlay::startGame()
{
	currentFigure = factory.create(logic.getCurrentFigure());
	currentFigure->addToTheBoard(board);
	info.update(logic.getPoints(), logic.getLines(), logic.getLevel(), logic.getNextFigure());
}
