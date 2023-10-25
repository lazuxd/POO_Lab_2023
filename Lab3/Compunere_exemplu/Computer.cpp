#include "Computer.hpp"

Computer::Computer()
{

}

void Computer::adunaDouaNumereDeLaTastatura()
{
    while (true)
    {
        char ch = kb.citesteCaracterulActual();
        if (ch >= '0' && ch <= '9')
        {
            std::string s{ch};
            ram.stocheazaDate(s);
            break;
        }
    }

    while (true)
    {
        char ch = kb.citesteCaracterulActual();
        if (ch >= '0' && ch <= '9')
        {
            char num1 = ram.citesteDateleStocate()[0];
            char num2 = ch;

            int n1 = num1 - 48; // 48 este codul ASCII pentru caracterul '0'
            int n2 = num2 - 48;

            int rezultat = cpu.efectueazaOperatieMatematica(n1, n2);
            std::cout << "Rezultatul este: " << rezultat << std::endl;
            break;
        }
    }

    
    
}
void Computer::afiseazaUtilizareCPU()
{
    cpu.nivelUtilizare();
}