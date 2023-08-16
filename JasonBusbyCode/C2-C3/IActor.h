#ifndef IACTOR_H
#define IACTOR_H

#include "IWeapon.h"

class IActor
{
public:
    virtual IWeapon* GetWeapon();
    virtual void SetWeapon (IWeapon* weapon);
    virtual int GetHealth() const;
    virtual void TakeDamage(int damage);
};

#endif