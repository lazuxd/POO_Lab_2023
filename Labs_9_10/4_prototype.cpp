#include <iostream>

// class Prototype
// {
//     public:
//         virtual Prototype clone() = 0;
// };

class Computer
{
    public:

        // Ideal ar fi atributele private + getters/setters
        std::string cpuBrand;
        int cpuCores;
        std::string memoryBrand;
        int memorySize;
        int memoryChannels;
        int displayWidth;
        int displayHeight;
        std::string motherboardBrand;

        Computer(std::string _cpuBrand,
                int _cpuCores,
                std::string _memoryBrand,
                int _memorySize,
                int _memoryChannels,
                int _displayWidth,
                int _displayHeight,
                std::string _motherboardBrand)
        :   cpuBrand(_cpuBrand),
            cpuCores(_cpuCores),
            memoryBrand(_memoryBrand),
            memorySize(_memorySize),
            memoryChannels(_memoryChannels),
            displayWidth(_displayWidth),
            displayHeight(_displayHeight),
            motherboardBrand(_motherboardBrand)
        {

        }

        Computer clone()
        {
            return Computer(cpuBrand, cpuCores, memoryBrand, memorySize,
                            memoryChannels, displayWidth, displayHeight, motherboardBrand);
        }
};

int main()
{
    Computer c1{"Intel", 4, "Awesome Brand", 32, 4, 2048, 720, "Brand 123"};

    Computer c2 = c1.clone();
    c2.memoryChannels = 2;

    return 0;
}