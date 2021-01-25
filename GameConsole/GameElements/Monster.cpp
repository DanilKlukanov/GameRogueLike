#include "Monster.h"

Monster::Monster(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {}

Monster::~Monster() = default;

void Monster::MoveActor(std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	int coord_x[4] = { -1, 1, 0, 0 };
	int coord_y[4] = { 0, 0, -1, 1 };
	int random_coord = rand() % 4;

	Position new_pos(GetPos().x + coord_x[random_coord], GetPos().y + coord_y[random_coord]);
	Position old_pos = GetPos();
    auto element = game_elements.find(new_pos);
    if (element != game_elements.end()) {
        Collide(element->second.get(), game_elements);
    }
    else {
        game_elements[new_pos] = game_elements[old_pos];
        game_elements.erase(old_pos);
        SetPos(new_pos);
    }
}

void Monster::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    actor->Collide(this, game_elements);
}

void Monster::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    bullet->Collide(this, game_elements);
}

void Monster::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Monster::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Monster::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Monster::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Monster::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    player->SetHp(std::max(0,player->GetHp() - this->GetDamage()));
    if (player->GetHp() == 0) {
        game_elements.erase(player->GetPos());
        SetLose(true);
        player->SetLose(true);
    }
}

void Monster::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Monster::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>&)
{
}