#include <iostream>
using namespace std;




// THIS IS NOT WORKING!!!!!!
/*
class BaseClass
{

};

class DerivedClass: private BaseClass
{

};


int main(){
    BaseClass* baseClass = new DerivedClass();

    return 0;
}
*/














// THIS IS NOT WORKING!!!!!!
/*
class BaseClass
{

};

class DerivedClass: protected BaseClass
{

};


int main(){
    BaseClass* baseClass = new DerivedClass();

    return 0;
}
*/














// THIS IS WORKING !!!!!!!
/*
class BaseClass
{

};

class DerivedClass: public BaseClass
{

};


int main(){
    BaseClass* baseClass = new DerivedClass();

    return 0;
}
*/















class BaseClass
{
public:
    virtual void Print()
    {
        cout << "Hello from BaseClass" << "\n";
    }
    static void FunctionToPrint(BaseClass* ptr)
    {
        cout << "Function from BaseClass" << "\n";
        ptr->Print();
    }
};

class DerivedClass : public BaseClass
{
public:
    void Print()
    {
        cout << "Hello from DerivedClass" << "\n";
    }
    void FunctionToPrint(BaseClass* ptr)
    {
        cout << "Function from DerivedClass" << "\n";
        BaseClass::FunctionToPrint(ptr);
    }
};

class ThirdDerivedClass : public DerivedClass
{
public:
    void Print()
    {
        cout << "Hello from ThirdDerivedClass" << "\n";
    }
    static void FunctionToPrint(BaseClass* ptr)
    {
        cout << "Function from ThirdDerivedClass" << "\n";
        BaseClass::FunctionToPrint(ptr);
    }
};


int main(){
    BaseClass* baseClassPtr = new BaseClass();


    ThirdDerivedClass* thirdDerivedPtr = new ThirdDerivedClass();
    ThirdDerivedClass::FunctionToPrint(thirdDerivedPtr);

    return 0;
}