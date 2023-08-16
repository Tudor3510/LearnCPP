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

    char GetCharacter() const override;
    bool CanEnter(IEntity& entity) override;
    void Enter(IEntity& entity) override;

};


#endif