#include "Heart.h"

Heart::Heart(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {}

Heart::~Heart() = default;

void Heart::MoveActor(std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Heart::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	actor->Collide(this, game_elements);
}

void Heart::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	bullet->Collide(this, game_elements);
}

void Heart::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Heart::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Heart::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Heart::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Heart::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	player->Collide(this, game_elements);
}

void Heart::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Heart::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>&)
{
}
