#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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




















// THIS IS NOT WORKING !!!!!!!!!!
// invalid conversion from 'const char*' to 'char*'
/*
class Vector2
{
    int _x, _y;
    char* _name;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(int x, int y, const char* name): _x(x), _y(y)
    {
        _name = new char[strlen(name)];
        strcpy(_name, name);
    }

    Vector2(int x, int y, const char* name): _x(x), _y(y), _name(name)
    {
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }

    const char* GetName() const
    {
        return _name;
    }
};

int main()
{
    Vector2* vect1 = new Vector2(1, 1, "whoa");
    Vector2 vect2(*vect1);

    cout << vect2.GetName() << "\n";

    delete vect1;

    return 0;
}
*/












// THIS COMPILES !!!!!!!!!
// BUT GIVES US UNKNOWN SIGNAL !!!!!!!
// because of the double deletion of the same dynamically allocated memory when both vect1 and vect2 objects are destroyed
// vect2 object is destroyed when main returns 0
/*
class Vector2
{
    int _x, _y;
    char* _name;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(int x, int y, const char* name): _x(x), _y(y)
    {
        _name = new char[strlen(name) + 1];

        strcpy(_name, name);
    }

    ~Vector2()
    {
        delete [] _name;
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }

    const char* GetName() const
    {
        return _name;
    }
};

int main()
{
    Vector2* vect1 = new Vector2(1, 1, "whoa");
    Vector2 vect2(*vect1);

    cout << vect2.GetName() << "\n";

    delete vect1;

    return 0;
}
*/

















// THIS COMPILES !!!!!!!!!
// SAME AS THE ABOVE !!!!!!!!
// BUT GIVES US UNKNOWN SIGNAL !!!!!!!
// because of the double deletion of the same dynamically allocated memory when both vect1 and vect2 objects are destroyed
// vect2 object is destroyed when main returns 0
/*
class Vector2
{
    int _x, _y;
    const char* _name;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(int x, int y, const char* name): _x(x), _y(y)
    {
        _name = new char[strlen(name) + 1];

        auto modifiable_name = const_cast<char*> (_name);
        strcpy(modifiable_name, name);
    }

    ~Vector2()
    {
        delete [] _name;
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }

    const char* GetName() const
    {
        return _name;
    }
};

int main()
{
    Vector2* vect1 = new Vector2(1, 1, "whoa");
    Vector2 vect2(*vect1);

    cout << vect2.GetName() << "\n";

    delete vect1;

    return 0;
}
*/















// THIS COMPILES !!!!!!!
// warning: returning reference to temporary
// but gives us segmentation fault when trying to get the name
/*
class Vector2
{
    int _x, _y;
    char* _name;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(int x, int y, const char* name): _x(x), _y(y)
    {
        _name = new char[strlen(name) + 1];

        strcpy(_name, name);
    }

    ~Vector2()
    {
        delete [] _name;
    }

    int GetX() const { return _x; }
    int GetY() const { return _y; }

    const string& GetName() const
    {
        return _name;
    }
};

int main()
{
    Vector2* vect1 = new Vector2(1, 1, "whoa");
    Vector2 vect2(*vect1);

    cout << vect2.GetName() << "\n";                            //Segmentation fault

    delete vect1;

    return 0;
}
*/









// THIS IS NOT WORKING
// cannot bind non-const lvalue reference of type
// 'std::string&' {aka 'std::__cxx11::basic_string<char>&'} to an rvalue of
// type 'std::string' {aka 'std::__cxx11::basic_string<char>'}
/*
int main()
{
    char ceva[] = "Un text";
    string& str = ceva;

    cout << "str: " << str << "\n";

    return 0;
}
*/













// THIS IS WORKING !!!!!!!!
// We are deleting the copy constructor and the assignment operator
/*
class Vector2
{
private:
    int _x, _y;

    Vector2(const Vector2& rhs) = delete;
    Vector2& operator = (const Vector2& rhs) = delete;

public:
    Vector2() : _x(0), _y(0)
    {
        cout << "Constructor without parameters" << "\n";
    }

    Vector2(int x, int y): _x(x), _y(y)
    {
    }
};

int main()
{
    Vector2 vect2(1, 2);

    return 0;
}
*/