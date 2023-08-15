#ifndef FIREBALL_H
#define FIREBALL_H

#include "IWeapon.h"
#include "Level.h"

class Fireball : public IWeapon
{
    char _character;
    Level& _level;
    int _damage;

public:
    Fireball(char character, Level& level, int damage);

    void Attach(IEntity& entity);
    void Fire(IEntity& entity, const Vector2& direction);
    bool IsActive(IEntity& entity);
};

#endif