#include <iostream>
#include <map>
#include "Human.hpp"

class Student : public Human
{
    private:
        std::map<std::string, float> note;
    
    public:

        Student(const std::string& name, const int& age);

        void addGrade(const std::string& materie, float nota);

        void afiseazaNotele(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, const Student& s);
};