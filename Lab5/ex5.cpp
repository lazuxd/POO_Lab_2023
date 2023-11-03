#include <iostream>
#include <cstdlib>
#include <ctime>

// Clasa Sportiv din ex4 mai poate fi numita de asemenea o Interfata
// Interfata = clasa care are toate metodele pur virtuale
// Acum ii mai adaugam o metoda care nu este pur virtuala
// pentru a fi doar clasa abstracta, nu interfata
class Sportiv
{
    public:
        // Asta e metoda virtuala, dar nu pur virtuala
        // pentru ca are o implementare in clasa de baza
        virtual bool esteCampionEuropean()
        {
            return false;
        }
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

        bool esteCampionEuropean() override
        {
            if (m < 5) // daca alearga un maraton in mai putin de 3h05min
            {
                return true;
            }
            else
            {
                return false;
            }
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

        bool esteCampionEuropean() override
        {
            if (extra > 90) // daca impinge mai mult de 190 kg
            {
                return true;
            }
            else
            {
                return false;
            }
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

    // Sportiv* s = new Sportiv(); // Tot nu se poate instantia, deoarece inca are metode pur virtuale
    Maratonist* m = new Maratonist();
    Powerlifter* p = new Powerlifter();

    // s->activitateFizicaSpecifica(); // ... prea generala ...
    m->activitateFizicaSpecifica(); // ... am alergat ...
    p->activitateFizicaSpecifica(); // ... am impins ...

    std::cout << "Este campion european maratonistul nostru: " << m->esteCampionEuropean() << std::endl;
    std::cout << "Este campion european powerlifterul nostru: " << p->esteCampionEuropean() << std::endl;

    Sportiv* s2 = m; // Insa putem avea pointeri catre clase abstracte
    Sportiv* s3 = p;

    s2->activitateFizicaSpecifica(); // ... am alergat ...
    s3->activitateFizicaSpecifica(); // ... am impins ...

    return 0;
}