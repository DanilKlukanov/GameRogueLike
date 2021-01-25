#include "Bullet.h"

Bullet::Bullet(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {
	coordinates[118] = Position(1, 0);
	coordinates[94] = Position(-1, 0);
	coordinates[60] = Position(0, -1);
	coordinates[62] = Position(0, 1);
}

Bullet::~Bullet() = default;

void Bullet::MoveActor(std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	Position old_pos = GetPos();
	Position new_pos(coordinates[GetSym()].x + old_pos.x, coordinates[GetSym()].y + old_pos.y);
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

void Bullet::Collide(Actor * actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	actor->Collide(this, game_elements);
}

void Bullet::Collide(Bullet * bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	game_elements.erase(this->GetPos());
}

void Bullet::Collide(Heart * heart, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	game_elements.erase(heart->GetPos());
	game_elements.erase(this->GetPos());
}

void Bullet::Collide(Spike * spike, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	spike->Collide(this, game_elements);
}

void Bullet::Collide(Trophy * trophy, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	trophy->Collide(this, game_elements);
}

void Bullet::Collide(Wall * wall, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	wall->Collide(this, game_elements);
}

void Bullet::Collide(Player * player, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	player->SetHp(std::max(0, player->GetHp() - GetDamage()));
	if (player->GetHp() == 0) {
		game_elements.erase(player->GetPos());
		player->SetLose(true);
		SetLose(true);
	}
	game_elements.erase(this->GetPos());
}

void Bullet::Collide(Monster * monster, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	monster->SetHp(std::max(0, monster->GetHp() - GetDamage()));
	if (monster->GetHp() == 0) {
		game_elements.erase(monster->GetPos());
	}
	game_elements.erase(this->GetPos());
}

void Bullet::Collide(Skeleton * skeleton, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	skeleton->SetHp(std::max(0, skeleton->GetHp() - GetDamage()));
	if (skeleton->GetHp() == 0) {
		game_elements.erase(skeleton->GetPos());
	}
	game_elements.erase(this->GetPos());
}
