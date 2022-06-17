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
 * @brief Demo program for LEAGUE exercise.
 *  @author DOLEV DUBLON
 * @since 01/07/2022
 *
 * here i am checking that it doesnt throw an exception
 */

TEST_CASE("TEAM test check no throw")
{
    CHECK(1 == 1);
    Game g;
    CHECK_NOTHROW(g = Game());
    Team t;
    CHECK_NOTHROW(t = Team());
    Schedule s;
    CHECK_NOTHROW(s = Schedule());
    League l;
    CHECK_NOTHROW(l = League());
}

TEST_CASE("TEST the score")
{

    Game g;
    Team t;
    Schedule s;
    League l;
    // for (int i = 0; i < 50; i++)
    // {
    //     /* code */

    //     CHECK_NOTHROW(g = Game());
    //     CHECK_NOTHROW(t = Team());
    //     CHECK_NOTHROW(s = Schedule());
    //     CHECK_NOTHROW(l = Leauge());
    //     CHECK(g.getScore() == 0);
    //     CHECK(t.getScore() == 0);
    //     CHECK(s.getScore() == 0);
    //     CHECK(l.getScore() == 0);
    //     g.setScore(1);
    //     t.setScore(2);
    //     s.setScore(3);
    //     l.setScore(4);
    //     CHECK(g.getScore() == 1);
    //     CHECK(t.getScore() == 2);
    //     CHECK(s.getScore() == 3);
    //     CHECK(l.getScore() == 4);
    // }
}