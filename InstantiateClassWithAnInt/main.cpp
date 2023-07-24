// #include <iostream>
// using namespace std;

// class classA{
// public:
//     classA(int i){
//         cout    <<  "CREATING A CLASS A WITH AN INT I OF"   <<  i   <<  "\n";
//     }
// };

// int main(){
//     classA classA = 73;


//     return 0;
// }


// #include <string>
// #include <utility>
// #include <memory>
 
// int main()
// {
//     std::string s = "test"; // OK: constructor is non-explicit
//     std::string s2 = std::move(s); // this copy-initialization performs a move
 
//     std::unique_ptr<int> p = new int(1); // error: constructor is explicit
//     std::unique_ptr<int> p(new int(1)); // OK: direct-initialization
 
//     int n = 3.14;    // floating-integral conversion
//     const int b = n; // const doesn't matter
//     int c = b;       // ...either way

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main(){

//     int* a = new int(1265);
//     cout    <<  *a   <<  "\n";

//     return 0;
// }



// THIS IS NOT WORKING !!!!!!!
/*
#include <iostream>
using namespace std;

class MyClass {
public:
    explicit MyClass(int value) {
        // Constructor implementation
    }
};

int main() {
    MyClass obj = 10; // Error: Cannot use explicit constructor for implicit conversion

    MyClass obj2(10); // OK: Direct initialization

    return 0;
}
*/









// THIS IS WORKING !!!!!!!!
/*
#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass(int value1, int value2)
    {

    }    
};

int main ()
{
    MyClass myClass(10, 20);


    return 0;
}
*/

