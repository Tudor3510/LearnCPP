#ifndef HEALTHPICKUPTILE_H
#define HEALTHPICKUPTILE_H

#include "ITile.h"

class HealthPickupTile : public ITile
{
private:
    char _character;
    int _healthToGive;

public:
    HealthPickupTile(char ch, int healthToGive);

    char GetCharacter() const override;
    bool CanEnter(IEntity& entity) override;
    void Enter(IEntity& entity) override;

};


#endif