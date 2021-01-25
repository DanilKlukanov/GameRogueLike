#include "GameMap.h"

GameMap::GameMap()
{
    ReadConfig();
    ReadMap();
    GetGameElementsTypes();
}

void GameMap::ReadConfig()
{
    std::ifstream fin("Config.json");
    fin >> config;
    fin.close();
}

void GameMap::ReadMap()
{
    std::string line;
    std::ifstream fin("Map.txt");
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            game_map.push_back(line);
        }
    }
    fin.close();
}

void GameMap::GetGameElementsTypes()
{
    for (int row = 0; row < GetRows(); row++) {
        for (int col = 0; col < GetCols(); col++) {
            char element = game_map[row][col];
            if (element != 32) {
                Position pos(row, col);
                std::string name;
                name.push_back(element);
                game_elements[pos] = CreateActor::Create(
                    pos,
                    element,
                    config[name]["hp"],
                    config[name]["max_hp"],
                    config[name]["damage"],
                    config[name]["hit_damage"]);
            }
        }
    }
    for (auto element = game_elements.begin(); element != game_elements.end(); element++) {
        all_elements.push_back(element->second);
    }
}

void GameMap::DrawMap()
{
    clear();
	for (int row = 0; row < GetRows(); row++) {
		for (int col = 0; col < GetCols(); col++) {
            Position pos(row, col);
            auto object = game_elements.find(pos);
            if (object != game_elements.end()) {
                mvaddch(row, col, object->second->GetSym());
            }
		}
	}

    PrintStatus();
    refresh();
}

void GameMap::PrintStatus()
{
    std::shared_ptr<Player> player;
    for (auto element = game_elements.begin(); element != game_elements.end(); element++) {
        player = std::dynamic_pointer_cast<Player>(element->second);
        if (player) {
            break;
        }
    };
    mvprintw(1, GetCols() + 2, "Information");
    mvprintw(3, GetCols() + 2, ("Hearts: " + std::to_string(player->GetHp()) + "/" + std::to_string(player->GetMaxHp())).c_str());
    mvprintw(5, GetCols() + 2, ("Shoot damage: " + std::to_string(player->GetHitDamage())).c_str());
}

int GameMap::GetRows()
{
    return rows;
}

int GameMap::GetCols()
{
    return cols;
}
