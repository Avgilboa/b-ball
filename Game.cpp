#include "Game.hpp"

Game::Game(Team &Home, Team &out) : _Home(Home), _Out(out)
{
    int away = MakeAwayRes() + add_bonus(_Out.GetTalnt());
    int home = MakeHomeRes() + add_bonus(Home.GetTalnt());
    if (home == away)
    {
        if (_Home.GetTalnt() + 0.1 - _Out.GetTalnt() >= 0)
        {
            home += 5;
        }
        else
        {
            away += 5;
        }
    }
    _Home.updateStatistics(home - away, home > away);
    _Out.updateStatistics(away - home, home < away);
}

int Game::add_bonus(double talent)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::normal_distribution<> bonus{75, 11};
    int point = bonus(e) * talent;
    point %= 10;
    return point;
}

int Game::MakeAwayRes()
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> res{75, 11};
    int away = res(e);
    if (away > 100)
    {
        away = 100;
    }
    if (away < 50)
    {
        away = 50;
    }

    return away;
}

int Game::MakeHomeRes()
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> res{75, 11};
    int home = res(e);
    if (home > 100)
    {
        home = 100;
    }
    if (home < 55)
    {
        home = 55;
    }

    return home;
}

void Game::PrintRes(int homePoint, int awayPoint)
{
    std::cout << "*****************************************\n"
              << "         This Game is between             \n"
              << " Home Team " << _Home.GetName() << "  Away Team " << _Out.GetName() << " \n"
              << " The result is " << _Home.GetName() << " = " << homePoint << "   " << _Out.GetName() << " = " << awayPoint << std::endl;
}
