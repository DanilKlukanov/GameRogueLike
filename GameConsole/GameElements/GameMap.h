#pragma once
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "CreateActor.h"
#include "../curses/curses.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class GameMap
{
public:
	GameMap();

	void ReadConfig();

	void ReadMap();

	void GetGameElementsTypes();

	void DrawMap();

	void PrintStatus();

	int GetRows();

	int GetCols();

private:
	friend class GameLoop;
	json config;
	std::vector<std::string> game_map;
	std::map<Position, std::shared_ptr<Actor>> game_elements;
	std::vector<std::shared_ptr<Actor>> all_elements;
	int rows = 28;
	int cols = 71;
};

