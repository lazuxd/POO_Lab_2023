#include <iostream>

class CPU
{
    private:
        int cores;
    
    public:
        CPU() {}
        CPU(int _cores) : cores(_cores) {}
};

class RAM
{
    private:
        int size;
    
    public:
        RAM() {}
        RAM(int _size) : size(_size) {}
};

class Storage
{
    private:
        int storageSize;
    
    public:
        Storage() {}
        Storage(int _storageSize) : storageSize(_storageSize) {}
};

class OS
{
    private:
        std::string type;
    
    public:
        OS() {}
        OS(std::string _type) : type(_type) {}
};

class Smartphone
{
    private:
        CPU cpu;
        RAM ram;
        Storage storage;
        OS os;
    
    public:
        Smartphone() {

        }

        Smartphone(CPU _cpu, RAM _ram, Storage _storage, OS _os)
        : cpu(_cpu), ram(_ram), storage(storage), os(_os)
        {

        }

        void setCpu(CPU _cpu)
        {
            cpu = _cpu;
        }

        void setRam(RAM _ram)
        {
            ram = _ram;
        }

        void setStorage(Storage _storage)
        {
            storage = _storage;
        }

        void setOs(OS _os)
        {
            os = _os;
        }
};

class SmartphoneBuilder
{
    private:
        Smartphone s;
    
    public:

        SmartphoneBuilder()
        {

        }

        SmartphoneBuilder& buildCPU(int cores)
        {
            s.setCpu(CPU(cores));
            return *this;
        }

        SmartphoneBuilder& buildRAM(int size)
        {
            s.setRam(RAM(size));
            return *this;
        }

        SmartphoneBuilder& buildStorage(int storageSize)
        {
            s.setStorage(Storage(storageSize));
            return *this;
        }

        SmartphoneBuilder& buildOS(std::string osType)
        {
            s.setOs(OS(osType));
            return *this;
        }

        Smartphone getSmartphone()
        {
            return s;
        }
};

class SmartphoneDirector
{
    private:
        SmartphoneBuilder* sb;
    
    public:
        void setBuilder(SmartphoneBuilder* _sb)
        {
            sb = _sb;
        }

        void buildSmartphone()
        {
            sb->buildCPU(4).buildRAM(16).buildStorage(512).buildOS("Android");
        }
};

int main()
{
    SmartphoneBuilder sb;
    SmartphoneDirector director;
    director.setBuilder(&sb);
    director.buildSmartphone();

    Smartphone s = sb.getSmartphone();

    return 0;
}