#ifndef IENTITY_H
#define IENTITY_H

#include "Position.h"

class IEntity
{
public:
    virtual char GetCharacter() = 0;
    virtual const Position& GetPosition() = 0;
    virtual void SetPosition(const Position& position) = 0;
    virtual void Collide(IEntity& entity) = 0;
    virtual void Update() = 0;
};

#endif