#include "Player.h"

Player::Player(Position pos, char sym, int hp, int max_hp, int damage, int hit_damage) :
    CanShootActor(pos, sym, hp, max_hp, damage, hit_damage) {
    coordinates[258] = Position(1, 0);
    coordinates[259] = Position(-1, 0);
    coordinates[260] = Position(0, -1);
    coordinates[261] = Position(0, 1);
    syms[258] = 'v';
    syms[259] = '^';
    syms[260] = '<';
    syms[261] = '>';
}

Player::~Player() = default;

void Player::MoveActor(std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    Position old_pos = GetPos();
    Position new_pos(0, 0);
    int command = getch();
    switch (command)
    {
    case 'w':
    case 'W':
    {
        new_pos.x = old_pos.x - 1;
        new_pos.y = old_pos.y;
        break;
    }
    case 's':
    case 'S':
    {
        new_pos.x = old_pos.x + 1;
        new_pos.y = old_pos.y;
        break;
    }
    case 'a':
    case 'A':
    {
        new_pos.x = old_pos.x;
        new_pos.y = old_pos.y - 1;
        break;
    }
    case 'd':
    case 'D':
    {
        new_pos.x = old_pos.x;
        new_pos.y = old_pos.y + 1;
        break;
    }
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT: {
        direction = command;
        ShootActor(game_elements);
        break;
    }
    default:
        break;
    }

    while (getch() > 0) {}

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

void Player::ShootActor(std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    Position new_pos(GetPos().x + coordinates[direction].x, GetPos().y + coordinates[direction].y);
    auto element = game_elements.find(new_pos);
    if (element == game_elements.end()) {
        game_elements[new_pos] = std::make_shared<Bullet>(new_pos, syms[direction], 1, 1, GetHitDamage(), GetHitDamage());
    }
}

void Player::Collide(Actor* actor, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    actor->Collide(this, game_elements);
}

void Player::Collide(Bullet* bullet, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    bullet->Collide(this, game_elements);
}

void Player::Collide(Heart* heart, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    SetHp(std::min(GetMaxHp(), GetHp() + heart->GetHp()));
    game_elements.erase(heart->GetPos());
}

void Player::Collide(Spike* spike, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    spike->Collide(this, game_elements);
}

void Player::Collide(Trophy* trophy, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    trophy->Collide(this, game_elements);
}

void Player::Collide(Wall* wall, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Player::Collide(Player* player, std::map<Position, std::shared_ptr<Actor>>&)
{
}

void Player::Collide(Monster* monster, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    monster->Collide(this, game_elements);
}

void Player::Collide(Skeleton* skeleton, std::map<Position, std::shared_ptr<Actor>>& game_elements)
{
    skeleton->Collide(this, game_elements);
}
