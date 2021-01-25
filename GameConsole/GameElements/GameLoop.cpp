#include "GameLoop.h"

GameLoop::GameLoop() = default;

void GameLoop::Play()
{
	while (true) {
		for (auto element = map.all_elements.begin(); element != map.all_elements.end(); element++) {
			if (map.game_elements.find((*element)->GetPos()) != map.game_elements.end()) {
				(*element)->MoveActor(map.game_elements);
			}
		}
		map.all_elements.clear();
		for (auto element = map.game_elements.begin(); element != map.game_elements.end(); element++) {
			if (element->second->GetWin()) {
				game_result = true;
				EndGame();
				return;
			}
			if (element->second->GetLose()) {
				game_result = false;
				EndGame();
				return;
			}
			map.all_elements.push_back(element->second);
;		}
		map.DrawMap();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void GameLoop::EndGame()
{
	clear();
	refresh();

	while (true) {
		if (game_result) {
			mvprintw(map.GetRows() / 2, map.GetCols() / 2, "You have found a prize! I am proud of you");
		}
		else {
			mvprintw(map.GetRows() / 2, map.GetCols() / 2, "I'm sorry. Next time, try to better");
		}
		if (getch() != -1) {
			break;
		}
	}
}
