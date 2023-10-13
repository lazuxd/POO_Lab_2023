#pragma once
#include <iostream>
#include <map>

class Game
{
    public:

        virtual unsigned int getScore() const;

        bool getIsGameOver() const;
        
        void playGame(std::istream& is,
                      std::ostream& os);

    private:

        unsigned int score;
        bool isGameOver;
};