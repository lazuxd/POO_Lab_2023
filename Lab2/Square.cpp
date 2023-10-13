#include "Square.hpp"

// Constructor implicit
Square::Square()
{
    value = 0;
}

// Constructor de inițializare
Square::Square(int val)
: value(val)
{
}

// metodă statică, se poate accesa folosind Piesa::MoveOrMerge(...)
// Deci apelată direct folosind clasa Piesa
bool Square::MoveOrMerge(Square& a, Square& b, const bool& onlyMove)
{
    bool change = false;

    if (!b.isEmpty())
    {
        if (a.isEmpty())
        { // Mutam piesa
            a.setValue(
                b.value);
            b.setValue(0);
            change = true;
        }
        else if (!onlyMove && a == b)
        { // Facem merge
            a.setValue(
                a.value + b.value);
            b.setValue(0);
            change = true;
        }
    }

    return change;
}

std::ostream& operator<<(std::ostream &os, const Square &p)
{
    os << p.value;
    return os;
}

bool Square::operator==(const Square &b)
{
    return this->value == b.value;
}

bool Square::isEmpty()
{
    return value == 0;
}

// Este preferat să folosiți const în toate locurile
// în care nu intenționați să modificați vreun atribut
int Square::getValue() const
{
    return value;
}

void Square::setValue(int val)
{
    this->value = val;
}