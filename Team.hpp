#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <map>
#include <iomanip>
#include <random>
#include <cmath>
#include <algorithm>
/**
 * @file Team.hpp
 * @author Aviad Gilboa
 * @brief This class save all the definitions about each team
 *
 */

struct statistics
{
    unsigned int _numOfGame;
    int _BalancePoints;
    unsigned int _numOfWin;
    unsigned int _numOfLose;
};
class Team
{
private:
    std::string _name;
    unsigned int _index;
    double _talent;
    bool _bot; // This means if the team generate by the player or by the computer.
    statistics _statistics;

public:
    Team() = default;
    ~Team() = default;
    Team(const std::string name, double talent,uint index, bool bot = false);
    void updateStatistics(int BalancePoints, bool IsWinner);
    void print();
    std::string GetName() const;
    double GetTalnt() const;
    statistics &GetStatistic();
};
