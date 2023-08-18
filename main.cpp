#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


class master{
    public:
    master(const string name, const int health, const int roll, const int initiativeModifier){
        this -> name = name;
        this -> health = health;
        this -> roll = roll;
        this -> initiativeModifier = initiativeModifier;
    }
string getname() const{
    return name;
    }
int getHealth() const{
    return health;
    }
int getRoll() const{
    return roll;
    }
int getInitiativeModifier() const{
    return initiativeModifier;
}
    private:
    string name;
    int health;
    int roll;
    int initiativeModifier;
};

void createCharacter(vector<master>& playerStatHolder){
    string name;
    int health;
    int roll;
    int initiativeModifier;
    string inputs;
    
    cout << endl << endl;
   
    cout << "Please enter player name" << endl;
    getline(cin, name);
    
    cout << "Please enter player health " << endl;
    cin >> health;
    
    cout << "Please enter the players initiative roll(before modifers) " << endl;
    cin >> roll;
    
    cout << "Please enter the players intiative modifier" << endl;
    cin >> initiativeModifier;
    
    roll = roll + initiativeModifier;
    
    playerStatHolder.push_back(master(name,health,roll,initiativeModifier));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "if you are done please press d, or press c to add more players!" << endl;
}

void combat(vector<master>& playerStatHolder){
    cout << "You have begun combat please press d when done, or c to continue when prompted" << endl;
}



int main(){
  string inputs = "a";
  vector<master> playerStatHolder;
  vector<int> initiativeHolder;
  int roll;
  
cout << "Enter in player info, press d when prompted if done" << endl;
  while(true){
   createCharacter(playerStatHolder);   
   cin >> inputs;

  if(inputs == "d"){
      break;
    }
  if(inputs == "c"){
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       continue;
  }
}
  
  sort(playerStatHolder.begin(),playerStatHolder.end(),
    [](const master& a, const master& b){
        return a.getRoll() > b.getRoll();
    });
  
  for(int i = 0; i < playerStatHolder.size(); i++){
      cout << '\n';
      cout << "Name: " << playerStatHolder.at(i).getname() << endl;
      cout << "health: " << playerStatHolder.at(i).getHealth() << endl;
      cout << "roll w/ modifier: " << playerStatHolder.at(i).getRoll() << endl << endl;
  }
 
 cout << "Would you like to begin combat? type y for yes" << endl;
 cin >> inputs;
 if(inputs == "y"){
     combat(playerStatHolder);
 }
    
    return  0;
}