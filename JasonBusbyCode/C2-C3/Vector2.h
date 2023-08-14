#ifndef VECTOR2_H
#define VECTOR2_H



class Vector2
{
    int _x, _y;

public:
    static const Vector2 North;
    static const Vector2 South;
    static const Vector2 East;
    static const Vector2 West;

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