// AX Pokemon Battle Program
// Took a long time and a lot of help from copilot to know what to code and understand it

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
        cout << name << " healed!" << endl;
    };

    // This checks to see if the pokemon is already in the user's team so all of them are unique inside it
    bool operator==(const Pokemon& other) const {
        return name == other.name && type == other.type && level == other.level;
    }
    

};

// Converts Type enum to readable string(used Copilot)
string getTypeName(Type type) {
    switch (type) {
        case Fire: return "Fire";
        case Water: return "Water";
        case Grass: return "Grass";
        case Electric: return "Electric";
        case Air: return "Air";
        default: return "Unknown";
    }
}


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

// This shows each of the pokemon strengths and weaknesses
float getTypeMultiplier(Type attacker, Type defender){
    // These are the different attacks and what it will return in each circumstance
    if (attacker == Electric && (defender == Water || defender == Air)) return 1.5;
    if (attacker == Air && defender == Fire) return 1.5;
    if (attacker == Water && defender == Fire) return 1.5;
    if (attacker == Fire && defender == Grass) return 1.5;
    if (attacker == Grass && defender == Water) return 1.5;

    // This makes it show the weaknesses of attackers and defenders
    if (attacker == Fire && defender == Water) return 0.5;
    if (attacker == Water && defender == Grass) return 0.5;
    if (attacker == Grass && defender == Fire) return 0.5;

    return 1.0;
};

void explore(){
    // picks a random Pokémon from the wild pokemons list
    int index = rand() % wild_pokemons.size();
    Pokemon found = wild_pokemons[index];

    cout << "You found a wild " << found.name << "! Do you want to catch it? (Y/N): ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y'){
        // Makes sure that you haven't already caught that pokemon(used Copilot)
        bool alreadyCaught = false;
        // iterates through the users pokemon vector to check if that pokemon is already there
        for (const auto& p : user_pokemons) {
            if (p == found) {
                alreadyCaught = true;
                break;
            }
        }

        // catches the pokemon if it isn't already in your team
        if (alreadyCaught) {
            cout << "You already have " << found.name << " in your team!" << endl;
        } else {
            user_pokemons.push_back(found);
            cout << found.name << " has been added to your team!" << endl;
        }
    } else{
        cout << "You let " << found.name << " go." << endl;
    }
    
};

// Lets you pick which Pokémon you want to battle each other(they keep battling until one Pokémon runs out of health)
void battle(){
    // Makes sure you have a pokemon to fight
    if (user_pokemons.empty()){
        cout << "You have no Pokemon to battle with!" << endl;
        return;
    }

    // Randomly picks a Pokémon for you to battle
    int WildIndex = rand() % wild_pokemons.size();
    Pokemon enemy = wild_pokemons[WildIndex];

    //Lets the user pick which Pokémon of theirs they want to fight
    cout << "Choose your Pokemon: " << endl;
    for (int i = 0; i < user_pokemons.size(); i++){
        cout  <<  i + 1 << "-" << user_pokemons[i].name << "(HP: " << user_pokemons[i].currentHP << " Level: " << user_pokemons[i].level << " )" << endl;
    }
    int choice;
    cin >> choice;
    Pokemon& player = user_pokemons[choice - 1];

    cout << "\nA wild " << enemy.name << " appeared! (HP: " << enemy.currentHP << ", Level: " << enemy.level << ")" << endl;

    // lets the user know why they cant battle if their current hp is less than or equal to 0
    if (player.currentHP <= 0){
        cout << player.name << " has no HP left! Heal your Pokemon before battling." << endl;
        return;
    }


    // starts the battle
    // keeps playing until one of the Pokémon runs out of HP
    while (player.currentHP > 0 && enemy.currentHP > 0) {
        // user can choose their attack
        // lists all of the choices
        cout << "\nChoose an attack:" << endl;
        for (int i = 0; i < player.attacks.size(); ++i) {
            cout << i + 1 << ". " << player.attacks[i].name << " (Damage: " << player.attacks[i].damage << ")" << endl;
        }
        int attackChoice;
        cin >> attackChoice;

        //These help make a type-based damage bonus during the battle(used Copilot)
        int damage = player.attacks[attackChoice - 1].damage;
        // Calls the function to see how effective the attack is
        float multiplier = getTypeMultiplier(player.type, enemy.type);
        // This somehow calculates the final damage(uses the static thing to convert from float to int)
        enemy.currentHP -= static_cast<int>(damage * multiplier);
        // Shows the user which attack the other pokemon played
        cout << player.name << " used " << player.attacks[attackChoice - 1].name 
        // This is a lot more compacted of something like a if statement that explains how effective the attack was
        << "! It's " << (multiplier > 1.0 ? "super effective!" : multiplier < 1.0 ? "not very effective..." : "effective.") << endl;
        // shows the current HP of both Pokémon
        cout << player.name << " HP: " << player.currentHP << " | " << enemy.name << " HP: " << enemy.currentHP << endl;


        // Lets the user know if you defeated the enemy
        if (enemy.currentHP <= 0) {
            cout << "You defeated " << enemy.name << "!" << endl;
            break;
        }

        // This randomly lets the enemy pik a random attack 
        int enemyAttackIndex = rand() % enemy.attacks.size();

        //(used Copilot)
        int enemyDamage = enemy.attacks[enemyAttackIndex].damage;
        // Calls the function to see how effective the attack is
        float enemyMultiplier = getTypeMultiplier(enemy.type, player.type);
        // This somehow calculates the final damage(uses the static thing to convert from float to int)
        player.currentHP -= static_cast<int>(enemyDamage * enemyMultiplier);
        // Shows the user which attack the other pokemon played
        cout << enemy.name << " used " << enemy.attacks[enemyAttackIndex].name 
        // This is a lot more compacted of something like a if statement that explains how effective the attack was
        << "! It's " << (enemyMultiplier > 1.0 ? "super effective!" : enemyMultiplier < 1.0 ? "not very effective..." : "effective.") << endl;


        // Lets the user know if they lost
        if (player.currentHP <= 0) {
            cout << player.name << " has been defeated!" << endl;
        }
    
    };
    // updates the level of the user's pokemon if they win
    if (player.currentHP > 0) {
        player.level += 1;
        cout << player.name << " leveled up to " << player.level << "!" << endl;
    }
    // updates the level of the users pokemon if they lose
    else {
        if (player.level > 1) {
            player.level -= 1;
            cout << player.name << " leveled down to " << player.level << "!" << endl;
        }
    }



};

void healing(){
    //If the user doesn't have any Pokémon to heal
    if(user_pokemons.empty()){
        cout << "You have no Pokemon to heal!" << endl;
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
    cout << "Welcome to Your Pokemon Battle Game!" << endl;

    // Keeps running until they exit
    while(true){
        cout <<
        "\n\nPokemon Battle Game Menu:"
        "\n1. Explore" << endl <<
        "2. Battle" << endl <<
        "3. Heal Pokemon" << endl <<
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
            cout << "Thank you for playing Pokemon!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }

    return 0;
}