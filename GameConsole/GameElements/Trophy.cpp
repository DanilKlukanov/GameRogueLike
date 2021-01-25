#include "Trophy.h"

Trophy::Trophy(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {}

Trophy::~Trophy() = default;

void Trophy::MoveActor(std::map<Position, std::shared_ptr<Actor>>&)
{

}

void Trophy::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	actor->Collide(this, game_elements);
}

void Trophy::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	game_elements.erase(bullet->GetPos());
}

void Trophy::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Trophy::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Trophy::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Trophy::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Trophy::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	SetWin(true);
}

void Trophy::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Trophy::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>&)
{
}
