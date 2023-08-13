#include "Vector2.h"


Vector2::Vector2(int x, int y) : _x(x), _y(y)
{
}
Vector2::Vector2() : _x(0), _y(0)
{
}

int Vector2::GetX() const {  return _x;  }
int Vector2::GetY() const {  return _y;  }

Vector2 Vector2::operator+ (const Vector2& rhs) const
{
    return Vector2(_x + rhs._x, _y + rhs._y);
}

Vector2& Vector2::operator+= (const Vector2& rhs)
{
    _x += rhs._x;
    _y += rhs._y;

    return *this;
}

Vector2 Vector2::operator- (const Vector2& rhs) const
{
    return Vector2(_x - rhs._x, _y - rhs._y);
}

Vector2& Vector2::operator-= (const Vector2& rhs)
{
    _x -= rhs._x;
    _y -= rhs._y;

    return *this;
}