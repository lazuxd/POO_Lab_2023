#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Computer.hpp"

int main()
{
    srand(time(0));

    Computer c;
    c.adunaDouaNumereDeLaTastatura();
    c.afiseazaUtilizareCPU();

    return 0;
}