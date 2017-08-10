#include "Game.h"
#include "GameStateMenu.h"

int main()
{
	srand(time(NULL));

	Game game;
	game.pushState(new GameStateMenu(&game));
	game.gameLoop();

	return 0;
}