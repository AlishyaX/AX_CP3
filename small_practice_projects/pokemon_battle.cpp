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



*/


 #include <iostream>

 using namespace std;

 enum Menu{
    Explore = 1,
    Battle,
    Heal,
    Exit
 };
void explore(){

};

void battle(){

};

void heal(){

};
int main(){
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
        cin >> input;

    
        if (input == Menu::Explore){
            explore();
        }else if(input == Menu::Battle){
            battle();
        }else if(input == Menu::Heal){
            heal();
        }else if(input == Menu::Exit){
            cout << "Thank you for playing Pokémon!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }

    return 0;
}