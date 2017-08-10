#include "Figure.h"
#include <iostream>

Figure::Figure(const sf::Vector2u positions[4], int number, bool rotating)
{	
	for (int i = 0; i < 4; i++)
	{
		blockPositions[i] = sf::Vector2u(positions[i].x + 3, positions[i].y);
	}

	value = number;
	canBeRotate = rotating;
}

void Figure::move(Board & board, const Direction & d)
{
	sf::Vector2i movingVector;

	if (d == Direction::Down)
	{
		movingVector = sf::Vector2i{ 0, 1 };

		if (!canMoveDown(board) || isFigureCollision(board, movingVector))
		{
			downCollision = true;
			return;
		}				
	}	
	else if (d == Direction::Left && canMoveLeft(board))
	{
		movingVector = sf::Vector2i{ -1, 0 };		
	}
	else if (d == Direction::Right && canMoveRight(board))
	{
		movingVector = sf::Vector2i{ 1, 0 };
	}

	if (!isFigureCollision(board, movingVector))
	{
		clearPositions(board);
		moveBlocks(board, movingVector);
		updateBoardLogic(board);
	}
}

void Figure::clearPositions(Board & board)
{
	for (int i = 0; i < 4; i++)
	{
		board.logic[blockPositions[i].y][blockPositions[i].x] = 0;
	}
}

void Figure::moveBlocks(Board & board, const sf::Vector2i & movingVector)
{
	for (int i = 0; i < 4; i++)
	{
		blockPositions[i] = blockPositions[i] + sf::Vector2u(movingVector);
	}
}

void Figure::updateBoardLogic(Board & board)
{
	for (int i = 0; i < 4; i++)
	{
		board.logic[blockPositions[i].y][blockPositions[i].x] = value;
	}
}

void Figure::rotate(Board & board)
{
	if (!canBeRotate)
	{
		return;
	}

	sf::Vector2u newPosition[4];
	sf::Vector2u centerBlock = blockPositions[1];

	for (int i = 0; i < 4; i++)
	{
		int x = blockPositions[i].x - centerBlock.x;
		int y = blockPositions[i].y - centerBlock.y;

		newPosition[i].x = centerBlock.x - y;
		newPosition[i].y = centerBlock.y + x;
	}

	for (int i = 0; i < 4; i++)
	{		
		if (board.logic[newPosition[i].y][newPosition[i].x] != 0 && !isOwnBlock(newPosition[i]) ||
			newPosition[i].x < 0 || newPosition[i].x > 9 || newPosition[i].y < 0 || newPosition[i].y > 19)
		{
			return;
		}
	}

	clearPositions(board);
		
	for (int i = 0; i < 4; i++)
	{
		blockPositions[i] = newPosition[i];
	}

	updateBoardLogic(board);			
}

bool Figure::addToTheBoard(Board & board)
{
	for (int i = 0; i < 4; i++)
	{
		if (board.logic[blockPositions[i].y][blockPositions[i].x] != 0)
		{
			return false;
		}
	}

	updateBoardLogic(board);

	return true;
}

bool Figure::isFigureCollision(Board & board, const sf::Vector2i & movingVector) const
{
	sf::Vector2u newPositions[4];	

	for (int i = 0; i < 4; i++)
	{
		newPositions[i] = blockPositions[i] + sf::Vector2u(movingVector);	

		if (board.logic[newPositions[i].y][newPositions[i].x] != 0 && !isOwnBlock(newPositions[i]))
		{
			return true;
		}
	}

	return false;
}

bool Figure::canMoveRight(Board & board) const
{
	for (int i = 0; i < 4; i++)
	{
		// figure is near the wall
		if (blockPositions[i].x >= board.WIDTH - 1)
		{
			return false;
		}		
	}

	return true;
}

bool Figure::canMoveLeft(Board & board) const
{
	for (int i = 0; i < 4; i++)
	{
		// figure is near the wall
		if (blockPositions[i].x <= 0)
		{
			return false;
		}
	}

	return true;
}

bool Figure::canMoveDown(Board & board) const
{
	for (int i = 0; i < 4; i++)
	{
		// figure is near the floor
		if (blockPositions[i].y >= board.HEIGHT - 1)
		{
			return false;
		}
	}

	return true;
}

bool Figure::isOwnBlock(const sf::Vector2u & position) const
{
	for (int i = 0; i < 4; i++)
	{
		if (position == blockPositions[i])
		{
			return true;
		}
	}

	return false;
}