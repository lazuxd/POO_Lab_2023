#include <iostream>

template <typename T>
T sum(T* numbers, unsigned int size)
{
    T result = 0;
    for (int i = 0; i < size; ++i)
    {
        result += numbers[i];
    }
    return result;
}

template<> // Template specialization
bool sum<bool>(bool* numbers, unsigned int size)
{
    bool result = false;
    for (int i = 0; i < size; ++i)
    {
        result = result || numbers[i];
    }
    std::cout<<"sum<bool>()"<<std::endl;
    return result;
}

int main()
{
    int ints[3] = {1, 2, 3};
    std::cout << sum<int>(ints, 3) << std::endl;

    double doubles[3] = {2.71, 3.14, 1.9};
    std::cout << sum<double>(doubles, 3) << std::endl;

    float floats[3] = {5.7, 8.14, 1.9};
    std::cout << sum<float>(floats, 3) << std::endl;

    bool bools[3] = {true, false, false};
    std::cout << sum<bool>(bools, 3) << std::endl;

    return 0;
}