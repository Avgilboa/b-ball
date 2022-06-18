#pragma once
#include "Team.hpp"
#include <chrono>

/**
 * @file Game.hpp
 * @author Aviad Gilboa
 * @brief The Game class will calculate with an probolity tools
 * The result about and return it.
 *
 * @copyright Copyright (c) 2022
 *
 */

class Game
{
private:
    Team& _Home;
    Team& _Out;

public:
    Game(Team &Home, Team &out);
    int add_bonus(double talent);
    int MakeHomeRes();
    int MakeAwayRes();
    void PrintRes(int homePoint, int awayPoint);
};
