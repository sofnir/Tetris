#pragma once
#include <SFML\Window\Event.hpp>
#include "GameState.h"
#include "Board.h"
#include "Figure.h"
#include "FiguresFactory.h"
#include "Logic.h"
#include "Dialog.h"
#include "GameplayInfo.h"
#include "TextButton.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	void draw() override;
	void update() override;
	void handleInput() override;

private:	
	Board board;
	FiguresFactory factory;
	Logic logic;
	GameplayInfo info;
	Figure *currentFigure;	
	Dialog *dialog;
	TextButton backButton;
	float delay = 500.0f;

	void createButton();
	void startGame();
};
