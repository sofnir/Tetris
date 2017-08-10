#pragma once
#include <iostream>

class Logic
{
public:
	Logic();
	
	const enum class State {PLAYING, END};

	void setState(const State & newState) { state = newState; }	
	void randNextFigure();
	void reset();
	void updatePoints();

	const State & getState() const { return state; }
	int getCurrentFigure() const { return currentFigure; }
	int getNextFigure() const { return nextFigure; }
	int getPoints() const { return points; }
	int getLines() const { return lines; }
	int getLevel() const { return level; }

private:
	State state = State::PLAYING;
	int currentFigure;
	int nextFigure;
	int points = 0;
	int level = 0;
	int lines = 0;

	int randNumber() const;	
};