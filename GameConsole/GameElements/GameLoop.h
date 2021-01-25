#pragma once
#include <thread>
#include "GameMap.h"

class GameLoop
{
public:
	GameLoop();

	void Play();

	void EndGame();
	
private:
	GameMap map;
	bool game_result = false;
};

