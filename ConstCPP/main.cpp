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








int GetInt(const string prompt)
{
    return 4;
}

int GetInt(const string& prompt)
{
    cout << prompt;
    return 10;
}









class Position
{
    const int _x, _y;
public:
    Position(int x, int y): _x(x), _y(y)
    {
    }

    const int GetX() const
    {
        return _x;
    }

    const int GetY() const
    {
        return _y;
    }
};


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