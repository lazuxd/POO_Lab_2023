#include <iostream>

class A
{
    public:
        virtual void f()
        {
            std::cout<<"A"<<std::endl;
        }
};

class B
{
    public:
        virtual void f()=0;
};

class C : public A, public B
{
    public:
        void f() override
        {
            A::f();
        }
};

int main()
{
    C c;
    c.f();
    c.A::f();
    // c.B::f();

    return 0;
}