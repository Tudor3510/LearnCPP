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













// THIS WORKS !!!!!!!!
/*
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


    ThirdDerivedClass* thirdDerivedPtr = new ThirdDerivedClass();       // Function from ThirdDerivedClass
    ThirdDerivedClass::FunctionToPrint(thirdDerivedPtr);                // Function from BaseClass
                                                                        // Hello from ThirdDerivedClass


    return 0;
}
*/













// THIS WORKS !!!!!!!!!
/*
class BaseClass
{
    public:
        virtual void PrintText() const
        {
            cout << "Hello from BaseClass" << "\n";
        }
};


class DerivedClass : public BaseClass
{
    public:
        void PrintText() const
        {
            cout << "Hello from DerivedClass" << "\n";
        }
};


class ThirdDerivedClass : public BaseClass
{
    public:
        void PrintText() const
        {
            cout << "Hello from ThirdDerivedClass" << "\n";
        }
};

int main ()
{
    BaseClass *baseClassPtr;
    
    baseClassPtr = new DerivedClass();
    baseClassPtr->PrintText();                          // Hello from DerivedClass

    cout << "\n";

    baseClassPtr = new ThirdDerivedClass();
    baseClassPtr->PrintText();                          // Hello from ThirdDerivedClass

    return 0;
}
*/


















// THIS WORKS !!!!!!!!!!!!!
// but be careful how it works
/*
class BaseClass
{
    public:
        virtual void PrintText()
        {
            cout << "Hello from BaseClass" << "\n";
        }
};


class DerivedClass : public BaseClass
{
    public:
        void PrintText() const
        {
            cout << "Hello from DerivedClass" << "\n";
        }
};


class ThirdDerivedClass : public BaseClass
{
    public:
        void PrintText() const
        {
            cout << "Hello from ThirdDerivedClass" << "\n";
        }
};

int main ()
{
    BaseClass *baseClassPtr;
    
    baseClassPtr = new DerivedClass();
    baseClassPtr->PrintText();                          // Hello from BaseClass

    cout << "\n";

    baseClassPtr = new ThirdDerivedClass();
    baseClassPtr->PrintText();                          // Hello from BaseClass

    return 0;
}
*/





















// THIS DOES NOT WORK !!!!!!
// void DerivedClass::PrintText() const' marked 'override', but does not override
/*
class BaseClass
{
    public:
        virtual void PrintText()
        {
            cout << "Hello from BaseClass" << "\n";
        }
};


class DerivedClass : public BaseClass
{
    public:
        void PrintText() const override
        {
            cout << "Hello from DerivedClass" << "\n";
        }
};


class ThirdDerivedClass : public BaseClass
{
    public:
        void PrintText() const override
        {
            cout << "Hello from ThirdDerivedClass" << "\n";
        }
};

int main ()
{
    BaseClass *baseClassPtr;
    
    baseClassPtr = new DerivedClass();
    baseClassPtr->PrintText();

    cout << "\n";

    baseClassPtr = new ThirdDerivedClass();
    baseClassPtr->PrintText();

    return 0;
}
*/
















// THIS DOES NOT WORK !!!!!!!!
// member function declared with 'override' does not override a base class member
// so you should put all the overridden function definition from the baseclass before the 'const' qualifier
/*
class BaseClass
{
    public:
        virtual void PrintText() const
        {
            cout << "Hello from BaseClass" << "\n";
        }
};


class DerivedClass : public BaseClass
{
    public:
        void PrintText() override const
        {
            cout << "Hello from DerivedClass" << "\n";
        }
};


class ThirdDerivedClass : public BaseClass
{
    public:
        void PrintText() override const
        {
            cout << "Hello from ThirdDerivedClass" << "\n";
        }
};

int main ()
{
    BaseClass *baseClassPtr;
    
    baseClassPtr = new DerivedClass();
    baseClassPtr->PrintText();

    cout << "\n";

    baseClassPtr = new ThirdDerivedClass();
    baseClassPtr->PrintText();

    return 0;
}
*/













// THIS WORKS !!!!!!!!
/*
class BaseClass
{
    public:
        virtual void PrintText() const
        {
            cout << "Hello from BaseClass" << "\n";
        }
};


class DerivedClass : public BaseClass
{
    public:
        void PrintText() const override
        {
            cout << "Hello from DerivedClass" << "\n";
        }
};


class ThirdDerivedClass : public BaseClass
{
    public:
        void PrintText() const override
        {
            cout << "Hello from ThirdDerivedClass" << "\n";
        }
};

int main ()
{
    BaseClass *baseClassPtr;
    
    baseClassPtr = new DerivedClass();
    baseClassPtr->PrintText();                          // Hello from DerivedClass

    cout << "\n";

    baseClassPtr = new ThirdDerivedClass();
    baseClassPtr->PrintText();                          // Hello from ThirdDerivedClass

    return 0;
}
*/
















// THIS WORKS !!!!!!!!!!
/*
class BaseClass
{
    public:
        virtual void PrintText() const
        {
            cout << "Hello from BaseClass" << "\n";
        }
};


class DerivedClass : public BaseClass
{
    public:
        void PrintText() const override
        {
            BaseClass::PrintText();
            cout << "Hello from DerivedClass" << "\n";
        }
};


class ThirdDerivedClass : public BaseClass
{
    public:
        void PrintText() const override
        {
            cout << "Hello from ThirdDerivedClass" << "\n";
        }
};

int main ()
{
    BaseClass *baseClassPtr;
    
    baseClassPtr = new DerivedClass();
    baseClassPtr->PrintText();                          // Hello from BaseClass
                                                        // Hello from DerivedClass

    cout << "\n";

    baseClassPtr = new ThirdDerivedClass();
    baseClassPtr->PrintText();                          // Hello from ThirdDerivedClass

    return 0;
}
*/