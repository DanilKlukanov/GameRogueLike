#include "Skeleton.h"

Skeleton::Skeleton(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	CanShootActor(pos, sym, hp, max_hp, damage, hit_damage) {}

Skeleton::~Skeleton() = default;

void Skeleton::MoveActor(std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
	int coord_x[4] = { -1, 1, 0, 0 };
	int coord_y[4] = { 0, 0, -1, 1 };
	int random = rand() % 5;

    if (random == 4) {
        ShootActor(game_elements);
        return;
    }

	Position new_pos(GetPos().x + coord_x[random], GetPos().y + coord_y[random]);
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

void Skeleton::ShootActor(std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    int coord_x[4] = { -1, 1, 0, 0 };
    int coord_y[4] = { 0, 0, -1, 1 };
    char direction[4] = { '^', 'v', '<', '>' };
    int random = rand() % 4;

    Position new_pos(coord_x[random] + GetPos().x, coord_y[random] + GetPos().y);
    auto element = game_elements.find(new_pos);
    if (element == game_elements.end()) {
        game_elements[new_pos] = std::make_shared<Bullet>(new_pos, direction[random], 1, 1, GetHitDamage(), GetHitDamage());
    }
}

void Skeleton::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    actor->Collide(this, game_elements);
}

void Skeleton::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    bullet->Collide(this, game_elements);
}

void Skeleton::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Skeleton::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Skeleton::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Skeleton::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Skeleton::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    player->SetHp(std::max(0, player->GetHp() - this->GetDamage()));
    if (player->GetHp() == 0) {
        game_elements.erase(player->GetPos());
        SetLose(true);
        player->SetLose(true);
    }
}

void Skeleton::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Skeleton::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>&)
{
}
