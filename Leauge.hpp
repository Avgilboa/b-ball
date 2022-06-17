#pragma once
#include "Game.hpp"
#include "Schedule.hpp"

/**
 * @file Leauge.hpp
 * @author Aviad Gilboa
 * @brief saving all the teams (Team class) playing in the league
 * and all the parameters about each team.
 * All league has 20 Teams.
 *
 */
class Schedule;
<<<<<<< HEAD
class League{
    private:
        std::vector<Team> _Teams;
        bool _start;
    public:
        League();
        League& AddTeam(const Team&  T);
        League& AddTeam(std::string name , double talent);
        bool StartLeague();
        bool checkAvialbleName(const std::string & name) const;
        void printTeams() const;
        bool FillTeams();
        Schedule* schedule;
        std::vector<int> Game(double Home_Talent , double Away_Talent);
};  
=======
class Schedule;

class League
{
private:
    std::vector<Team> _Teams;
    bool _start;

public:
    League();
    League &AddTeam(const Team &T);
    League &AddTeam(std::string name, double talent);
    bool StartLeague();
    bool checkAvialbleName(const std::string &name) const;
    void printTeams() const;
    bool FillTeams();
    Schedule* schedule;
    std::vector<int> Game(double Home_Talent, double Away_Talent);
};
>>>>>>> cb3698704121668aa182a924ebef30961964b9ac
