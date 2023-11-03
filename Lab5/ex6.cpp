#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class Sportiv
{
    public:
        virtual bool esteCampionEuropean() const
        {
            return false;
        }
        virtual void activitateFizicaSpecifica() const = 0;

        // Destructor virtual
        // Este recomandat a fi folosit în special atunci cand
        // Avem de gand sa folosim alocari dinamice in clasele derivate
        virtual ~Sportiv()
        {
            std::cout << "~Sportiv()" << std::endl;
        }
};

class Maratonist : public Sportiv
{
    private:
        unsigned int h, m;

    public:
        Maratonist(unsigned int h, unsigned int m) : h(h), m(m) {}

        Maratonist()
        {
            h = 3;
            m = rand() % 60;
        }

        ~Maratonist() override
        {
            std::cout << "~Maratonist()" << std::endl;
        }

        bool esteCampionEuropean() const override
        {
            if (m < 5) // daca alearga in mai putin de 3h05min
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void activitateFizicaSpecifica() const override
        {
            std::cout << "Am alergat 42 km in " << h << " ore si " << m << " minute" << std::endl;
        }
};

class Powerlifter : public Sportiv
{
    private:
        unsigned int greutate;

    public:

        Powerlifter(unsigned int greutate) : greutate(greutate) {}

        Powerlifter()
        {
            unsigned int base = 100;
            unsigned int extra = rand() % 100;
            greutate = base + extra;
        }

        ~Powerlifter() override
        {
            std::cout << "~Powerlifter()" << std::endl;
        }

        bool esteCampionEuropean() const override
        {
            if (greutate > 190)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void activitateFizicaSpecifica() const override
        {
            std::cout << "Am impins " << greutate << " kg" << std::endl;
        }        
};

int main()
{
    srand(time(0));

    std::vector<Sportiv*> sportivi;

    while(true)
    {
        std::string str;
        std::cin >> str;
        if (str[0] == 'm')
        {
            unsigned int m, h;
            std::cin >> h;
            std::cin >> m;
            sportivi.push_back(new Maratonist(h, m));
        }
        else if (str[0] == 'p')
        {
            unsigned int g;
            std::cin >> g;
            sportivi.push_back(new Powerlifter(g));
        }
        else
        {
            break;
        }
    }

    for (std::vector<Sportiv*>::iterator it = sportivi.begin(); it != sportivi.end(); ++it)
    {
        (*it)->activitateFizicaSpecifica();
        delete (*it);
    }

    return 0;
}