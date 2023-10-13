#include "Board.hpp"
#include <iomanip>
#include <cstdlib>

Game2048::Game2048()
{
    unsigned int i1 = rand() % Game2048::C_BOARD_SIZE;
    unsigned int j1 = rand() % Game2048::C_BOARD_SIZE;
    unsigned int i2 = rand() % Game2048::C_BOARD_SIZE;
    unsigned int j2 = rand() % Game2048::C_BOARD_SIZE;

    bool isTwo = rand() % 2;

    if (isTwo)
    {
        state[i1][j1] = Square(2);
    }
    else
    {
        state[i1][j1] = Square(4);
    }
    
    state[i2][j2] = Square(2);
}

Game2048::Game2048(const Game2048& b)
{
    for (int i = 0 ; i < Game2048::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Game2048::C_BOARD_SIZE; ++j)
        {
            this->state[i][j].setValue(b.state[i][j].getValue());
        }
    }
}

bool Game2048::operator==(const Game2048 &b)
{
    for (int i = 0 ; i < Game2048::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Game2048::C_BOARD_SIZE; ++j)
        {
            if (!(this->state[i][j] == b.state[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Game2048 &b)
{
    for (int i = 0 ; i < Game2048::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Game2048::C_BOARD_SIZE; ++j)
        {
            os << std::setw(4) << b.state[i][j] << " | ";
        }
        os << std:: endl;
    }
    return os;
}

void Game2048::moveLeft()
{
    for (int i = 0; i < Game2048::C_BOARD_SIZE; ++i)
    {
        bool change;

        do
        {
            change = false;
            for (int j = 0; j < Game2048::C_BOARD_SIZE-1; ++j)
            {
                change = change || Square::MoveOrMerge(state[i][j], state[i][j+1], true);
            }
        }
        while (change == true);
        

        for (int j = 0; j < Game2048::C_BOARD_SIZE-1; ++j)
        {
            Square::MoveOrMerge(state[i][j], state[i][j+1], false);
        }
    }
}

void Game2048::moveRight()
{
    for (int i = 0; i < Game2048::C_BOARD_SIZE; ++i)
    {
        bool change;

        do
        {
            change = false;
            for (int j = Game2048::C_BOARD_SIZE-1; j > 0; --j)
            {
                change = change || Square::MoveOrMerge(state[i][j], state[i][j-1], true);
            }
        }
        while (change == true);
        

        for (int j = Game2048::C_BOARD_SIZE-1; j > 0; --j)
        {
            Square::MoveOrMerge(state[i][j], state[i][j-1], false);
        }
    }
}
void Game2048::moveUp()
{
    for (int j = 0; j < Game2048::C_BOARD_SIZE; ++j)
    {
        bool change;

        do
        {
            change = false;
            for (int i = 0; i < Game2048::C_BOARD_SIZE-1; ++i)
            {
                change = change || Square::MoveOrMerge(state[i][j], state[i+1][j], true);
            }
        }
        while (change == true);
        
        for (int i = 0; i < Game2048::C_BOARD_SIZE-1; ++i)
        {
            Square::MoveOrMerge(state[i][j], state[i+1][j], false);
        }
    }
}
void Game2048::moveDown()
{
    for (int j = 0; j < Game2048::C_BOARD_SIZE; ++j)
    {
        bool change;

        do
        {
            change = false;
            for (int i = Game2048::C_BOARD_SIZE-1; i > 0; --i)
            {
                change = change || Square::MoveOrMerge(state[i][j], state[i-1][j], true);
            }
        }
        while (change == true);

        for (int i = Game2048::C_BOARD_SIZE-1; i > 0; --i)
        {
            Square::MoveOrMerge(state[i][j], state[i-1][j], false);
        }
    }
}

void Game2048::updateScore()
{
    unsigned int score = 0;

    for (int i = 0 ; i < Game2048::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Game2048::C_BOARD_SIZE; ++j)
        {
            score += state[i][j].getValue();
        }
    }

    this->score = score;
}

bool Game2048::updateGameOver()
{
    for (int i = 0 ; i < Game2048::C_BOARD_SIZE ; ++i)
    {
        for (int j = 0 ; j < Game2048::C_BOARD_SIZE; ++j)
        {
            if (state[i][j].isEmpty())
            {
                this->isGameOver = false;
                return this->isGameOver;
            }
        }
    }

    this->isGameOver = true;
    return this->isGameOver;
}

bool Game2048::move(const Action& action)
{
    // Întoarcem true dacă chiar s-a făcut o mutare, altfel false

    Game2048 bCopy{*this};

    switch (action)
    {
    case E_MOVE_LEFT:
        moveLeft();
        break;
    case E_MOVE_RIGHT:
        moveRight();
        break;
    case E_MOVE_UP:
        moveUp();
        break;
    case E_MOVE_DOWN:
        moveDown();
        break;
    default:
        return false;
    }

    if (bCopy == (*this))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Game2048::addRandomSquare()
{
    unsigned int i, j;

    do
    {
        i = rand() % Game2048::C_BOARD_SIZE;
        j = rand() % Game2048::C_BOARD_SIZE;
    } while (!state[i][j].isEmpty());
    
    bool isTwo = rand() % 2;

    if (isTwo)
    {
        state[i][j].setValue(2);
    }
    else
    {
        state[i][j].setValue(4);
    }
}

void Game2048::playGame(std::istream& is,
                     std::ostream& os,
                     const std::map<std::string, Action>& actionsMap)
{
    std::string actionStr;
    Action action;
    std::map<std::string, Action>::const_iterator it;

    while (!updateGameOver())
    {
        os << (*this);
        updateScore();
        os << "Scorul actual: " << score << std::endl;
        is >> actionStr;

        it = actionsMap.find(actionStr);

        if (it == actionsMap.end())
        {
            os << "Oprim jocul" << std::endl;
            return;
        }

        action = it->second;

        while (!move(action))
        {
            // Nimic de făcut aici
        }

        addRandomSquare();
    }

    os << "Game Over!" << std::endl;
}