#pragma once
#include "Actor.h"
#include "Bullet.h"
#include "Heart.h"
#include "Monster.h"
#include "Player.h"
#include "Skeleton.h"
#include "Trophy.h"
#include "Wall.h"

class Spike : public Actor
{
public:
	Spike(Position, char, int, int, int, int);

	~Spike();

	void MoveActor(std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Actor*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Bullet*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Heart*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Spike*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Trophy*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Wall*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Player*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Monster*, std::map<Position, std::shared_ptr<Actor>>&) override;

	void Collide(Skeleton*, std::map<Position, std::shared_ptr<Actor>>&) override;
};

