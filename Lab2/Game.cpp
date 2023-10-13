#include "Game.hpp"

unsigned int Game::getScore() const
{
    return score;
}

bool Game::getIsGameOver() const
{
    return isGameOver;
}

void Game::playGame(std::istream& is,
              std::ostream& os)
{
    os << "Play Game";
}