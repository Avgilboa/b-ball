#pragma once
#include <algorithm>
#include <deque>
#include <map>
#include <vector>
#include <iostream>
/**
 * @file Schedule.hpp
 * @author Aviad Gilboa
 * @brief This File will save the orders of the games and save
 * a table of all the statistics about each team.
 * it will help us to orgenized the rank of each team.
 *
 */

class Schedule
{
private:
    int NumRound;
    int const_team;
    std::vector<int> Teams;
    //// number of round ---> Home team, Away Team
    std::map<int, int> round;

public:
    Schedule();
    std::map<int, int> &GetRound();
    void OrderNextRound();
};
