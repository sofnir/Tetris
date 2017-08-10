#pragma once
#include "SFML\System\Vector2.hpp"
#include "Board.h"

class Figure
{
public:
	Figure(const sf::Vector2u positions[4], int number, bool rotating);
	const sf::Vector2u getPositions(int i) const { return blockPositions[i]; }
	
	enum class Direction { Down, Left, Right };
	void move(Board & board, const Direction & d);
	void rotate(Board & board);	
	bool isDownCollision() const { return downCollision; }	
	bool addToTheBoard(Board & board);

private:
	sf::Vector2u blockPositions[4];
	bool downCollision = false;
	bool canBeRotate = true;
	int value = 1;

	void clearPositions(Board & board);
	void moveBlocks(Board & board, const sf::Vector2i & movingVector);
	void updateBoardLogic(Board & board);

	bool isFigureCollision(Board & board, const sf::Vector2i & movingVector) const;
	bool canMoveRight(Board & board) const;
	bool canMoveLeft(Board & board) const;
	bool canMoveDown(Board & board) const;
	bool isOwnBlock(const sf::Vector2u & position) const;
};