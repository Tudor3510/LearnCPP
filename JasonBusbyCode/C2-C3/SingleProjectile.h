#ifndef SINGLEPROJECTILE_H
#define SINGLEPROJECTILE_H

#include "IProjectile.h"
#include "Vector2.h"
#include "Level.h"
#include "IEntity.h"


class SingleProjectile : public IProjectile
{
    unsigned int _frameCount;
    Level& _level;
    char _character;
    Vector2 _position;
    Vector2 _velocity;
    int _damage;

public:
    SingleProjectile(Level& level, int damage, char ch, const Vector2& velocity);

    int GetDamage() override;
    char GetCharacter() const override;
    const Vector2& GetPosition() const override;
    void SetPosition(const Vector2& position) override;
    void Collide(IEntity& entity) override;
    void Update() override;
};


#endif