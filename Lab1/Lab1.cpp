#include <iostream>

/*

Cum putem implementa jocul 2048?

Am avea nevoie de variabile în care să stocăm status-ul curent al jocului:
state = 
[
    [0, 2, 0],
    [2, 0, 0],
    [0, 0, 0]
]
score = 10

Și am mai avea nevoie de câteva funcții ajutătoare, cum ar fi:
int* moveLeft(state)
int* moveRight(state)
...

Ce se întâmplă dacă avem de executat mai multe jocuri concomitent? (să spunem ca vrem să fie un fel de joc multiplayer)

La un moment dat lucrurile se vor complica dstul de mult și noi modificări vor fi greu de făcut, dacă nu avem codul structurat mai bine.
Clasele ajută la acest lucru. Pe lângă asta, clasele (și restul conceptelor de POO) au multe alte beneficii care vor mai fi discutate orele următoare.
*/

class Piesa
{
    private:
        int value;
    
    public:

        // Constructor implicit
        Piesa()
        {
            value = 0;
        }

        // Constructor de inițializare
        Piesa(int val)
        : value(val)
        {
        }

        // metodă statică, se poate accesa folosind Piesa::MoveOrMerge(...)
        // Deci apelată direct folosind clasa Piesa
        static void MoveOrMerge(Piesa& a, Piesa& b)
        {
            if (!b.isEmpty())
            {
                if (a.isEmpty())
                {
                    a.setValue(
                        b.value);
                    b.setValue(0);

                }
                else if (a == b)
                {
                    a.setValue(
                        a.value + b.value);
                    b.setValue(0);
                }
            }
        }

        friend std::ostream& operator<<(std::ostream &os, const Piesa &p)
        {
            os << p.value;
            return os;
        }

        bool operator==(const Piesa &b)
        {
            return this->value == b.value;
        }

        bool isEmpty()
        {
            return value == 0;
        }
    
        // Este preferat să folosiți const în toate locurile
        // în care nu intenționați să modificați vreun atribut
        int getValue() const
        {
            return value;
        }

        void setValue(int val)
        {
            this->value = val;
        }
};

// Clasa asta e mai întâi declarată și pe urmă urmează implementarea
class Board
{
    public:
        // Am făcut acest atribut 'static const' pentru că nu avem de gând să schimbăm
        // valoarea asta de la obiect la altul
        static const int C_BOARD_SIZE = 3;

        Board();
        Board(const Board& b); // Constructor de copiere
        void printInfo();
        friend std::ostream& operator<<(std::ostream& os, const Board &b);
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        unsigned int getScore() const;
        void updateScore();
    
    private:
        Piesa state[C_BOARD_SIZE][C_BOARD_SIZE];
        unsigned int score;
};


Board::Board()
{
    std::cout << "Constructorul implicit este apelat" << std::endl;
    state[0][0] = Piesa(2);
    state[1][1] = Piesa(2);
}

Board::Board(const Board& b)
{
    std::cout << "Constructorul de copiere este apelat" << std::endl;
    for (int i = 0 ; i < Board::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Board::C_BOARD_SIZE; ++j)
        {
            this->state[i][j].setValue(b.state[i][j].getValue());
        }
    }
}

void Board::printInfo()
{
    std::cout << state[0][0] << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Board &b)
{
    for (int i = 0 ; i < Board::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Board::C_BOARD_SIZE; ++j)
        {
            os << b.state[i][j] << " | ";
        }
        os << std:: endl;
    }
    return os;
}

void Board::moveLeft()
{
    for (int i = 0; i < Board::C_BOARD_SIZE; ++i)
    {
        for (int j = Board::C_BOARD_SIZE-1; j > 0; --j)
        {
            Piesa::MoveOrMerge(state[i][j-1], state[i][j]);
        }
    }
}

void Board::moveRight()
{
    for (int i = 0; i < Board::C_BOARD_SIZE; ++i)
    {
        for (int j = 0; j < Board::C_BOARD_SIZE-1; ++j)
        {
            Piesa::MoveOrMerge(state[i][j+1], state[i][j]);
        }
    }
}
void Board::moveUp()
{
    for (int j = 0; j < Board::C_BOARD_SIZE; ++j)
    {
        for (int i = Board::C_BOARD_SIZE-1; i > 0; --i)
        {
            
            Piesa::MoveOrMerge(state[i-1][j], state[i][j]);
        }
    }
}
void Board::moveDown()
{
    for (int j = 0; j < Board::C_BOARD_SIZE; ++j)
    {
        for (int i = 0; i < Board::C_BOARD_SIZE-1; ++i)
        {
            
            Piesa::MoveOrMerge(state[i][j], state[i-1][j]);
        }
    }
}

int main()
{
    // Obiect instanțiat după clasa Piesa
    // Construit folosind constructorul de inițializare
    Piesa p{4};

    // Obiect de tip Board
    // Construit folosind constructorul implicit
    Board b;
    
    std::cout << b << std::endl;

    b.moveLeft();
    std::cout << "Dupa mutare la stanga: " << std::endl;

    std::cout << b << std::endl;

    b.moveUp();

    std::cout << "Dupa mutare sus: " << std::endl;

    std::cout << b << std::endl;

    Board b2{b};

    std::cout << "Obiectul b2 (copie a lui b): " << std::endl;

    std::cout << b2 << std::endl;

    return 0;
}