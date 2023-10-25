#include <iostream>
#include "Student.hpp"

int main()
{
    Student s{"Popescu Ion", 24};

    s.addGrade("POO", 9.5);
    s.addGrade("AI", 10);
    s.addGrade("Probabilitati", 8);

    std::cout << s;

    return 0;
}