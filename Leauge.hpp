#pragma once
#include "Game.hpp"
#include "Schedule.hpp"
class Schedule;
class Game;
/**
 * @file Leauge.hpp
 * @author Aviad Gilboa
 * @brief saving all the teams (Team class) playing in the league
 * and all the parameters about each team.
 * All league has 20 Teams.
 *
 */

class League{
    private:
        std::vector<Team> _Teams;
        bool _start;
        Schedule schedule;
    public:
        League();
        League& AddTeam(const Team&  T);
        League& AddTeam(std::string name , double talent);
        bool StartLeague();
        bool checkAvialbleName(const std::string & name) const;
        void printTeams() const;
        bool FillTeams();
        void PlayRound();
};  
