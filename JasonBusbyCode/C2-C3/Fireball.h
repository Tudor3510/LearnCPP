#ifndef FIREBALL_H
#define FIREBALL_H

#include "IWeapon.h"

class Fireball : public IWeapon
{
public:
    void Attach(IEntity& entity);
    void Fire(IEntity& entity, const Vector2& position);
    bool IsActive(IEntity& entity);
};

#endif