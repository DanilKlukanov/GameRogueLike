#include "Wall.h"

Wall::Wall(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {}

Wall::~Wall() = default;

void Wall::MoveActor(std::map<Position, std::shared_ptr<Actor>>&)
{

}

void Wall::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	actor->Collide(this, game_elements);
}

void Wall::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	game_elements.erase(bullet->GetPos());
}

void Wall::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Wall::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Wall::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Wall::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Wall::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Wall::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Wall::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>&)
{
}
