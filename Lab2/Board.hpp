#pragma once
#include <iostream>
#include <map>
#include "Game.hpp"
#include "Square.hpp"

class Game2048 : public Game
{
    public:
        // Am făcut acest atribut 'static const' pentru că nu avem de gând să schimbăm
        // valoarea asta de la obiect la altul
        static const int C_BOARD_SIZE = 4;

        enum Action
        {
            E_MOVE_LEFT,
            E_MOVE_RIGHT,
            E_MOVE_UP,
            E_MOVE_DOWN
        };

        Game2048();
        Game2048(const Game2048& b); // Constructor de copiere

        bool operator==(const Game2048 &b);
        friend std::ostream& operator<<(std::ostream& os, const Game2048 &b);
        
        void playGame(std::istream& is,
                      std::ostream& os,
                      const std::map<std::string, Action>& actionsMap);
    
    private:
        Square state[C_BOARD_SIZE][C_BOARD_SIZE];
        unsigned int score;
        bool isGameOver;

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        bool move(const Action& action);

        void updateScore();
        bool updateGameOver();

        void addRandomSquare();
};