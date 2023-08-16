#ifndef ENEMY_H
#define ENEMY_H

#include "Actor.h"
#include "Level.h"

class Enemy : public Actor
{
public:
    Enemy(Level& level, char ch);

    void Collide(IEntity& entity) override;
    void Update() override;
};

#endif