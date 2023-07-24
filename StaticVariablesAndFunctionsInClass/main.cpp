#include <iostream>
using namespace std;

// THIS WORKS !!!!!
// class BaseClass
// {
//     int a = 5;
// public:
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };




// THIS DOES NOT WORK !!!!!
// a nonstatic data member may not be defined outside its class
// class BaseClass
// {
//     int a;
// public:
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// int BaseClass::a = 54;




// THIS DOES NOT WORK  !!!
// ISO C++ forbids in-class initialization of non-const static member BaseClass::a
// class BaseClass
// {
//     static int a = 5;
// public:
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };




//THIS WORKS !!!!!
// class BaseClass
// {
//     static int a;
// public:
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// int BaseClass::a = 27;





// THIS DOES NOT WORK  !!!!
// qualified name is not allowed
// class BaseClass
// {
//     static int a;
// public:
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// void SetBaseClassA(int val)
// {
//     int BaseClass::a = val;
// }




// THIS DOES NOT WORK !!!!!
// member BaseClass::a is inaccessibe
// class BaseClass
// {
//     static int a;
// public:
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// void SetBaseClassA(int val)
// {
//     BaseClass::a = val;
// }






// THIS DOES NOT WORK !!!!!
// undefined reference to BaseClass::a (LINKER ERROR)
// class BaseClass
// {
// public:
//     static int a;
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// void SetBaseClassA(int val)
// {
//     BaseClass::a = val;
// }






// THIS WORKS !!!!!
// class BaseClass
// {
// public:
//     static int a;
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// int BaseClass::a = 87;

// void SetBaseClassA(int val)
// {
//     BaseClass::a = val;
// }






// THIS DOES NOT WORK  !!!!
// qualified name is not allowed
// class BaseClass
// {
// public:
//     static int a;
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };

// void SetBaseClassA(int val)
// {
//     int BaseClass::a = 87;
// }








// THIS DOES NOT WORK !!!!!
// undefined reference to BaseClass::a (LINKER ERROR)
// class BaseClass
// {
// public:
//     static int a;
//     void print()
//     {
//         cout    <<  "a = "   <<  a   <<  "\n";
//     }
// };








// THIS DOES NOT WORK !!!!!!
// only nonstatic member functions may be virtual
// class BaseClass
// {
    
// public:
//     virtual static int print()
//     {
//         cout    <<  "BaseClass" <<  "\n";
//     }

// };










// THIS WORKS !!!!!!!!!
// class BaseClass
// {
    
// public:
//     static void print()
//     {
//         cout    <<  "BaseClass" <<  "\n";
//     }

// };

// class DerivedClass : public BaseClass
// {
// public:
//     static void print()
//     {
//         BaseClass::print();
//         cout    <<  "DerivedClass"  <<  "\n";
//     }
// };








// THIS DOES NOT WORK !!!!!!
// a nonstatic member reference must be relative to a specific object
// class BaseClass
// {
    
// public:
//     void print()
//     {
//         cout    <<  "BaseClass" <<  "\n";
//     }

// };

// class DerivedClass : public BaseClass
// {
// public:
//     static void print()
//     {
//         BaseClass::print();
//         cout    <<  "DerivedClass"  <<  "\n";
//     }
// };








// THIS WORKS !!!!!
// If we create more objects, the "count" variable in the static function will have the same value across all objects
class BaseClass
{

public:
    void print(){
        static int count = 0;
        count += 1;
        std::cout   <<  count   <<  "\n";
    }
};


int main(){
    BaseClass baseClass1, baseClass2;
    
    baseClass1.print();
    baseClass1.print();
    baseClass1.print();

    baseClass2.print();
    baseClass2.print();
    baseClass2.print();


    return 0;
}