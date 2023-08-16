#ifndef PLAYER_H
#define PLAYER_H

#include "IEntity.h"
#include "Level.h"
#include "IWeapon.h"
#include "IActor.h"
#include "Actor.h"
#include <stack>

class Player : public Actor
{
public:
    Player(Level& level, char ch);

    void FireProjectile();

    void Collide(IEntity& entity) override;
    void Update() override;
};




#endif