#include <iostream>
#include <cmath>
#include <memory>

template <typename T>
class Complex
{
    private:
        T real, imaginar;
    
    public:
        Complex() = delete;

        Complex(const T& _real, const T& _imaginar)
        : real(_real),
          imaginar(_imaginar)
        {
            std::cout << "Construieste un obiect de tip Complex" << std::endl;
        }

        Complex<T> operator+(const Complex<T>& z)
        {
            return Complex<T>(real+z.real, imaginar+z.imaginar);
        }

        T norm() const
        {
            return sqrt(real*real + imaginar*imaginar);
        }

        void afisare() const
        {
            std::cout << "z = " << real << " + i * " << imaginar << std::endl;
        }

        ~Complex()
        {
            std::cout << "Obiect de tip Complex este distrus" << std::endl;
        }
};

std::shared_ptr<Complex<double> > doWeirdStuffWithPointers()
{
    std::shared_ptr<Complex<double> > ptr1 = std::make_shared<Complex<double> >(2.4, 1.3);
    std::shared_ptr<Complex<double> > ptr2 = ptr1;
    Complex<double> z = *ptr1 + *ptr2;
    ptr1->afisare();
    z.afisare();

    return ptr1;
}

class A;
class B;

class A
{
    public:
        std::weak_ptr<B> b;

        A()
        {
            std::cout << "A()" << std::endl;
        }

        void dummyMethod()
        {

        }

        ~A()
        {
            std::cout << "~A()" << std::endl;
        }
};

class B
{
    public:
        std::weak_ptr<A> a;

        B()
        {
            std::cout << "B()" << std::endl;
        }

        void dummyMethod()
        {
            
        }

        ~B()
        {
            std::cout << "~B()" << std::endl;
        }
};

void circularReferences()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b = b;
    b->a = a;

    std::shared_ptr<B> b2 = a->b.lock();
    if (b2 != nullptr)
    {
        b2->dummyMethod();
    }
}

int main()
{
    // auto ptr = doWeirdStuffWithPointers();

    // std::cout << "Am revenit in main" << std::endl;

    circularReferences();

    // std::auto_ptr<Complex<int> > cPtr(new Complex(1, 2));
    // cPtr->afisare();

    return 0;
}