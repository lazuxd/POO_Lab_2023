#include <iostream>
#include "LivingBeing.hpp"

class Human : public LivingBeing
{
    private:
        int age;
        std::string name;

    public:

        Human(const std::string& name, const int& age);

        friend std::ostream& operator<<(std::ostream& os, const Human& h);

        int getAge() const;
};