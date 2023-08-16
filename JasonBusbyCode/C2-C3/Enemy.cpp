#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Level& level, char ch) : Actor(level, ch)
{   
}

void Enemy::Collide(IEntity& entity)
{

}

void Enemy::Update()
{
    if (rand() % 4 == 0)
        _weapons.top()->Fire(*this, _direction);

    auto dir = rand() % 4;
    switch (dir)
    {
    case 0:
        Move(Vector2::North);
        break;
    
    case 1:
        Move(Vector2::South);
        break;

    case 2:
        Move(Vector2::East);
        break;

    case 3:
        Move(Vector2::West);
        break;
    }
}