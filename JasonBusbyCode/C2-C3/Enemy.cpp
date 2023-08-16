#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Level& level, char ch) : Actor(level, ch), _frameCount(0)
{
    _direction = Vector2(1, 0);
}

void Enemy::Collide(IEntity& entity)
{

}

void Enemy::Update()
{
    if (rand() % 4 == 0)
        _weapons.top()->Fire(*this, _direction);

    if (_frameCount++ < 5)
        return;
    
    _frameCount = 0;

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