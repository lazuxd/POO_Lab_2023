#include <iostream>

// class Num
// {
//     int n;

//     public:

//         Num() = delete;
//         Num(int n) : n(n) {}

//         // bool operator<(const Num & b)
//         // {
//         //     return this->n < b.n;
//         // }

//         friend bool operator<(const Num &a, const Num &b)
//         {

//         }

//         int operator()(int a, int b, int c, int d)
//         {

//         }
// };

// class A;
// class B;

// class A
// {
//     int a;
//     public:
//         A(int a) : a(a) {}
//         int getVal() const
//         {
//             return a;
//         }
// };

// class B
// {
//     int b;
//     public:
//         B(int b) : b(b) {}
//         int getVal() const
//         {
//             return b;
//         }
// };

// bool operator<(const A& a, const B& b)
// {
//     return a.getVal() < b.getVal();
// }


// class P
// {
//     protected:
//         int a = 1;
//     public:
//         P()
//         {
//             std::cout << "P()" << std::endl;
//         }
//         ~P() {std::cout << "~P()" << std::endl;}
// };

// class C : public P
// {
//     protected:
//         int a = 2;
//     public:
//         C()
//         : P()
//         {
//             std::cout << "C()" << std::endl;
//             std::cout << P::a << std::endl;
//             std::cout << a << std::endl;
//         }

//         ~C()
//         {
//             std::cout << "~C()" << std::endl;
//         }
// };


// class P
// {
//     public:
//         virtual void f()
//         {
//             std::cout << "P::f()" << std::endl;
//         }
// };

// class C : public P
// {
//     public:
//         void f() override
//         {
//             std::cout << "C::f()" << std::endl;
//         }
// };

// class C2 : public C
// {
//     public:
//         void f() override
//         {
//             std::cout << "C2::f()" << std::endl;
//         }
// };


class P
{
    protected:
        int a;
    public:
        P(int val) : a(val) {}
        int getVal() const
        {
            return a;
        }
        virtual P operator+(const P& p) const
        {
            return P{this->a + p.a};
        }
};

class C : public P
{
    public:
        C(int val) : P(val) {}

        // C operator+(const C& c) const
        // {
        //     return C{this->a + c.a};
        // }
};


int main()
{
    P p1{1}, p2{2};
    P p3 = p1+p2;
    std::cout<<p3.getVal()<<std::endl;

    C c1{1}, c2{2};
    P p4 = c1+p2;
    std::cout<<p3.getVal()<<std::endl;

    return 0;
}