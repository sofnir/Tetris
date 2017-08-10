#pragma once
#include "SFML\System\Vector2.hpp"
#include "Figure.h"
#include "Board.h"

class FiguresFactory
{
public:
	FiguresFactory();	

	Figure * create(int number) const;

private:
	sf::Vector2u figure_I[4] = { { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } };
	sf::Vector2u figure_L[4] = { { 0,1 },{ 1,1 },{ 2,1 },{ 2,0 } };
	sf::Vector2u figure_J[4] = { { 0,0 },{ 0,1 },{ 1,1 },{ 2,1 } };
	sf::Vector2u figure_O[4] = { { 1,0 },{ 2,0 },{ 1,1 },{ 2,1 } };
	sf::Vector2u figure_S[4] = { { 0,1 },{ 1,1 },{ 1,0 },{ 2,0 } };
	sf::Vector2u figure_Z[4] = { { 0,0 },{ 1,0 },{ 1,1 },{ 2,1 } };
	sf::Vector2u figure_T[4] = { { 0,1 },{ 1,1 },{ 1,0 },{ 2,1 } };
};