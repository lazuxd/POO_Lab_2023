#include <iostream>
#include "CPU.hpp"

CPU::CPU() :
    nucleu1(0.8),
    nucleu2(0.4)
{
}

void CPU::nivelUtilizare()
{
    std::cout << "Nivel utilizare: nucleu1 = " << nucleu1 << " ; nucleu2 = " << nucleu2 <<std::endl;
}

int CPU::efectueazaOperatieMatematica(int a, int b)
{
    return a+b;
}