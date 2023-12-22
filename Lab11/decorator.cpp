#include <iostream>

// class ComplexInterface
// {
//     ComplexInterface* add(const Complex& other)
//     {
//         return Complex(realPart+other.realPart, imagPart+other.imagPart);
//     }

//     ComplexInterface* multiply(const Complex& other)
//     {
//         return Complex(0.0, 0.0);
//     }
// };

class Complex
{
    private:
        float realPart, imagPart;
    
    public:
        Complex(float real, float imag)
        : realPart(real),
          imagPart(imag)
        {

        }

        float getReal() const
        {
            return realPart;
        }

        float getImag() const
        {
            return imagPart;
        }

        Complex add(const Complex& other)
        {
            return Complex(realPart+other.realPart, imagPart+other.imagPart);
        }

        Complex multiply(const Complex& other)
        {
            return Complex(0.0, 0.0);
        }
};

class ComplexMultiplyDecorator
{
    private:
        Complex c;
    public:
        ComplexMultiplyDecorator(const Complex& _c)
        : c(_c)
        {}

        ComplexMultiplyDecorator add(const Complex& other)
        {
            return c.add(other);
        }

        ComplexMultiplyDecorator multiply(const Complex& other)
        {
            Complex c_new(c.getReal()*other.getReal() - c.getImag()*other.getImag(),
                            other.getReal()*c.getImag() + c.getReal()*other.getImag());

            return ComplexMultiplyDecorator(c_new);
        }

        Complex getComplex() const
        {
            return c;
        }
};

int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(5.0, 4.0);

    ComplexMultiplyDecorator cd1(c1);

    Complex c = cd1.multiply(c2).getComplex();

    std::cout<<c.getReal() << " ; " << c.getImag() << std::endl;

    return 0;
}