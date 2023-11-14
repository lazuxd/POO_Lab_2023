#include <iostream>
#include <exception>

class ZeroDivision : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "Impartire la 0! Eroare!";
        }
};

double divide(double a, double b)
{
    if (b == 0.0)
    {
        throw ZeroDivision();
    }
    return a / b;
}

int main()
{
    double x = 5.0, y = 0.0;
    const double EPS = 0.001;

    try
    {
        std::cout << divide(x, y) << std::endl;
    }
    catch(const ZeroDivision& e)
    {
        std::cout << divide(x, y+EPS) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}