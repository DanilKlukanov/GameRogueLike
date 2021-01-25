#include "Spike.h"

Spike::Spike(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {}

Spike::~Spike() = default;

void Spike::MoveActor(std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Spike::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	actor->Collide(this, game_elements);
}

void Spike::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	game_elements.erase(bullet->GetPos());
}

void Spike::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Spike::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Spike::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Spike::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Spike::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	player->SetHp(std::max(0, player->GetHp() - GetDamage()));
	if (player->GetHp() == 0) {
		game_elements.erase(player->GetPos());
		SetLose(true);
	}
}

void Spike::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Spike::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>&)
{
}
