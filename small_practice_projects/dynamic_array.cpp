// AX Dynamic Array Program

// I had to have copilot teach me getline(), empty(), and move().
// I also renamed temp into newColors so I can understand it better

#include <iostream>
#include <string>
#include <memory> // to be able to use the unique pointers

using namespace std;

int main(){
    cout << "Welcome to the color test! This is where you can test how many colors you know.\n" << endl;
    int capacity = 5; // array starts with only the space for 5 colors
    unique_ptr<string[]> colors = make_unique<string[]>(capacity); // the unique pointer that manages the dynamic array of strings
    int entries = 0; // keeps track of how many colors the user inputs
    string input; // stores the colors inputted

    while (true){
        cout << "Type in a color(click enter if you don't know anymore): ";
        getline(cin, input); // This lets the user type in multiple lines and save it in input
        
        if(input.empty()) break; // if they dont know anymore colors
        
        if(entries == capacity){
            capacity += 5; // if the amount of space in the array are all used up it will give it more space
            unique_ptr<string[]> newColors = make_unique<string[]>(capacity); // makes a bigger array to hold more colors

            for(int i = 0; i < entries; i++){
                newColors[i] = move(colors[i]); // moves all the colors from the old array into the new one
            }
            
            colors = move(newColors); // replaces the old array with the new one
        }

        // Stores the users input color into array and adds one to entries
        colors[entries] = input;
        entries++;
    }
    //prints all the colors
    cout << "Here are all of the colors you entered:" << endl;
    for(int i = 0; i < entries; i++){
        cout << "-" << colors[i] << endl;
    }

    
    return 0;
}