#include <iostream>

// THIS WORKS !!!!!!!
/*
namespace Whoa
{
    class Test
    {
    };

    void DoStuff(Test t)
    {
        std::cout << "Doing stuff in namespace Whoa\n";
    }
}

int main()
{
    Whoa::Test test;

    DoStuff(test);              // ADL
    // ADL stands for "Argument-Dependent Lookup," which is a mechanism
    // in C++ that allows unqualified function or operator names to be
    // looked up in the namespaces of the function arguments


    return 0;
}
*/






// THIS DOES NOT WORK !!!!!
// 'cout' was not declared in this scope; did you mean 'std::cout'?
// even though we call the cout function with an argument that is of a type defined in std
// I dont know why, I could not find an answer
/*
int main()
{
    std::string str ("Un string");
    cout << str;

    return 0;
}
*/
