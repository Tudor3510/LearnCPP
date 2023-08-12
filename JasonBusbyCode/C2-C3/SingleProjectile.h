#ifndef SINGLEPROJECTILE_H
#define SINGLEPROJECTILE_H

#include "IProjectile.h"
#include "Position.h"


class SingleProjectile : public IProjectile
{
public:
    SingleProjectile(int damage, char ch, const Position& velocity);

    int GetDamage();
    char GetCharacter() const;
    const Position& GetPosition() const;
    void SetPosition(const Position& position);
    void Collide(IEntity& entity);
    void Update();
};


#endif