#ifndef ACTOR_H
#define ACTOR_H

#include "Vector2.h"
#include "Level.h"
#include <stack>
#include "IWeapon.h"
#include "IActor.h"

class Actor : public IEntity, public IActor
{
    char _character;
    Vector2 _position;
    int _health;

protected:
    Vector2 _direction;
    std::stack<IWeapon*> _weapons;
    Level& _level;

public:
    Actor(Level& level, char ch);

    virtual void Move(const Vector2& direction);

    IWeapon* GetWeapon() override;
    void SetWeapon(IWeapon* weapon) override;
    int GetHealth() const override;
    void TakeDamage(int damage) override;

    char GetCharacter() const override;
    const Vector2& GetPosition() const override;
    void SetPosition(const Vector2& position) override;
    void Collide(IEntity& entity) override;
    void Update() override;
};

#endif