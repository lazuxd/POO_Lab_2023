#include <iostream>

class MathUtils
{
    public:
        static double PI;
        static int sum(int a, int b);
        static double log(double x);
};

class A
{
    private:
        int n;
        A(int n) : n(n) {}
    public:
        static A& GetInstance()
        {
            static A a = A(400);
            return a;
        }
};

double MathUtils::PI = 3.14;

int MathUtils::sum(int a, int b)
{
    return a+b;
}
double MathUtils::log(double x)
{
    return 1.0;
}

int increment()
{
    static int i = -1;
    ++i;
    return i;
}

int main()
{
    std::cout<<increment()<<std::endl;
    std::cout<<increment()<<std::endl;
    std::cout<<increment()<<std::endl;
    std::cout<<increment()<<std::endl;

    A::GetInstance();

    return 0;
}