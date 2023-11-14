#include <iostream>

double sum(void* ptr, std::string type)
{
    if (type == "double")
    {
        double* d = reinterpret_cast<double*>(ptr);
        return d[0]+d[1];
    }
    else if (type == "int")
    {
        int* i = reinterpret_cast<int*>(ptr);
        return i[0]+i[1];
    }
    return 0.0;
}

int main()
{
    double* doubleArr = new double[3];
    doubleArr[0] = 1.5;
    doubleArr[1] = 3.1;
    doubleArr[2] = 7.9;

    int* intArr = new int[2];
    intArr[0] = 3;
    intArr[1] = 5;

    std::cout << sum(doubleArr, "double") << std::endl;
    std::cout << sum(intArr, "int") << std::endl;

    return 0;
}