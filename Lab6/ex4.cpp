#include <iostream>

class A
{
    public:
        virtual void f()
        {
            std::cout<<"A"<<std::endl;
        }
};

class B : public A
{
    public:
        void f() override
        {
            std::cout<<"B"<<std::endl;
        }
};

class C : public A
{
    public:
        void f() override
        {
            std::cout<<"C"<<std::endl;
        }
};


int main()
{
    A* a = new B();

    B* b = dynamic_cast<B*>(a);
    C* c = dynamic_cast<C*>(a);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}