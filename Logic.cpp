#include "Logic.h"

Logic::Logic()
{
	currentFigure = randNumber();
	nextFigure = randNumber();
}

void Logic::randNextFigure()
{
	currentFigure = nextFigure;
	nextFigure = randNumber();
}

void Logic::reset()
{
	state = State::PLAYING;
	points = 0;
	level = 0;
	lines = 0;

	currentFigure = randNumber();
	nextFigure = randNumber();
}

void Logic::updatePoints()
{
	points++;
	lines++;

	if (points % 10 == 0)
	{
		level++;
	}
}

int Logic::randNumber() const
{
	int number = rand() % 7 + 1;

	return number;
}
