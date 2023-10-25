#include "CPU.hpp"
#include "RAM.hpp"
#include "Keyboard.hpp"

class Computer
{
    private:
        CPU cpu;
        RAM ram;
        Keyboard kb;

    public:

        Computer();
        void adunaDouaNumereDeLaTastatura();
        void afiseazaUtilizareCPU();
};