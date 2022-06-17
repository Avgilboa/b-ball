#include "Leauge.hpp"
std::string pickName();
double pickTalent();


League::League() {

    this->_Teams.clear();
    this->_start = false;
}

League& League::AddTeam(const Team & T){
    if(checkAvialbleName(T.GetName())){
        this->_Teams.push_back(T);
        return *this;
    }
    
    throw std::runtime_error("this  name already exist");
}

League& League::AddTeam(std::string name , double talent){
    if(checkAvialbleName(name)){
        this->_Teams.push_back(Team(name, talent));
        return *this;
    }
    throw std::runtime_error("this name already exist");
}

bool League::StartLeague(){
    this->_start = FillTeams();
    return this->_start;
}

bool League::FillTeams(){
    
    for(unsigned int i= this->_Teams.size();i<20;i++){
        std::string name = pickName();
        double talent = pickTalent();
        try
        {
            checkAvialbleName(name);
            AddTeam(Team(name,talent, true));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        

    }
    return true;
}

std::string pickName(){
    std::vector<std::string> names {"Banana", "Melon", "Monkey", "Avatar", "Turtele", "Car"
    ,"Hammer", "Tank", "Prize", "Bird","TV", "Cat", "Fish", "Loop", "Horse" , "Butter", "Wine", "Pasta", "Pig", "bull"};
    
    std::vector<std::string> vibes{"satlan","positive","harsh","screaming","bomb","Amazing","ungreatful","777","55","sticky"
    ,"Angry", "desperate", "01", "Happy", "sitting", "standing", "winner","lazy", "hungry", "loving" };

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.1,0.998);
    std::uniform_int_distribution<int> in(0,19);
    int index1 = in(mt);
    int index2 = in(mt);
    std::string name = vibes.at((unsigned long) index2) + " "+ names.at((unsigned long) index1);

    return name;
}

double pickTalent(){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0.1,0.998);
        double talent =dist(mt);
        return talent;
}
bool League::checkAvialbleName(const std::string & name) const{
    for(Team T : this->_Teams){
        if(T.GetName()==name){
            return false;
        }
    }
    return true;
}

void League::printTeams() const{ 
    for(Team T : this->_Teams){
        T.print();
    }
}


void League::PlayRound(){
    std::map<int,int> round = this->schedule.GetRound();
    for (auto &[first, second] : round)
    {
        Game(this->_Teams.at((unsigned long) first-1), this->_Teams.at( (unsigned long) second-1));
    }
}