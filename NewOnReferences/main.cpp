#include <iostream>
using namespace std;

int main() {
    int *x = new int(10);
    int& ref = *new int(475);  // Reference to variable x

    std::cout << "Address of x: " << x << std::endl;   // Print address of x
    std::cout << "Address referred to by ref: " << ref << std::endl;  // Print address referred to by ref

    delete &ref;
    return 0;
}