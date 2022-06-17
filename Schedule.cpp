#include "Schedule.hpp"

Schedule::Schedule():Teams(20) ,NumRound(0), const_team(1){
    int count=1;
    for(unsigned int i=0; i<Teams.size();i++){Teams.at(i) =count++;}
}

std::map<int, int>& Schedule::GetRound(){
    if(NumRound>20){throw std::logic_error("The league is end");}
    Teams.OrderNextRound();
    this->NumRound++;
    return this->round;
}

