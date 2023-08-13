#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
    int _x, _y;

public:
    Vector2(int x, int y);
    Vector2();

    int GetX() const;
    int GetY() const;

    Vector2 operator + (const Vector2& rhs) const;
    Vector2& operator += (const Vector2& rhs);

    Vector2 operator - (const Vector2& rhs) const;
    Vector2& operator -= (const Vector2& rhs);
};



#endif