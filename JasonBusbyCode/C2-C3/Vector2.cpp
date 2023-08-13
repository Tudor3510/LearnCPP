#include "Vector2.h"


Vector2::Vector2(int x, int y) : _x(x), _y(y)
{
}

int Vector2::GetX() const {  return _x;  }
int Vector2::GetY() const {  return _y;  }