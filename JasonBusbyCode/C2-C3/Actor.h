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

    IWeapon* GetWeapon();
    void SetWeapon(IWeapon* weapon);
    int GetHealth() const;
    void TakeDamage(int damage);

    char GetCharacter() const;
    const Vector2& GetPosition() const;
    void SetPosition(const Vector2& position);
    void Collide(IEntity& entity);
    void Update();
};

#endif