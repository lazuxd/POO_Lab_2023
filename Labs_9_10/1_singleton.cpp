#include <iostream>

class DataReader
{
    public:
        virtual std::string getData() = 0;
};

class DataWriter
{
    public:
        virtual void writeDataToFile(const std::string& path) = 0;
};

class DatabaseMgr : public DataReader, public DataWriter
{
    private:
        DatabaseMgr() {}
        DatabaseMgr(DatabaseMgr& a) {}
        
    public:

        static DatabaseMgr& GetInstance()
        {
            static DatabaseMgr instance;
            return instance;
        }

        std::string getData() override
        {
            return "data from db";
        }

        void writeDataToFile(const std::string& path) override
        {
            std::cout << "Salvam datele in fisierul: " << path << std::endl;
        }
};

void showData(DataReader& dataReader)
{
    std::cout << dataReader.getData() << std::endl;
}

int main()
{

    std::cout<<"Datele noastre sunt: " << DatabaseMgr::GetInstance().getData() << std::endl;
    showData(DatabaseMgr::GetInstance());

    return 0;
}