#include "Student.hpp"

Student::Student(const std::string& name, const int& age)
: Human(name, age)
{
    
}

void Student::addGrade(const std::string& materie, float nota)
{
    note.insert(std::pair<std::string, float>(materie, nota));
}

void Student::afiseazaNotele(std::ostream& os) const
{
    for (std::map<std::string, float>::const_iterator it = note.cbegin();
            it != note.cend(); ++it)
    {
        os << "Materia: " << it->first << " ; Nota: " << it->second << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    const Human* h = &s;

    os << (*h); // folosim operatorul << din clasa parinte

    s.afiseazaNotele(os);

    return os;
}