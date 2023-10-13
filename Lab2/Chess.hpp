#pragma once
#include "Game.hpp"

class Chess : public Game
{
    public:
        virtual unsigned int getScore() const;
};