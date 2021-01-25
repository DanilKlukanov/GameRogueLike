#include "CanShootActor.h"

CanShootActor::CanShootActor(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
	Actor(pos, sym, hp, max_hp, damage, hit_damage) {}

CanShootActor::~CanShootActor() = default;