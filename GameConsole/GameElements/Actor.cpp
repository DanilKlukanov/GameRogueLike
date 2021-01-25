#include "Actor.h"

Actor::Actor(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	pos(pos), sym(sym), hp(hp), max_hp(max_hp), damage(damage), hit_damage(hit_damage) {}

Position Actor::GetPos()
{
	return pos;
}

void Actor::SetPos(Position pos)
{
	this->pos = pos;
}

char Actor::GetSym()
{
	return sym;
}

void Actor::SetSym(char sym)
{
	this->sym = sym;
}

int Actor::GetHp()
{
	return hp;
}

void Actor::SetHp(int hp)
{
	this->hp = hp;
}

int Actor::GetMaxHp()
{
	return max_hp;
}

void Actor::SetMaxHp(int max_hp)
{
	this->max_hp = max_hp;
}

int Actor::GetDamage()
{
	return damage;
}

void Actor::SetDamage(int damage)
{
	this->damage = damage;
}

int Actor::GetHitDamage()
{
	return hit_damage;
}

void Actor::SetHitDamage(int hit_damage)
{
	this->hit_damage = hit_damage;
}

bool Actor::GetLose()
{
	return lose;
}

void Actor::SetLose(bool lose)
{
	this->lose = lose;
}

bool Actor::GetWin()
{
	return win;
}

void Actor::SetWin(bool win)
{
	this->win = win;
}

int Actor::GetDirection()
{
	return direction;
}

void Actor::SetDirection(int direction)
{
	this->direction = direction;
}
