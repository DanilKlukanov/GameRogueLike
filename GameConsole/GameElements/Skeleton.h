#pragma once
#include "CanShootActor.h"
#include "Bullet.h"
#include "Heart.h"
#include "Monster.h"
#include "Player.h"
#include "Spike.h"
#include "Trophy.h"
#include "Wall.h"

class Skeleton : public CanShootActor
{
public:
	Skeleton(Position, char, int, int, int, int);

	~Skeleton();

	void MoveActor(std::map<Position, std::shared_ptr<Actor>>&) override;

	void ShootActor(std::map<Position, std::shared_ptr<Actor>>&) override;

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

