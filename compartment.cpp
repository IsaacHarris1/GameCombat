#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

void clearScreen(){
    system("clear");
}

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

class Enemies : public master {
public:
    Enemies(const string name, int health,const int armorClass, const int initiativeModifier, const int initiativeHolder)
        : master(name,health,initiativeModifier,armorClass){
            this->initiativeHolder = initiativeHolder;
        }
    int getInitiativeHolder() const {
        return initiativeHolder;
    }
    
private:
    int initiativeHolder;    
        
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
void createEnemies(vector<Enemies>& enemyStatHolder){
    string name;
    int health;
    int roll;
    int initiativeModifier;
    int initiativeHolder;
    int armorClass;
    string inputs;
    
    cout << endl << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please enter enemy name" << endl;
    getline(cin, name);
    
    cout << "Please enter enemy health " << endl;
    health = inputValidation();
    
    cout << "Please enter the enemy intiative modifier" << endl;
    initiativeModifier = inputValidation();
    
    
    
    initiativeHolder = basicD20Roll() + initiativeModifier;
    
    cout << "Please enter the enemy armorClass" << endl;
    armorClass = inputValidation();
    
    enemyStatHolder.push_back(Enemies(name,health,armorClass,initiativeModifier,initiativeHolder));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "if you are done please press d, or press c to add more foes!" << endl;
}


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

int rollHelper(int amountRoll, mt19937& rng, uniform_int_distribution<int>& dist){
    int rollTotal = 0;
    int diceRoll = 0;
    for(int i = 0; i < amountRoll; i++){
        diceRoll = dist(rng);
        rollTotal += diceRoll;
        cout << "total roll: " << rollTotal << endl;
    }
    return rollTotal;
}

int diceRoll() {
    mt19937 rng(time(nullptr));
    string diceChoice;
    int diceConvert;
    int amountRoll;
    int rollTotal = 0;
    cout << "what type of dice would you like me to roll? ex(d4)" << endl;
    cin >> diceChoice;
    
    diceConvert = stoi(diceChoice.substr(1));
    
    uniform_int_distribution<int> dist(1, diceConvert);
    while (true){
        diceConvert = stoi(diceChoice.substr(1));
        switch(diceConvert){
            case 4:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
           
            case 6:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
            
            case 8:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
            
            case 10:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
            
            case 12:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
            
            case 20:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
            
            case 100:
            cout << "How many times shall I roll?" << endl;
            cin >> amountRoll;
            rollTotal = rollHelper(amountRoll, rng, dist);
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
            
            default:
            cout << "Invalid dice, please try again" << endl;
            cin >> diceChoice;
            continue;
            
        }
        break;
    }
    return rollTotal;
}

int main(){
  int selection = 0;
  string inputs = "a";
  vector<master> playerStatHolder;
  vector<Enemies> enemyStatHolder;
  vector<int> initiativeHolder;
  

while(true){
    cout << "Hello user, here are your options for the menu, select from the options below" << endl;
    cout << "1: Begin/Edit the party" << endl;
    cout << "2: Display the party" << endl;
    cout << "3: Begin/edit enemies" << endl;
    cout << "4: Display the enemies" << endl;
    cout << "5: Begin combat" << endl;
    cout << "6: Terminate program" << endl;

   int selection = inputValidation();
    
    
    
    
     if(selection == 1){
        bool editingParty = true;
        
        while(editingParty){
           cout << "Enter in player info, press d when prompted if done" << endl;
           createCharacter(playerStatHolder);   
        char userInput = inputCharValidation();
              if(userInput == 'd'){
                  cout << "done! \n";
                  editingParty = false;
                }
              else if(userInput == 'c'){
                   continue;
                }
            }
        }
        
    else if(selection == 2){
      
      if(playerStatHolder.size() == 0){
         // clearScreen();
          cout << "The party is currently empty, please press 1 to add" << endl;
          
      }
      else{
          for(int i = 0; i < playerStatHolder.size(); i++){
              cout << '\n';
              cout << "Name: " << playerStatHolder.at(i).getName() << endl;
              cout << "health: " << playerStatHolder.at(i).getHealth() << endl;
              cout << "modifier: " << playerStatHolder.at(i).getInitiativeModifier() << endl;
              cout << "Armor class: " << playerStatHolder.at(i).getArmorClass() << endl;
              cout << "\n";
          }
        }
    }
    
    else if(selection == 3){
        bool editingEnemies = true;
        if(enemyStatHolder.size() == 0){
          //  clearScreen();
            cout << "There are no enemies in this list, beginning list" << endl;
            
        }
        while(editingEnemies){
            cout << "Enter in enemy info, press d when prompted if done" << endl;
            createEnemies(enemyStatHolder);
        char userInput = inputCharValidation();
            if(userInput == 'd'){
                cout << "done! \n";
                editingEnemies = false;
            }
            else if(userInput == 'c'){
                continue;
            }
        }
        
    }
    
    else if(selection == 4){
        if(enemyStatHolder.size() == 0){
            //clearScreen();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "There are no enemies in this list" << endl;
        }
        else if(enemyStatHolder.size() > 0){
            for(int i = 0; i < enemyStatHolder.size(); i++){
                cout << "\n";
                cout << "Name: " << enemyStatHolder.at(i).getName() << endl;
                cout << "Health: " << enemyStatHolder.at(i).getHealth() << endl;
                cout << "Initiative: " << enemyStatHolder.at(i).getInitiativeHolder() << endl;
                cout << "Armor class: " << enemyStatHolder.at(i).getArmorClass() << endl << endl;
            }
        }
    }
    
    
    else if(selection == 5){
            cout << "combat selected" << endl;
            //combad code here
    }
    
    else if(selection == 6){
            cout << "Program terminated" << endl;
            break;
        }

}


 return 0;
 
}