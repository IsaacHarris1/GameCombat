#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>

using namespace std;


class master{
    public:
    master(const string name, const int health, const int initiativeModifier, const int armorClass){
        this -> name = name;
        this -> health = health;
        this -> initiativeModifier = initiativeModifier;
        this -> armorClass = armorClass;
    }
void editHealth(int newHealth){
    health = newHealth;
}
string getName() const{
    return name;
    }
int getHealth() const{
    return health;
    }
int getInitiativeModifier() const{
    return initiativeModifier;
}
int getArmorClass() const{
    return armorClass;
}
    private:
    string name;
    int health;
    int initiativeModifier;
    int armorClass;
};

int basicD20Roll(){
    int d_20 = 0;
    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> dist(1, 20);
    d_20 = dist(rng);
    return d_20;
    
}

//bool isAlive()
//edited for team creation and storing
void createCharacter(vector<master>& playerStatHolder){
    string name;
    int health;
    int roll;
    int initiativeModifier;
    int armorClass;
    string inputs;
    
    cout << endl << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please enter player name" << endl;
    getline(cin, name);
    
    cout << "Please enter player health " << endl;
    cin >> health;
    
   // cout << "rolling a d20 for the player " << endl;
    //roll = basicD20Roll();
    
    cout << "Please enter the players intiative modifier" << endl;
    cin >> initiativeModifier;
    
    cout << "Please enter the players armorClass" << endl;
    cin >> armorClass;
    
    //roll += initiativeModifier;
    
    playerStatHolder.push_back(master(name,health,initiativeModifier,armorClass));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "if you are done please press d, or press c to add more players!" << endl;
}

int main(){
  int choiceT = 0;
  int choice = 0;
  string choiceTstring;
  string choiceString;
  string inputs = "a";
  vector<master> playerStatHolder;
  vector<int> initiativeHolder;
  
cout << "Hello user, here are your options for the menu" << endl;
cout << "1: Begin/Edit the players" << endl;

cin >> choice;

while(atoi(choiceString.c_str()) == 0){
    cin >> choiceString;

choice = atoi(choiceString.c_str());
    if(choice == 0){
        cout << " That is not an option please try again." << endl;
        cin >> choiceString;
    }
}
  if(choice == 1){
  
cout << "Enter in player info, press d when prompted if done" << endl;
  while(true){
   createCharacter(playerStatHolder);   
   cin >> inputs;

  if(inputs == "d"){
      break;
    }
  if(inputs == "c"){
       continue;
  }
}
}
if(inputs == "d"){
  
  for(int i = 0; i < playerStatHolder.size(); i++){
      cout << '\n';
      cout << "Name: " << playerStatHolder.at(i).getName() << endl;
      cout << "health: " << playerStatHolder.at(i).getHealth() << endl;
      cout << "modifier: " << playerStatHolder.at(i).getInitiativeModifier() << endl;
      cout << "Armor class: " << playerStatHolder.at(i).getArmorClass() << endl;
  }
}

 return 0;
 
}