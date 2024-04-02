// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
#include <iostream>
#include <string>
using namespace std;

class Parent1
{
protected:
    int protected_element = 0;

private:
    int private_element = 0;

public:
    int public_elememt = 0;
    int a = 9;
    void virtual print()
    {
        cout<<"Inside Parent1"<<endl;
    }
    int geta()
    {
        print();
        return a;
    }
};

class Parent2
{
public:
    int b = 3;
    int getb()
    {
        return b;
    }
};

class Child : public Parent1, private Parent2
{
private:
    static int count;

public:
    Child()
    {
        count++;
    }
    int child_element = 0;
    void print()
    {
        cout<<"Inside Child"<<endl;
    }

    int getc()
    {
        int a = geta();
        int b = getb();
        return a * b;
    }
    static int getObjects()
    {
        return count;
    }
};

int Child::count = 0;

// Functor in cpp also konwn as (Function Objects)
// Here the object of class DemoFunctor act as a function 
// Basically functors are used to store the state of function in class without using static variable which can not be done simple function

class DemoFunctor{
    private:
        int _var1;
    public:
        DemoFunctor(int val){
            _var1=val;
        }
        int operator()(int val){
            return val+_var1;
        }
};

int main()
{
    Child c;
    Parent1 *p;
    p=&c;
    // cout<<c.getc();
    c.print();
    c.Parent1::print();
    p->print();
    p->Parent1::print();
    Parent1 P;
    // P.geta();
    // cout << Child::getObjects();

    DemoFunctor d(12);
    cout<<d(6);
    return 0;
}