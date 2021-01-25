#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "../curses/curses.h"
#include "Position.h"

class Bullet;
class Heart;
class Spike;
class Trophy;
class Wall;
class Player;
class Monster;
class Skeleton;

class Actor
{
public:
	Actor(Position, char, int, int, int, int);

	Position GetPos();

	void SetPos(Position);

	char GetSym();

	void SetSym(char);

	int GetHp();

	void SetHp(int);

	int GetMaxHp();

	void SetMaxHp(int);

	int GetDamage();

	void SetDamage(int);

	int GetHitDamage();

	void SetHitDamage(int);

	bool GetLose();

	void SetLose(bool);

	bool GetWin();

	void SetWin(bool);

	int GetDirection();

	void SetDirection(int);

	virtual void MoveActor(std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Actor*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Bullet*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Heart*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Spike*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Trophy*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Wall*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Player*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Monster*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

	virtual void Collide(Skeleton*, std::map<Position, std::shared_ptr<Actor>>&) = 0;

private:
	int direction;
	bool lose = false;
	bool win = false;
	Position pos;
	char sym;
	int hp;
	int max_hp;
	int damage;
	int hit_damage;
};

