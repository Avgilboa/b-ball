#include "Schedule.hpp"

Schedule::Schedule() : NumRound(0), const_team(1)
{
    for (int i = 0; i < 20; i++)
    {
        Teams.push_back(i);
    }
}

std::map<int, int> &Schedule::GetRound()
{
    if (NumRound > 20)
    {
        throw std::logic_error("The league is end");
    }
    this->NumRound++;
    this->OrderNextRound();
    return this->round;
}

void Schedule::OrderNextRound()
{
    std::rotate(Teams.begin() + 1, Teams.begin() + NumRound + 1, Teams.end());
    if (NumRound < 11)
    {
        for (int i = 0; i < 10; i++)
        {
            this->round[i] = Teams.at((unsigned long)i + 10);
        }
    }
    if (NumRound >= 11)
    {
        for (int i = 0; i < 10; i++)
        {
            this->round[i + 10] = Teams.at((unsigned long)i);
        }
    }
}
