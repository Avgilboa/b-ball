#include "Team.hpp"
Team::Team(const std::string name, double talent,uint index, bool bot)
{
    if (talent >= 1 || talent <= 0)
    {
        throw std::runtime_error("The talent parameter needs to be between 0 to 1");
    }
    this->_name = name;
    this->_talent = talent;
    this->_bot = bot;
    this->_index = index;

    this->_statistics._numOfGame = 0;
    this->_statistics._BalancePoints = 0;
    this->_statistics._numOfWin = 0;
    this->_statistics._numOfLose = 0;
}

void Team::updateStatistics(int BalancePoints, bool IsWinner)
{
    this->_statistics._numOfGame+=1;;
    this->_statistics._BalancePoints += BalancePoints;
    if (IsWinner)
    {
        this->_statistics._numOfWin++;
    }
    if(!IsWinner)
    {
        this->_statistics._numOfLose++;
    }
}

void Team::print()
{
    std::cout << "********************************************************\n";
    std::cout << "Team name                 :   " << this->_name << "\n";
    std::cout << "current talent of the Team:   " << this->_talent << "\n";
    std::cout << "Index Team                :   " << this->_index+1 << "\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "________________________statistics____________________\n";
    std::cout << "Total game played         :   " << this->_statistics._numOfGame << "\n";
    std::cout << "Number of winnig game     :   " << this->_statistics._numOfWin << "\n";
    std::cout << "Number of losing game     :   " << this->_statistics._numOfLose << "\n";
    std::cout << "Balance points            :   " << this->_statistics._BalancePoints << "\n";
    std::cout << "********************************************************\n";
    std::cout << std::endl
              << std::endl;
}

std::string Team::GetName() const
{
    return this->_name;
}

double Team::GetTalnt() const
{
    return this->_talent;
}

statistics &Team::GetStatistic()
{
    return this->_statistics;
}