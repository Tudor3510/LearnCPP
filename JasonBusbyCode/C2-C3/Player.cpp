#include "Player.h"
#include "SingleProjectile.h"
#include "IActor.h"


Player::Player(Level &level, char ch) : Actor(level, ch)
{
}


void Player::Collide(IEntity& entity)
{
}

void Player::Update()
{
}

void Player::FireProjectile()
{
    if (_weapons.empty())
        return;

    if (!_weapons.top()->IsActive(*this))
        _weapons.pop();

    if (_weapons.empty())
        return;

    _weapons.top()->Fire(*this, _direction);    
}


