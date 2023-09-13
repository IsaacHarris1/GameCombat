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

int inputValidation(){
    int input;
    while(true){
        if(cin >> input){
            break;
        }
        cout << "Invalid input try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

char inputCharValidation(){
    char inputChar;
    while(true){
        if(cin >> inputChar){
            break;
        }
        cout << "Not a character try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return inputChar;
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
    health = inputValidation();
    
    cout << "Please enter the players intiative modifier" << endl;
    initiativeModifier = inputValidation();
    
    cout << "Please enter the players armorClass" << endl;
    armorClass = inputValidation();
    
    playerStatHolder.push_back(master(name,health,initiativeModifier,armorClass));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "if you are done please press d, or press c to add more players!" << endl;
}

int main(){
  int selection = 0;
  string inputs = "a";
  vector<master> playerStatHolder;
  vector<int> initiativeHolder;
  

while(true){
    cout << "Hello user, here are your options for the menu, select from the options below" << endl;
    cout << "1: Begin/Edit the party" << endl;
    cout << "2: Display the party" << endl;
    cout << "5: Terminate program" << endl;

   int selection = inputValidation();
    
    
    
    
     if(selection == 1){
        bool editingParty = true;
        
        while(editingParty){
           cout << "Enter in player info, press d when prompted if done" << endl;
           createCharacter(playerStatHolder);   
        
              if(inputCharValidation() == 'd'){
                  cout << "done! \n";
                  editingParty = false;
                }
                
              else if(inputCharValidation() == 'c'){
                   continue;
                }
            }
        }
        
    else if(selection == 2){
      
      if(playerStatHolder.size() == 0){
          cout << "The party is currently empty, please press 1 to add" << endl;
          cout << "\n \n \n \n \n";
      }
      else{
          for(int i = 0; i < playerStatHolder.size(); i++){
              cout << '\n';
              cout << "Name: " << playerStatHolder.at(i).getName() << endl;
              cout << "health: " << playerStatHolder.at(i).getHealth() << endl;
              cout << "modifier: " << playerStatHolder.at(i).getInitiativeModifier() << endl;
              cout << "Armor class: " << playerStatHolder.at(i).getArmorClass() << endl;
              cout << "\n \n \n \n \n";
          }
        }
    }
    
    else if(selection == 5){
            cout << "Program terminated" << endl;
            break;
        }

}


 return 0;
 
}