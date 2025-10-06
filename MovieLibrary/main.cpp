// AX Movie Library

/*
INSTRUCTIONS:
Create an application that manages your Movie Library using structures to store movie details and enumerations for menu options. 
Your program should persist movie data by reading from and writing to an external file in CSV format.

Main menu needs to allow our user to load the library from a file (I will use a different one than the example one I have given you), 
view all movies, add a movie, delete a movie, and search movies.

The search menu should allow the user to select what they would like to search by, 
then the specific value they would like to search. 

NOTE: You need to build a sequential search algorithm for this project (it is a state standard) 

NOTE: Practice Movies ListDownload Practice Movies List

EXAMPLE:
Rating (e.g., G, PG, PG-13, R)
Director (e.g., Christopher Nolan)
Release Year (e.g., 1987)
Genre (e.g., Action, Comedy)

KEY REMINDERS:
Use structures to organize movie data.
Use enumerations for the menu.
Incorporate input validation and error handling.
Make sure the program is user-friendly and clear.


*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Movie{
    string title;
    string rating;
    string director;
    int releaseYear;
    string genre;

};

enum Menu{
    LoadLibrary = 1,
    ViewMovies,
    AddMovie,
    DeleteMovie,
    SearchMovies,
    Exit
};

enum SearchMenu{
    ByTitle = 1,
    ByRating,
    ByDirector,
    ByReleaseYear,
    ByGenre,
    Back
};

int main(){
    int input;
    cout << "Welcome to Your Movie Library!" << endl;

    // Keeps running until they exit
    while(true){
        cout <<
        "\n\nMovie Library Menu:"
        "\n1. Addition" << endl <<
        "2. Subtraction" << endl <<
        "3. Multiplication" << endl <<
        "4. Division" << endl <<
        "5. Exit" << endl <<
        "Select(1-5): ";

        while(!(cin >> input)){
            cout << "Please enter a number option" << endl;
            cin.clear();
            cin.ignore();
        }
        

    
        if (input == Menu::Add){
            addition();
        }else if(input == Menu::Sub){
            subtraction();
        }else if(input == Menu::Mult){
            multiplication();
        }else if(input == Menu::Div){
            division();
        }else if(input == Menu::Exit){
            cout << "Thank you for using my Calculator!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }


    return 0;
}


