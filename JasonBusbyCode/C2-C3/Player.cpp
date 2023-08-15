#include "Player.h"
#include "SingleProjectile.h"


Player::Player(Level &level, char ch) : _level(level), _character(ch)
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
    _level.SetEntity(new SingleProjectile(_level, 10, '*', _direction), _position + _direction);
}