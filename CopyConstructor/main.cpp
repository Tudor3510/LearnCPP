#include <iostream>
#include <vector>
#include <string>
using namespace std;


// THIS IS WORKING !!!!!!!!!!
/*
class Vector2
{
    int _x, _y;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(const Vector2& rhs) : _x(rhs._x), _y(rhs._y)
    {
        cout << "Copy constructor" << "\n";
    }

    Vector2(int x, int y): _x(x), _y(y)
    {
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }
};

int main()
{
    Vector2 vect2(1, 2);

    Vector2 copy(vect2);                        // Copy constructor

    Vector2 copy2 = vect2;                      // Copy constructor

    return 0;
}
*/











// THIS IS NOT WORKING !!!!!!
// no matching function for call to 'Vector2::Vector2(Vector2&)
/*
class Vector2
{
    int _x, _y;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    explicit Vector2(const Vector2& rhs) : _x(rhs._x), _y(rhs._y)
    {
        cout << "Copy constructor" << "\n";
    }

    Vector2(int x, int y): _x(x), _y(y)
    {
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }
};

int main()
{
    Vector2 vect2(1, 2);

    Vector2 copy(vect2);                        // Copy constructor

    Vector2 copy2 = vect2;                      // no matching function for call to 'Vector2::Vector2(Vector2&)

    return 0;
}
*/













// THIS IS WORKING !!!!!!!!!
/*
class Vector2
{
    int _x, _y;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(const Vector2& rhs) : _x(rhs._x), _y(rhs._y)
    {
        cout << "Copy constructor" << "\n";
    }

    Vector2(int x, int y): _x(x), _y(y)
    {
    }

    Vector2& operator= (const Vector2& rhs)
    {
        cout << "operator = (or operator=)" << "\n";

        _x = rhs._x;
        _y = rhs._y;
        return *this;
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }
};

int main()
{
    Vector2 vect2(1, 2);

    Vector2 copy(vect2);                        // Copy constructor

    Vector2 copy2;                              // Constructor without parameters
    copy2 = vect2;                              // operator = (or operator=)

    return 0;
}
*/