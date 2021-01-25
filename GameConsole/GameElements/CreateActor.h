#pragma once
#include "Bullet.h"
#include "Heart.h"
#include "Monster.h"
#include "Player.h"
#include "Skeleton.h"
#include "Spike.h"
#include "Trophy.h"
#include "Wall.h"

class CreateActor {
public:
	CreateActor() = default;
	static std::shared_ptr<Actor> Create(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) {
		std::shared_ptr<Actor> new_actor;
		switch (sym)
		{
		case 'P': {
			new_actor = std::make_shared<Player>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		case 'T': {
			new_actor = std::make_shared<Trophy>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		case '+': {
			new_actor = std::make_shared<Heart>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		case '$': {
			new_actor = std::make_shared<Spike>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		case '#': {
			new_actor = std::make_shared<Wall>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		case 'M': {
			new_actor = std::make_shared<Monster>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		case 'S': {
			new_actor = std::make_shared<Skeleton>(pos, sym, hp, max_hp, damage, hit_damage);
			break;
		}
		default:
			break;
		}
		return new_actor;
	}
};
