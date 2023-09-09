#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>

using namespace std;


class master{
    public:
    master(const string name, const int health, const int roll, const int initiativeModifier, const int armorClass){
        this -> name = name;
        this -> health = health;
        this -> roll = roll;
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
int getRoll() const{
    return roll;
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
    int roll;
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

void createCharacter(vector<master>& playerStatHolder){
    string name;
    int health;
    int roll;
    int initiativeModifier;
    int armorClass;
    string inputs;
    
    cout << endl << endl;
   
    cout << "Please enter player name" << endl;
    getline(cin, name);
    
    cout << "Please enter player health " << endl;
    cin >> health;
    
    cout << "rolling a d20 for the player " << endl;
    roll = basicD20Roll();
    
    cout << "Please enter the players intiative modifier" << endl;
    cin >> initiativeModifier;
    
    cout << "Please enter the players armorClass" << endl;
    cin >> armorClass;
    
    roll += initiativeModifier;
    
    playerStatHolder.push_back(master(name,health,roll,initiativeModifier, armorClass));
    
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
    //int diceRoll;
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

void combat(vector<master>& playerStatHolder){
    bool isInCombat = true;
    int playerSelect;
    int diceModifier;
    int health;
    
    while(isInCombat){
        cout << "You have begun combat please press d when done, or c to continue when prompted" << endl;
        
        for(int i = 0; i < playerStatHolder.size(); i++){
            cout << (i + 1) << ": " << playerStatHolder.at(i).getName() << endl;
        }
        
        cout << "Who is being attacked?" << endl;
        cin >> playerSelect;
        cout << "You have selected " << playerStatHolder.at(playerSelect - 1).getName() << " prepare for combat!" << endl;
        cout << "Armor class: " << playerStatHolder.at(playerSelect - 1).getArmorClass() << endl;
        cout << "Rolling a d20 for attack" << endl;
        int d_20 = basicD20Roll();
        cout << "Please enter in hit modifier here" << endl;
        cin >> diceModifier;
        d_20 += diceModifier;
        cout << "Total attack roll: " << d_20 << endl;
        
        if(d_20 > playerStatHolder.at(playerSelect - 1).getArmorClass()){
            cout << "You hit!" << endl;
            
            int newHealth = playerStatHolder.at(playerSelect - 1).getHealth() - diceRoll();
            playerStatHolder.at(playerSelect - 1).editHealth(newHealth);
        }
        
        if(d_20 <= playerStatHolder.at(playerSelect - 1).getArmorClass()){
            cout << "You missed! Aim better next time" << endl;
        }

        if(playerStatHolder.at(playerSelect - 1).getHealth() <= 0){
            
            cout << "Opponent slain" << endl;
        
        isInCombat = false;
        }
    }
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
      cout << "Name: " << playerStatHolder.at(i).getName() << endl;
      cout << "health: " << playerStatHolder.at(i).getHealth() << endl;
      cout << "roll w/ modifier: " << playerStatHolder.at(i).getRoll() << endl;
      cout << "Armor class: " << playerStatHolder.at(i).getArmorClass() << endl;
  }
 
 cout << "Would you like to begin combat? type y for yes" << endl;
 cin >> inputs;
 if(inputs == "y"){
     combat(playerStatHolder);
 }
    
    return  0;
}