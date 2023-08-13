#include "SingleProjectile.h"

SingleProjectile::SingleProjectile(Level &level, int damage, char ch, const Vector2 &velocity)
    : _level(level), _damage(damage), _character(ch), _velocity(velocity), _frameCount(0)
{
}

int SingleProjectile::GetDamage()
{
}

char SingleProjectile::GetCharacter() const
{
}

const Vector2& SingleProjectile::GetPosition() const
{
}

void SingleProjectile::SetPosition(const Vector2& Vector2)
{
}

void SingleProjectile::Collide(IEntity& entity)
{
    _level.RemoveEntity(*this);
}

void SingleProjectile::Update()
{
    if (++ _frameCount < 15)
        return;

    _frameCount = 0;
    _level.MoveEntity(*this, _position + _velocity);
}