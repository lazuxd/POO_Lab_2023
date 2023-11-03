#include <iostream>
#include <cstdlib>
#include <ctime>

class Sportiv
{
    public:
        // Adaugam virtual/override fata de ex1
        virtual void activitateFizicaSpecifica()
        {
            std::cout << "Clasa prea generala. Nu avem ce face aici" << std::endl;
        }
};

class Maratonist : public Sportiv
{
    private:
        unsigned int h, m;

    public:

        Maratonist()
        {
            h = 3;
            m = rand() % 60;
        }

        void activitateFizicaSpecifica() override
        {
            std::cout << "Am alergat 42 km in " << h << " ore si " << m << " minute" << std::endl;
        }
};

class Powerlifter : public Sportiv
{
    private:
        unsigned int base, extra;

    public:

        Powerlifter()
        {
            base = 100;
            extra = rand() % 100;
        }

        void activitateFizicaSpecifica() override
        {
            std::cout << "Am impins " << (base+extra) << " kg" << std::endl;
        }
};

int main()
{
    srand(time(0));

    Sportiv s;
    Maratonist m;
    Powerlifter p;

    s.activitateFizicaSpecifica(); // ... prea generala ...
    m.activitateFizicaSpecifica(); // ... am alergat ...
    p.activitateFizicaSpecifica(); // ... am impins ...

    Sportiv s2 = m;
    Sportiv s3 = p;

    s2.activitateFizicaSpecifica(); // ... prea generala ...
    s3.activitateFizicaSpecifica(); // ... prea generala ...

    // Am obtinut acelasi output ca si in ex1, desi am folosit virtual/override...
    // Deci ce se intampla?

    return 0;
}