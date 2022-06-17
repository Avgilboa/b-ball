#include "Schedule.hpp"

Schedule::Schedule():Teams(20) ,NumRound(0), const_team(1){
    for(unsigned int i=0; i<Teams.size();i++){Teams.at(i) = i+1;}
}

std::map<int, int>& Schedule::GetRound(){
    if(NumRound>20){throw std::logic_error("The league is end");}
    this->NumRound++;
    this->OrderNextRound();
    return this->round;
}

void Schedule::OrderNextRound(){
    std::rotate(Teams.begin()+1,Teams.begin()+NumRound+1,Teams.end());
    if(NumRound<11){
        for (int i=0; i<10;i++){
            this->round[i] = Teams.at(i+10);
        }
    }
      if(NumRound>=11){
        for (int i=0; i<10;i++){
            this->round[i+10] = Teams.at(i);
        }
    }
}

