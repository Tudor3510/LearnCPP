#include <iostream>
using namespace std;



// THIS WORKS !!!!!!!!!!!!!!!
class BClass
{
    int x, y;

public:
    BClass(int x, int y): x(x), y(y)
    {
    }

    int GetX() const { return x; }
    int GetY() const { return y; }
};

class DClass : public BClass
{
    int z;

public:
    DClass(int x, int y, int z): BClass(x, y), z(z)
    {
    }
    int GetZ() const { return z; }

};

int main()
{
    DClass obj(10, 15, 20);
    cout    << "X: " << obj.GetX() << "\n"
            << "Y: " << obj.GetY() << "\n"
            << "Z: " << obj.GetZ() << "\n";


    return 0;
}