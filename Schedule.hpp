#pragma once

#include "Leauge.hpp"
/**
 * @file Schedule.hpp
 * @author Aviad Gilboa
 * @brief This File will save the orders of the games and save
 * a table of all the statistics about each team.
 * it will help us to orgenized the rank of each team.
 * 
 */

class Schedule{
    private:
        std::map<unsigned int, std::map<unsigned int, unsigned int>> season;
        //// number of round ---> Home team, Away Team
    public:
        Schedule();
        
        void orgenizeSeason(unsigned int numberTeams);
};
