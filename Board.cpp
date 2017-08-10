#include "Board.h"

Board::Board()
{
	createFrame();
	block.setTexture(Data::blocksTexture);
}

void Board::draw(sf::RenderWindow & window)
{
	window.draw(frame);

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (logic[i][j] > 0)
			{
				block.setTextureRect(sf::IntRect((logic[i][j] - 1) * blockSize, 0, blockSize, blockSize));
				block.setPosition(sf::Vector2f(frame.getGlobalBounds().left + blockSize * j, frame.getGlobalBounds().top + blockSize * i));
				window.draw(block);
			}
		}
	}
}

void Board::checkIsRowsFully(Logic & gameLogic)
{
	// delate blocks if fully in any row 
	int count = 0;

	for (int i = HEIGHT - 1; i > 0; i--)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (logic[i][j] != 0)
			{
				count++;
			}
		}							

		if (count == 10)
		{
			for (int k = i; k > 0; k--)
			{
				for (int j = 0; j < WIDTH; j++)
				{
					logic[k][j] = logic[k - 1][j];
				}					
			}				

			gameLogic.updatePoints();
		}

		count = 0;
	}
}

void Board::reset()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			logic[i][j] = 0;
		}
	}
}

void Board::createFrame()
{
	frame.setSize(sf::Vector2f(10.0f * blockSize, 20.0f * blockSize));
	frame.setPosition(sf::Vector2f(15, 15));
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineColor(Color::Blue);
	frame.setOutlineThickness(1);
}