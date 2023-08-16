#include <iostream>
using namespace std;

// THIS WOKRS !!!!!!
// So you can use the same name
/*
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
    cout << classA->GetX() << "\n"          // 10
         << classA->GetY() << "\n";         // 12

    return 0;
}
*/






// THIS DOES NOT WORK !!!!!!
// class 'DerivedClass' does not have any field named '_text'
// You can not initialize members of the parent class in the derived class constructor initialization list.
// It doesn't matter whether they are protected, public or anything else.
/*
class BaseClass
{
protected:
    std::string _text;
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass(std::string text) : _text(text)
    {
    }

};


int main()
{
    DerivedClass derivedClass("Un text");

    return 0;
}
*/