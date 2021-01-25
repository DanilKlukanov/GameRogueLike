#pragma once
#include "Actor.h"

class CanShootActor : public Actor
{
public:
	CanShootActor(Position, char, int, int, int, int);

	~CanShootActor();

	virtual void ShootActor(std::map<Position, std::shared_ptr<Actor>>&) = 0;
};

