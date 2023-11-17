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
          imaginar(_imaginar) {}

        T norm() const
        {
            return sqrt(real*real + imaginar*imaginar);
        }

        void afisare() const
        {
            std::cout << "z = " << real << " + i * " << imaginar << std::endl;
        }
};

int main()
{
    Complex<double> z1{1.4, 3.2};
    Complex<unsigned int> z2{4, 3};

    z1.afisare();
    z2.afisare();

    return 0;
}