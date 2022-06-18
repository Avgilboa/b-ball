#include "doctest.h"
#include "Game.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
#include "Leauge.hpp"

/**
 * @brief Demo program for TEAM exercise.
 *  @author DOLEV DUBLON
 *
 */

/**
 *  @author Aviad gilboa
 *
 * 
 */

TEST_CASE("legue have 20 teams")
{
    /* 
    5 diffrent league we will check:
        1. (a+b) all the team make by the bot
        2. c - all the teams by the user
        3. (d+e) league that have teams for the bot and teams by the user
        */
    League a,b,c,d,e;
    a.StartLeague();
    b.StartLeague();
    c.AddTeam("a",0.5).AddTeam("b",0.5).AddTeam("c",0.5).AddTeam("d",0.5).AddTeam("e",0.5).AddTeam("f",0.5).AddTeam("g",0.5)
    .AddTeam("h",0.5).AddTeam("i",0.5).AddTeam("j",0.5).AddTeam("k",0.5).AddTeam("m",0.5).AddTeam("n",0.5).AddTeam("l",0.5)
    .AddTeam("o",0.5).AddTeam("p",0.5).AddTeam("q",0.5).AddTeam("r",0.5).AddTeam("s",0.5).AddTeam("t",0.5);
    CHECK_THROWS(c.AddTeam("banana", 0.6));
    c.StartLeague();
    d.AddTeam("a",0.5);
    CHECK_NOTHROW(d.AddTeam("a",0.5));
    d.StartLeague();
    e.StartLeague();
    CHECK(a.size()==20);
    CHECK(b.size()==20);
    CHECK(c.size()==20);
    CHECK(d.size()==20);
    CHECK(e.size()==20);
}
TEST_CASE("The league point is between 50 to 100"){

    Team b("b",0.2,1);
    Team a("a",0.7,0);
    for (int i=0; i<20;i++){
        CHECK_NOTHROW(Game(a,b));
        CHECK(a.GetStatistic()._numOfGame==i+1);
        CHECK(b.GetStatistic()._numOfGame==i+1);
    }
}