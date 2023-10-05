#include <iostream>
#include <uchar.h>
using namespace std;

int main ()
{
    const unsigned short* ceva1 = new unsigned short(311);
    const char16_t* ceva2 = (const char16_t*) ceva1;

    cout << *ceva2 << "\n";

    return 0;
}