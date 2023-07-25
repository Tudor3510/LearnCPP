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









// THIS IS NOT WORKING !!!!!!!
// can not call non-const functions from const objects
/*
class Position
{
private:
    int _x, _y;

public:
    int GetX() const { return _x; }
    int GetY() const { return _y; }

    void SetX(int x) { _x = x; }
    void SetY(int y) { _y = y; }
};

void Blegh(const Position& pos)
{
    pos.SetX(10);
}

int main()
{
    Position pos;
    pos.SetX(10);
    pos.SetY(40);

    Blegh(pos);

    cin.get();
    return 0;
}
*/









// THIS IS WORKING !!!!!!!!!
// but bad code
/*
class Position
{
private:
    int _x, _y;

public:
    int GetX() const { return _x; }
    int GetY() const { return _y; }

    void SetX(int x) { _x = x; }
    void SetY(int y) { _y = y; }
};

void Blegh(const Position& pos)
{
    Position& pos2 = const_cast<Position&> (pos);
    pos2.SetX(100);
}

int main()
{
    Position pos;
    pos.SetX(10);
    pos.SetY(40);

    Blegh(pos);

    cout << "X: " << pos.GetX() << "\n";                // X: 100

    return 0;
}
*/









// class Position
// {
// private:
//     int _x, _y;

// public:
//     int GetX() const { return _x; }
//     int GetY() const { return _y; }

//     void SetX(int x) { _x = x; }
//     void SetY(int y) { _y = y; }
// };

// void Blegh(const Position& pos)
// {
//     Position& pos2 = const_cast<Position&> (pos);
//     pos2.SetX(100);
// }