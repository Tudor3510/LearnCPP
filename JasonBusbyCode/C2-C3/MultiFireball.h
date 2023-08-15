#ifndef MULTIFIREBALL_H
#define MULTIFIREBALL_H

#include <map>
#include "IWeapon.h"
#include "Level.h"
#include "IEntity.h"

class MultiFireball : public IWeapon
{
    std::map<IEntity*, int> _ammo;
    char _character;
    Level& _level;
    int _damage;

public:
    MultiFireball(char character, Level& level, int damage);

    void Attach(IEntity& entity);
    void Fire(IEntity& entity, const Vector2& direction);
    bool IsActive(IEntity& entity);


private:
    void CreateProjectile(const Vector2& position, const Vector2& direction);
};


#endif