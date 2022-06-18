#include "Game.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;
int main()
{
    League league;
    league.AddTeam("dolev_Team", 0.5);
    league.AddTeam("yakov_Team", 0.6);
    league.AddTeam("daniel_Team", 0.7);
    league.AddTeam("aviad_Team", 0.8);
    league.StartLeague();
    league.playLeague();
    league.printTeams();

    return 0;
}

/* 
  */

/*
Saves for testing:
    Team T("Aviad",0.9);
    League L,a,s,d,f;
    L.AddTeam(T).AddTeam("Aviada", 0.6);
    s.StartLeague();
    a.StartLeague();
    d.StartLeague();
    f.StartLeague();
    L.StartLeague();
    L.printTeams();

    */