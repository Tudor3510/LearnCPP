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

// THIS WORKS !!!!!!!!
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
*/

// THIS WORKS !!!!!!!!
// but there is a catch
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

    Vector2* operator->()
    {
        cout << "In operator->     ";
        return this;
    }

};

int main()
{
    Vector2 myObject(7, 7);
    Vector2* myObjectPtr =  &myObject;

    cout    << "X: " << myObjectPtr->GetX() << "\n"                 // X: 7
            << "Y: " << myObjectPtr->GetY() << "\n";                // Y: 7

    // The "In operator-> " is not printed because we have overloaded the operator-> for Vector2,
    // not for Vector2*(you can not overload the operator for the pointer). So we can use
    // operator-> directly on objects of type Vector2, as in the example below

    cout    << "\n";


    cout    << "X: " << myObject->GetX() << "\n"                    // X: In operator->     7
            << "Y: " << myObject->GetY() << "\n";                   // Y: In operator->     7


    return 0;
}
*/













// THIS DOES NOT WORK !!!!!!!!!!!
// circular pointer delegation detected
/*
class Vector2
{
    float _x, _y;

public:
    Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    Vector2 operator->()
    {
        cout << "In operator->     ";
        return *this;
    }
};

int main()
{
    Vector2 myObject(8, 8);

    cout << "X: " << myObject->GetX() << "\n"
         << "Y: " << myObject->GetY() << "\n";
    // circular pointer delegation detected

    // If the return value is another object of class type, not a pointer, then the subsequent
    // member lookup is also handled by an operator-> function. This is called the "drill-down behavior."
    // The language chains together the operator-> calls until the last one returns a pointer.

    return 0;
}
*/











// THIS DOES NOT WORK !!!!!!!!
// result of 'operator->()' yields non-pointer result
/*
class Vector2
{
    float _x, _y;

public:
    Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    string operator->()
    {
        cout << "In operator->     ";
        return string("returned string");
    }
};

int main()
{
    Vector2 myObject(8, 8);

    cout << "X: " << myObject->GetX() << "\n"
         << "Y: " << myObject->GetY() << "\n";



    return 0;
}
*/














// THIS WORKS !!!!!!!!!!
// but be careful with all the cases
/*
class Vector2
{
    float _x, _y;

public:
    Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    Vector2 operator* (int multiplier)
    {
        return Vector2(_x * multiplier, _y * multiplier);
    }

    Vector2& operator* ()
    {
        cout << "Overloading dereference operator      ";
        return *this;
    }
};

int main()
{
    Vector2 myObject(3, 21);
    auto afterMultiplication = myObject * 3;
    cout << "X: " << afterMultiplication.GetX() << "\n"             // X: 9
         << "Y: " << afterMultiplication.GetY() << "\n"             // Y: 63
         << "\n";

    
    
    Vector2 * myObjectPtr = &afterMultiplication;

    cout << "X: " << (*myObjectPtr).GetX() << "\n"                  // X: 9
         << "Y: " << (*myObjectPtr).GetY() << "\n"                  // Y: 63
         << "\n";

    // The "Overloading dereference operator " is not printed because we have overloaded the operator* for Vector2,
    // not for Vector2*(you can not overload the dereference operator for the built-in pointer type). So we can use
    // operator* directly on objects of type Vector2, as in the example below


    cout << "X: " << (*afterMultiplication).GetX() << "\n"          // X: Overloading dereference operator      9
         << "Y: " << (*afterMultiplication).GetY() << "\n"          // Y: Overloading dereference operator      63
         << "\n";


    return 0;
}
*/















// THIS WORKS !!!!!!!!!!!!
// but be careful that the object returned is not a reference
/*
class Vector2
{
    float _x, _y;

public:
    Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    void SetX(int x) { _x = x; }
    void SetY(int y) { _y = y; }

    Vector2 operator* (int multiplier)
    {
        return Vector2(_x * multiplier, _y * multiplier);
    }

    Vector2 operator* ()
    {
        cout << "Overloading dereference operator      ";
        return *this;
    }
};

int main()
{
    Vector2 myObject(43, 81);

    (*myObject).SetY(173);                  // Overloading dereference operator
    
    cout << "\n";

    cout << (*myObject).GetY() << "\n";     // Overloading dereference operator      81

    return 0;
}
*/









// THIS WORKS !!!!!!!!!!
/*
class Vector2
{
    float _x, _y;

public:
    Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    Vector2 operator* (int multiplier)
    {
        return Vector2(_x * multiplier, _y * multiplier);
    }

    string operator* ()
    {
        cout << "Overloading dereference operator    ";
        return "Un nou string";
    }
};


int main()
{
    Vector2 myObject(26, 34);

    cout << *myObject << "\n";              // Overloading dereference operator    Un nou string


    return 0;
}
*/