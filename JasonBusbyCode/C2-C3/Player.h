#ifndef PLAYER_H
#define PLAYER_H

#include "IEntity.h"
#include "Level.h"
#include "IWeapon.h"
#include "IActor.h"
#include <stack>

class Player : public IEntity, public IActor
{
    char _character;
    Vector2 _position;
    Vector2 _direction;
    Level& _level;
    std::stack<IWeapon*> _weapons;

public:
    Player(Level& level, char ch);

    void Move(const Vector2& direction);
    void FireProjectile();
    void SetWeapon(IWeapon* weapon);

    char GetCharacter() const;
    const Vector2& GetPosition() const;
    void SetPosition(const Vector2& position);
    void Collide(IEntity& entity);
    void Update();
};




#endif