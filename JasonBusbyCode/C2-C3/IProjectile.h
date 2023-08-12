#ifndef IPROJECTILE_H
#define IPROJECTILE_H

#include "IEntity.h"

class IProjectile : IEntity
{
public:
    virtual int GetDamage() = 0;

};


#endif