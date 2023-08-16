#include "Player.h"
#include "SingleProjectile.h"


Player::Player(Level &level, char ch) : _level(level), _character(ch), _health(100)
{
}

char Player::GetCharacter() const
{
    return _character;
}

const Vector2& Player::GetPosition() const
{
    return _position;
}


void Player::SetWeapon(IWeapon* weapon)
{
    _weapons.push(weapon);
    weapon->Attach(*this);
}


IWeapon* Player::GetWeapon()
{
    return !_weapons.empty() ? _weapons.top() : NULL;
}


int Player::GetHealth() const
{
    return _health;
}


void Player::TakeDamage(int damage)
{
    _health -= damage;
}


void Player::SetPosition(const Vector2& position)
{
    _position = position;
}

void Player::Collide(IEntity& entity)
{
}

void Player::Update()
{
}

void Player::Move(const Vector2& direction)
{
    auto newPosition = _position + direction;
    _level.MoveEntity(*this, newPosition);
    _direction = direction;
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


