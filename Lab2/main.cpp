#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.hpp"
#include "Chess.hpp"

int main()
{
    srand(time(0));

    Game2048 g1;

    std::cout << "Scorul lui g1: " << g1.getScore() << std::endl;

    Chess c;
    std::cout << "Scorul lui c: " << c.getScore() << std::endl;

    Game2048 bPlay;

    std::map<std::string, Game2048::Action> actionsMap;
    actionsMap.insert(std::pair<std::string, Game2048::Action>("w", Game2048::E_MOVE_UP));
    actionsMap.insert(std::pair<std::string, Game2048::Action>("s", Game2048::E_MOVE_DOWN));
    actionsMap.insert(std::pair<std::string, Game2048::Action>("a", Game2048::E_MOVE_LEFT));
    actionsMap.insert(std::pair<std::string, Game2048::Action>("d", Game2048::E_MOVE_RIGHT));

    bPlay.playGame(std::cin, std::cout, actionsMap);

    return 0;
}