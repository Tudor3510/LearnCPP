#include "WeaponPickupTile.h"
#include "Player.h"

WeaponPickupTile::WeaponPickupTile(char ch, IWeapon* weapon)
: _character(ch), _weapon(weapon)
{
}

char WeaponPickupTile::GetCharacter() const
{
    return _character;
}


bool WeaponPickupTile::CanEnter(IEntity& entity)
{
    return true;
}


void WeaponPickupTile::Enter(IEntity& entity)
{
    auto player = dynamic_cast<Player*>(&entity);

    if (player == NULL)
        return;

    player->SetWeapon(_weapon);
}