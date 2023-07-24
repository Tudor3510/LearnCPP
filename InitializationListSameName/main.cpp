#include <iostream>
using namespace std;


//So you can use the same name
class ClassA
{
    int x, y;
public:
    ClassA(int x, int y): x(x), y(y)
    {
    };

    int GetX() { return x; };
    int GetY() { return y; };
};

int main(){
    ClassA* classA = new ClassA(10, 12);
    cout    <<  classA->GetX()  <<  "\n"    <<  classA->GetY()    <<  "\n";


    return 0;
}