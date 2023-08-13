#include "SingleProjectile.h"

SingleProjectile::SingleProjectile(Level &level, int damage, char ch, const Vector2 &velocity)
    : _level(level), _damage(damage), _character(ch), _velocity(velocity), _frameCount(0)
{
}

int SingleProjectile::GetDamage()
{
    return _damage;
}

char SingleProjectile::GetCharacter() const
{
    return _character;
}

const Vector2& SingleProjectile::GetPosition() const
{
    return _position;
}

void SingleProjectile::SetPosition(const Vector2& position)
{
    _position = position;
}

void SingleProjectile::Collide(IEntity& entity)
{
    _level.RemoveEntity(*this);
}

void SingleProjectile::Update()
{
    if (++ _frameCount < 0)
        return;

    _frameCount = 0;
    _level.MoveEntity(*this, _position + _velocity);
}