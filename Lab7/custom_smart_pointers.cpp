#include <iostream>
#include <cmath>

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

template <typename T>
class SmartPointer
{
    private:
        T* ptr;
    
    public:
        SmartPointer() = delete;

        SmartPointer(T* _ptr) : ptr(_ptr) {}

        SmartPointer<T>& operator=(T* _ptr)
        {
            this->ptr = _ptr;
        }

        T& operator*()
        {
            return *ptr;
        }

        T* operator->()
        {
            return ptr;
        }

        ~SmartPointer()
        {
            delete ptr;
        }
};

void doWeirdStuffWithPointers()
{
    SmartPointer<Complex<double> > ptr1 = new Complex<double>(2.4, 1.3);
    SmartPointer<Complex<double> > ptr2 = new Complex<double>(5.3, 6.3);
    Complex<double> z = *ptr1 + *ptr2;
    ptr1->afisare();
    z.afisare();
}

int main()
{
    doWeirdStuffWithPointers();

    // ...

    return 0;
}