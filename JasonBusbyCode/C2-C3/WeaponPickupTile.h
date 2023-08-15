#ifndef WEAPONPICKUPTILE_H
#define WEAPONPICKUPTILE_H

#include "ITile.h"
#include "IWeapon.h"

class WeaponPickupTile : public ITile
{
private:
    char _character;
    IWeapon* _weapon;

public:
    WeaponPickupTile(char ch, IWeapon* weapon);

    char GetCharacter() const;
    bool CanEnter(IEntity& entity);
    void Enter(IEntity& entity);

};


#endif