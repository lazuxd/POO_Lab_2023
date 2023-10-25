#include <iostream>
#include "Human.hpp"

Human::Human(const std::string& name, const int& age)
: name(name),
  age(age)
{

}

std::ostream& operator<<(std::ostream& os, const Human& h)
{
    os << "Nume: " << h.name << " ; varsta: " << h.age << " ; isAlive: " << h.getIsAlive() << std::endl;
    return os;
}

int Human::getAge() const
{
    return age;
}