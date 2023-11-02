#include <iostream>

// class Parent
// {
//     protected:
//         int n;

//     public:
//         Parent(int val) : n(val) {}
// };

// class Child : public Parent
// {
//     public:
//         Child(int val) : Parent(val) {}
//         void afiseaza()
//         {
//             std::cout << n << std::endl;
//         }
// };

// class Human
// {
//     private:
//         std::string nume;
//         std::string prenume;

//         Human();

//     public:
//         explicit Human(std::string nume, std::string prenume = "")
//         : nume(nume),
//           prenume(prenume)
//         {
//             std::cout << "Human() apelat" << std::endl; 
//         }
// };

class P
{
    protected:
        typedef P Base;

    public:
        virtual void f()
        {
            std::cout << "P::f()" << std::endl;
        }
        void g()
        {
            std::cout << "P::g()" << std::endl;
        }
};

class C : public P
{
    public:
        void f() override
        {
            Base::f();
            g();
            std::cout << "C::f()" << std::endl;
        }
};

// class C2 : public C
// {
//     public:
//         void f()
//         {
//             std::cout << "C2::f()" << std::endl;
//         }
// };

int main()
{
    C c;

    c.f();

    return 0;
}