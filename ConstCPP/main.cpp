#include <iostream>
using namespace std;

class Person
{
    const int _age = 78;
public:
    Person(int age) : _age(age)
    {
    }


    int GetAge() const {return _age;}
};












// THIS IS NOT WORKING !!!!!!!!!!
/*
class Position
{
    int _x, _y;
public:
    Position(int x, int y): _x(x), _y(y)
    {
    }

    int GetX() const
    {
        return _x;
    }

    int GetY() const
    {
        return _y;
    }
};

int main()
{
    Position& position = Position(3, 4);

    cout    << "X: " << position.GetX() << "\n"
            << "Y: " << position.GetY() << "\n";

    return 0;
}
*/







// THIS IS NOT WORKING !!!!!!!!!
// cannot overload functions distinguished by return type alone
/*
int ReturnTen()
{
    return 10;
}

const int ReturnTen()
{
    return 10;
}

int main ()
{
    int a = ReturnTen();
}
*/







/*
int main()
{

    int x = 7;
    cout << x << "\n";

    const_cast<int&> (x) = 89;
    cout << x << "\n";

    int const *  ptr = &x;

    int b = 8;
    ptr = &b;

    return 0;
}
*/