#include <iostream>
using namespace std;


// THIS WORKS !!!!!!
/*
template <typename T1>
double add (T1 a, T1 b, T1 c)
{
    return double(a) + b + c;
}


int main()
{
    cout << add (5, 7, 12);

    return 0;
}
*/



// THIS DOES NOT WORK !!!!!!
// 'T2' has not been declared
/*
template <typename T1, T2, T3>
double add (T1 a, T2 b, T3 c)
{
    return double(a) + b + c;
}


int main()
{
    cout << add (5, 7, 12);

    return 0;
}
*/





// THIS WORKS !!!!!!
/*
template <typename T1, typename T2, typename T3>
double add (T1 a, T2 b, T3 c)
{
    return a + b + c;
}


int main()
{
    cout << add (5, 7.8, 12);               // 24.8

    return 0;
}
*/







// THIS WORKS !!!!!!!!!
/*
template <class T1, class T2, class T3>
double add (T1 a, T2 b, T3 c)
{
    return a + b + c;
}


int main()
{
    cout << add (5, 7.8, 12);               // 24.8

    return 0;
}
*/







// THIS WORKS !!!!!!!!!!!!!!!!
/*
template <int N>
class SomeClass
{
private:
    int arr[N];
public:
    int GetSize() const { return N; };
};

int main()
{
    SomeClass<20> cls;
    cout << cls.GetSize() << "\n";              // 20


    return 0;
}
*/






// THIS DOES NOT WORK !!!!!!!!!!!!!!!!
// the value of 'length' is not usable in a constant expression
/*
template <int N>
class SomeClass
{
private:
    int arr[N];
public:
    int GetSize() const { return N; };
};

int main()
{
    int length;
    cout << "Enter length: ";
    cin >> length;

    SomeClass<length> cls;
    cout << cls.GetSize() << "\n";


    return 0;
}
*/






// THIS DOES NOT WORK !!!!!!
// too few arguments for class template "SomeClass"
/*
template <int N, typename T>
class SomeClass
{
private:
    int arr[N];
public:
    T GetSize() const { return N; };
};

int main()
{
    SomeClass<20> cls;
    cout << cls.GetSize() << "\n";


    return 0;
}
*/








// THIS WORKS !!!!
/*
template <int N, typename T>
class SomeClass
{
private:
    int arr[N];
public:
    T GetSize() const { return N; };
};

int main()
{
    SomeClass<35, int> cls;
    cout << cls.GetSize() << "\n";              // 35


    return 0;
}
*/




// THIS WORKS !!!!!!!!!!!
// but be careful !!!!!
// The compiler first looks for an exact match.
// If there is a non-template function with the exact argument types, it will be chosen over the template function.
/*
template <typename T>
T function (T a, T b)
{
    return a + b;
}

int function (int a, int b)
{
    return a * b;
}

int main ()
{
    cout << function (5, 7);                            // 35 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return 0;
}
*/















// THIS WORKS !!!!!!!!!!!
// but be careful !!!!!
// The compiler first looks for an exact match.
// If there is a non-template function with the exact argument types, it will be chosen over the template function.
// In this case, when you call function(5, 7.5) in the main function, there's no exact match for the argument types (int and double).
// However, the template function cannot be instantiated with these arguments because it requires both arguments to have the same type (T).
// The compiler cannot deduce a single type for T that would make the template function work with these arguments.
/*
template <typename T>
T function (T a, T b)
{
    return a + b;
}

int function (int a, int b)
{
    return a * b;
}

int main ()
{
    cout << function (5, 7.5);                          // 35 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return 0;
}
*/







// THIS WORKS !!!!!!!!!!!!!!!
// but be careful, look above
/*
template <typename T>
T function (T a, T b)
{
    return a + b;
}

int function (int a, int b)
{
    return a * b;
}

int main ()
{
    cout << function (5.0, 7.5);                            // 12.5 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return 0;
}
*/








// THIS WORKS !!!!!!!!
// but be careful, look above
/*
template <typename T>
T function (T a, T b)
{
    return a + b;
}

int function (int a, int b)
{
    return a * b;
}

int main ()
{
    cout << function<float> (5, 7.5);                          // 12.5 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return 0;
}
*/

