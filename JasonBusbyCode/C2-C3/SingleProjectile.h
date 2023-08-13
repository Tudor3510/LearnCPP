#ifndef SINGLEPROJECTILE_H
#define SINGLEPROJECTILE_H

#include "IProjectile.h"
#include "Vector2.h"


class SingleProjectile : public IProjectile
{
public:
    SingleProjectile(Level& level, int damage, char ch, const Vector2& velocity);

    int GetDamage();
    char GetCharacter() const;
    const Vector2& GetPosition() const;
    void SetPosition(const Vector2& Vector2);
    void Collide(IEntity& entity);
    void Update();
};


#endif