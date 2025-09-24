// AX Pokemon Battle Program

/*

INSTRUCTIONS:
Write a program that creates a Pokémon battle game using structures for Pokémon and enumeration for the menu in C++. The game should allow users to explore (find Pokémon), battle, heal Pokémon, and exit the game. Implement structures for Pokémon that include names, max HP, attacks, and level. Use enumeration for the main menu options.

The game must include the following features:

A main menu with options to explore, battle, heal, and exit.
Exploration feature to find and catch Pokémon.
Battle system where users can fight against wild Pokémon or other trainers.
Healing option to restore Pokémon HP.
Multiple attack options for each Pokémon during battles.
Different Pokémon types with associated weaknesses and strengths.
Type-based damage bonuses during battles.
OUTPUT EXAMPLE:

Pokémon Battle Game Menu:

Explore
Battle
Heal Pokémon
Exit
Enter your choice (1-4): 1

You found a wild Pikachu! Do you want to catch it? (Y/N): Y

Pikachu has been added to your team!

CLARIFICATIONS:

You should have 5 different Pokemon types.
Each type needs at least 1 -2 Pokemon in it. 
Pokemon should have at least 3 attacks to choose from.



*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
 // Enumeration for pokemon types
enum Type{
    Fire,
    Water,
    Grass,
    Electric, // electric beats air and water
    Air // beats fire

};

 // Enumeration for the menu
enum Menu{
    Explore = 1,
    Battle,
    Heal,
    Exit
};

// Each pokemon and how much damage
struct Attack{
    string name;
    int damage;

};

// Each pokemons stats
struct Pokemon{
    string name;
    Type type;
    int maxHP;
    int currentHP;
    int level;
    vector<Attack> attacks;
    
    void heal(){
        currentHP = maxHP;
        cout << name << "healed!" << endl;
    };
    

};
// holds their name, type, max HP, current HP, level, and attacks(name, how much damage)
vector<Pokemon> wild_pokemons = {
    {"Charmander", Fire, 50, 50, 1, {{"Flame Burst", 15}, {"Ember", 10}, {"Fire Spin", 12}}},
    {"Squirtle", Water, 55, 55, 1, {{"Water Gun", 12}, {"Bubble", 10}, {"Aqua Tail", 14}}},
    {"Bulbasaur", Grass, 60, 60, 1, {{"Vine Whip", 10}, {"Razor Leaf", 12}, {"Seed Bomb", 14}}},
    {"Pikachu", Electric, 45, 45, 1, {{"Thunder Shock", 15}, {"Spark", 12}, {"Electro Ball", 18}}},
    {"Pidgey", Air, 40, 40, 1, {{"Gust", 10}, {"Air Slash", 12}, {"Feather Dance", 8}}}
};

// make a new vector to hold all of the pokemons the users have
vector<Pokemon> user_pokemons;

void explore(){
    // picks a random Pokémon from the wild pokemons list
    int index = rand() % wild_pokemons.size();
    Pokemon found = wild_pokemons[index];

    cout << "You found a wild " << found.name << "! Do you want to ctach it? (Y/N): ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y'){
        // Puts the wild Pokémon into their Pokémon
        user_pokemons.push_back(found);
        cout << found.name << "has been added to your team! " << endl;
    } else{
        cout << "You let " << found.name << " go." << endl;
    }
    
};

// Lets you pick which Pokémon you want to battle each other(they keep battling until one Pokémon runs out of health)
void battle(){
    // Makes sure you have a pokemon to fight
    if (user_pokemons.empty()){
        cout << "You have no Pokémon to battle with!" << endl;
        return;
    }

    // Randomly picks a Pokémon for you to battle
    int WildIndex = rand() % wild_pokemons.size();
    Pokemon enemy = wild_pokemons[WildIndex];

    //Lets the user pick which Pokémon of theirs they want to fight
    cout << "Choose your Pokémon: " << endl;
    for (int i = 0; i < user_pokemons.size(); i++){
        cout  <<  i + 1 << "-" << user_pokemons[i].name << "(HP: " << user_pokemons[i].currentHP << " Level: " << user_pokemons[i].level << " )" << endl;
    }
    int choice;
    cin >> choice;
    Pokemon& player = user_pokemons[choice - 1];

    // starts the battle
    // keeps playing until one of the Pokémon runs out of HP
    while (player.currentHP > 0 && enemy.currentHP > 0) {
        ////////////////////////////////////////////////////////////////////This is where I left off
        cout << "\nChoose an attack:" << endl;
        for (int i = 0; i < player.attacks.size(); ++i) {
            cout << i + 1 << ". " << player.attacks[i].name << " (Damage: " << player.attacks[i].damage << ")" << endl;
        }
        int attackChoice;
        cin >> attackChoice;
        int damage = player.attacks[attackChoice - 1].damage;
        enemy.currentHP -= damage;

        if (enemy.currentHP <= 0) {
            cout << "You defeated " << enemy.name << "!" << endl;
            break;
        }

        int enemyAttackIndex = rand() % enemy.attacks.size();
        int enemyDamage = enemy.attacks[enemyAttackIndex].damage;
        player.currentHP -= enemyDamage;

        if (player.currentHP <= 0) {
            cout << player.name << " fainted!" << endl;
        }




    
    
    };


};

void healing(){
    //If the user doesn't have any Pokémon to heal
    if(user_pokemons.empty()){
        cout << "You have no Pokémon to heal!" << endl;
        return;
    }

    // Loops through all of the Pokémon the user has and heals them all
    for (auto& p: user_pokemons){
        p.heal();
    }
    
};


int main(){
    srand(time(0)); // so I can use random
    int input;
    cout << "Welcome to Your Calculator!" << endl;

    // Keeps running until they exit
    while(true){
        cout <<
        "\n\nPokémon Battle Game Menu:"
        "\n1. Explore" << endl <<
        "2. Battle" << endl <<
        "3. Heal Pokémon" << endl <<
        "4. Exit" << endl <<
        "Enter your choice(1-4): ";

        while(!(cin >> input)){
            cout << "Please enter a number option" << endl;
            cin.clear();
            cin.ignore();
        }
    
        if (input == Menu::Explore){
            explore();
        }else if(input == Menu::Battle){
            battle();
        }else if(input == Menu::Heal){
            healing();
        }else if(input == Menu::Exit){
            cout << "Thank you for playing Pokémon!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }

    return 0;
}