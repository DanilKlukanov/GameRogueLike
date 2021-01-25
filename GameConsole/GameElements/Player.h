#pragma once
#include "CanShootActor.h"
#include "Bullet.h"
#include "Heart.h"
#include "Monster.h"
#include "Skeleton.h"
#include "Spike.h"
#include "Trophy.h"
#include "Wall.h"

class Player : public CanShootActor
{
public:
	Player(Position, char, int, int, int, int);

	~Player();

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

private:
	int direction;
	std::map<int, Position> coordinates;
	std::map<int, char> syms;
};