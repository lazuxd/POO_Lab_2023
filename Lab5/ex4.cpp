#include <iostream>
#include <cstdlib>
#include <ctime>

class Sportiv
{
    public:
        
        // Daca este prea generala pentru a face o implementare cu sens,
        // putem chiar sa nu o implementam
        // Asta se poate face folosind " = 0" imadiat dupa declaratie
        // Aceasta este acum o metoda pur virtuala
        // Iar clasa Sportiv devine clasa abstracta, aceasta nu mai poate
        // fi instantiata (adica nu putem crea obiecte dintr-o clasa abstracta)
        virtual void activitateFizicaSpecifica() = 0;
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

        // Metoda aceasta fiind pur virtuala in clasa de baza, suntem obligati sa o suprascriem
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

        // Metoda aceasta fiind pur virtuala in clasa de baza, suntem obligati sa o suprascriem
        void activitateFizicaSpecifica() override
        {
            std::cout << "Am impins " << (base+extra) << " kg" << std::endl;
        }
};

int main()
{
    srand(time(0));

    // Sportiv* s = new Sportiv(); // Nu mai putem creea obiecte de tip Sportiv
    Maratonist* m = new Maratonist();
    Powerlifter* p = new Powerlifter();

    // s->activitateFizicaSpecifica(); // ... prea generala ...
    m->activitateFizicaSpecifica(); // ... am alergat ...
    p->activitateFizicaSpecifica(); // ... am impins ...

    Sportiv* s2 = m; // Insa putem avea pointeri catre clase abstracte
    Sportiv* s3 = p;

    s2->activitateFizicaSpecifica(); // ... am alergat ...
    s3->activitateFizicaSpecifica(); // ... am impins ...

    return 0;
}