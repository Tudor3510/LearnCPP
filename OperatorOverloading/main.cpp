#include <iostream>
#include <string>

using namespace std;


// THIS COMPILES !!!!!
// but gives us segmentation fault because reference to local variable "local" returned
/*
class Vector2
{
    float _x, _y;
public:
    Vector2(float x, float y): _x(x), _y(y)
    {
    }

    float GetX() const {  return _x;  }
    float GetY() const {  return _y;  }

    Vector2& operator + (const Vector2& rhs) const
    {
        Vector2 local(_x + rhs._x, _y + rhs._y);
        return local;
    }

};


int main()
{
    Vector2 vectA(1, 2);
    Vector2 vectB(7, 9);

    cout    << "X: " << (vectA + vectB).GetX()
            << "Y: " << (vectA + vectB).GetY()
            << "\n";

    return 0;
}
*/







// THIS CODE WORKS !!!!!!!!
// even though it calculates vectA + vectB twice
/*
class Vector2
{
    float _x, _y;
public:
    Vector2(float x, float y): _x(x), _y(y)
    {
    }

    float GetX() const {  return _x;  }
    float GetY() const {  return _y;  }

    Vector2 operator + (const Vector2& rhs) const
    {
        Vector2 local(_x + rhs._x, _y + rhs._y);
        return local;
    }

};


int main()
{
    Vector2 vectA(1, 2);
    Vector2 vectB(7, 9);

    cout    << "X: " << (vectA + vectB).GetX() << "\n"
            << "Y: " << (vectA + vectB).GetY() << "\n";

    return 0;
}
*/









// THIS WORKS

class Vector2
{
    float _x, _y;
public:
    Vector2(float x, float y): _x(x), _y(y)
    {
    }

    float GetX() const {  return _x;  }
    float GetY() const {  return _y;  }

    Vector2 operator + (const Vector2& rhs) const
    {
        Vector2 local(*this);
        local += rhs;
        return local;
    }

    Vector2& operator+= (const Vector2& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;

        return *this;
    }

    Vector2& operator++()               //prefix
    {
        ++_x;
        ++_y;
        return *this;
    }

    Vector2 operator++(int)             // postfix
    {                                   // the int is a dummy parameter
        Vector2 copy(*this);            // used solely to differentiate the postfix
        operator++();                   // increment operator
        return copy;
    }
};

int main()
{
    Vector2 myObject1(1, 2);
    Vector2 myObject2(7, 1);

    Vector2 result = myObject1 + myObject2;
    cout << "Y: " << result.GetY() << "\n";

    myObject1 += myObject2;
    cout << "X: " << myObject1.GetX() << "\n";

    ++myObject1;
    cout << "X: " << myObject1++.GetX() << "\n";

    cout << "X: " << myObject1.GetX() << "\n";

    return 0;
}