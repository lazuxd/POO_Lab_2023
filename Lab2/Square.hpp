#pragma once
#include <iostream>

class Square
{
    private:
        int value;
    
    public:

        // Constructor implicit
        Square();

        // Constructor de inițializare
        Square(int val);

        // metodă statică, se poate accesa folosind Piesa::MoveOrMerge(...)
        // Deci apelată direct folosind clasa Piesa
        static bool MoveOrMerge(Square& a, Square& b, const bool& onlyMove);

        friend std::ostream& operator<<(std::ostream &os, const Square &p);

        bool operator==(const Square &b);

        bool isEmpty();
    
        // Este preferat să folosiți const în toate locurile
        // în care nu intenționați să modificați vreun atribut
        int getValue() const;

        void setValue(int val);
};