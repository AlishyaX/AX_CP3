// AX Movie Library

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


// helps with saving the file later
string currentFilename; // Global variable to store the current filename

// movie structure to hold each movie's details from csv
struct Movie{
    string title;
    string rating;
    string director;
    int releaseYear;
    string genre;

};

// vector to hold all of the movies in the library
vector<Movie> movieLibrary;

// main menu options
enum Menu{
    LoadLibrary = 1,
    ViewMovies,
    AddMovie,
    DeleteMovie,
    SearchMovies,
    Exit
};

// helps me search each of the different search options
enum SearchMenu{
    ByTitle = 1,
    ByRating,
    ByDirector,
    ByReleaseYear,
    ByGenre,
    Back
};

// A lot of help understanding from Copilot
// Function to load the movie library from a specified CSV file
void loadLibrary(){
    // tested with movies.csv and works
    // I'm pretty sure the file tested has to be in the Movie Library folder
    // gets the user's filename that they want to have the movies from
    string fileName;
    cout << "Enter the filename to load the movie library from: ";
    cin >> fileName;
    currentFilename = fileName; // Store for saving later


    // Syntax just in case there is an issue with opening the file
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }

    // this clears the current library just in case there is one open so that there is no mixing data
    movieLibrary.clear();
    // declares a variable to hold each line taken from the file
    string line;

    getline(inputFile, line); // Skip header row if present

    // a loop that reads each line from the file line by line
    while (getline(inputFile, line)) {
        // uses stringstream to parse lines seperating them with commas
        stringstream ss(line);
        // movie struct to hold the data temporarily
        Movie movie;
        // temporarily holds the release year and also changes it to be a string so its easier to parse
        string releaseYearStr;

        // gets each part of the movie data from each line in the
        getline(ss, movie.title, ',');
        getline(ss, movie.director, ',');
        getline(ss, releaseYearStr, ',');
        getline(ss, movie.genre, ',');
        getline(ss, movie.rating, ',');


        // converts the release year back into an integer and stores it
        movie.releaseYear = stoi(releaseYearStr);
        // adds the movie structure to the movieLibrary vector
        movieLibrary.push_back(movie);
    }

    // closes the file after reading and updates user
    inputFile.close();
    cout << "Movie library loaded successfully from " << fileName << endl;
}



// Displays all of the movies using setw to format the output
void viewMovies(){
    // checks if there are any movies in the library
    if (movieLibrary.empty()) {
        cout << "No movies in the library. Please load a library first." << endl;
        return;
    }else{

        // prints out the header for the movie list(setw is used to format the output)
        cout << left << setw(30) << "Title" 
            << setw(8) << "Rating" 
            << setw(35) << "Director" 
            << setw(14) << "Release Year" 
            << setw(25) << "Genre" << endl;
        cout << string(112, '-') << endl;

        // loops through each movie in the library and prints out its details(the same setw formatting is used to keep it aligned)
        for (const auto& movie : movieLibrary) {
            cout << left << setw(30) << movie.title 
                << setw(8) << movie.rating 
                << setw(35) << movie.director 
                << setw(14) << movie.releaseYear 
                << setw(25) << movie.genre << endl;
        }
    }
}


// Function to add a movie to the csv
void addMovie(){
    //creates a movie struct to hold the new movie data
    Movie newMovie;

    // gets the movie details from the user
    cout << "Enter movie title: ";
    cin.ignore();
    getline(cin, newMovie.title);

    cout << "Enter movie rating (e.g., G, PG, PG-13, R): ";
    getline(cin, newMovie.rating);

    cout << "Enter movie director: ";
    getline(cin, newMovie.director);

    cout << "Enter movie release year: ";
    // checks to make sure the user types in an integer for the release year
    while(!(cin >> newMovie.releaseYear)){
        cout << "Please enter a valid year" << endl;
        cin.clear();
        cin.ignore();
    }

    cin.ignore();
    cout << "Enter movie genre: ";
    getline(cin, newMovie.genre);

    // adds the new movie to the movieLibrary vector
    movieLibrary.push_back(newMovie);
    cout << "Movie added successfully!" << endl;
}


// Function to delete a movie in the csv by the title
void deleteMovie(){
    // checks if there are any movies in the library
    if (movieLibrary.empty()) {
        cout << "No movies in the library. Please load a library first." << endl;
        return;
    }

    //saves the title of the movie to delete
    string titleToDelete;
    cout << "Enter the title of the movie to delete: ";
    cin.ignore();
    getline(cin, titleToDelete);

    // uses the find_if algorithm to search through the vector and checks if the movie title's match
    // it returns an iterator to the found movie or the end of the vector if not found
    // partially still confused on how the iterartor works
    auto it = find_if(movieLibrary.begin(), movieLibrary.end(), [&](const Movie& movie) {
        return movie.title == titleToDelete;
    });

    // if the movie was found, it deletes it from the vector and updates the user
    if (it != movieLibrary.end()) {
        movieLibrary.erase(it);
        cout << "Movie \"" << titleToDelete << "\" deleted successfully!" << endl;
    } else {
        cout << "Movie \"" << titleToDelete << "\" not found in the library." << endl;
    }
}


// Function that allows the user to search for movies based on different criteria
// Seems very complex with copilot help but when broken down to small parts understandable
void searchMovies(){
    // checks if there are any movies in the library
    if (movieLibrary.empty()) {
        cout << "No movies in the library. Please load a library first." << endl;
        return;
    }

    //stores the user's search option
    int searchOption;

    cout << "\nSearch Menu:"
         << "\n1. By Title"
         << "\n2. By Rating"
         << "\n3. By Director"
         << "\n4. By Release Year"
         << "\n5. By Genre"
         << "\n6. Back to Main Menu"
         << "\nSelect(1-6): ";

    //makes sure they input an int
    while(!(cin >> searchOption)){
        cout << "Please enter a number option" << endl;
        cin.clear();
        cin.ignore();
    }

    cin.ignore(); // Clear newline character just in case there was anything left

    // made a variable to hold the search term and search year
    string searchTerm;
    int searchYear;

    // vector to hold the search results
    vector<Movie> results;
    
        //if the user chose to search by title
        if(searchOption == ByTitle) {
        cout << "Enter title to search: ";
        getline(cin, searchTerm);
        // loops through the movie library and checks if the search term is found in the movie title ... etc for all of the other conditions
        // if it is found, it adds it to the results vector(same with all of the other options)
        for(const auto& movie : movieLibrary) {
            if(movie.title.find(searchTerm) != string::npos){
                results.push_back(movie);
            }
        }
        // if the user chose to search by rating
        }else if(searchOption == ByRating){
            cout << "Enter rating to search: ";
            getline(cin, searchTerm);
            for(const auto& movie : movieLibrary){
                if(movie.rating == searchTerm){
                    results.push_back(movie);
                }
            }
        // if the user chose to search by director
        }else if(searchOption == ByDirector){
            cout << "Enter director to search: ";
            getline(cin, searchTerm);
            for(const auto& movie : movieLibrary){
                if(movie.director.find(searchTerm) != string::npos){
                    results.push_back(movie);
                }
            }
        // if the user chose to search by release year
        }else if(searchOption == ByReleaseYear){
            cout << "Enter release year to search: ";
            while(!(cin >> searchYear)){
                cout << "Please enter a valid year" << endl;
                cin.clear();
                cin.ignore();
            }
            for(const auto& movie : movieLibrary){
                if (movie.releaseYear == searchYear){
                    results.push_back(movie);
                }
            }
            cin.ignore(); // Clear buffer after reading number
        } else if(searchOption == ByGenre){
            cout << "Enter genre to search: ";
            getline(cin, searchTerm);
            for(const auto& movie : movieLibrary){
                if(movie.genre.find(searchTerm) != string::npos){
                    results.push_back(movie);
                }
            }
        } else if(searchOption == Back){
            return;
        } else {
            cout << "Invalid option. Returning to main menu." << endl;
            return;
        }

        // Display results
        if(results.empty()){
            cout << "No movies found matching your search." << endl;
        } else {
            cout << "\nSearch Results:\n";
            cout << left << setw(30) << "Title" 
                << setw(10) << "Rating" 
                << setw(25) << "Director" 
                << setw(15) << "Release Year" 
                << setw(20) << "Genre" << endl;
            cout << string(100, '-') << endl;
            for(const auto& movie : results){
                cout << left << setw(30) << movie.title 
                    << setw(10) << movie.rating 
                    << setw(25) << movie.director 
                    << setw(15) << movie.releaseYear 
                    << setw(20) << movie.genre << endl;
        }
    }
}


// Function that saves the current movie library to a specified file in CSV format that was loaded at the beginning
// aka it overwrites the file with any changes the user made and saves it
void saveLibrary(const string& filename) {
    // opens the file for writing
    ofstream outputFile(filename);
    // Write header for the CSV file
    outputFile << "Title,Director,Release Year,Genre,Rating\n";

    // Write each movie's details in CSV format
    for (const auto& movie : movieLibrary) {
        outputFile << movie.title << ","
                   << movie.director << ","
                   << movie.releaseYear << ","
                   << movie.genre << ","
                   << movie.rating << "\n";
    }

    outputFile.close();
    cout << "Movie library saved successfully to " << filename << endl;
}



// Main function
int main(){
    int input;
    cout << "Welcome to Your Movie Library!" << endl;

    while(true){
        cout <<
        "\n\nMovie Library Menu:"
        "\n1. Load a library from a file" << endl <<
        "2. View all movies" << endl <<
        "3. Add a movie" << endl <<
        "4. Delete a movie" << endl <<
        "5. Search movies" << endl <<
        "6. Exit" << endl <<
        "Select(1-6): ";

        while(!(cin >> input)){
            cout << "Please enter a number option" << endl;
            cin.clear();
            cin.ignore();
        }
        

    
        if (input == Menu::LoadLibrary){
            loadLibrary();
        }else if(input == Menu::ViewMovies){
            viewMovies();
        }else if(input == Menu::AddMovie){
            addMovie();
        }else if(input == Menu::DeleteMovie){
            deleteMovie();
        }else if(input == Menu::SearchMovies){
            searchMovies();
        }else if(input == Menu::Exit){
            // saves anything the user has edited to the current file they loaded from
            saveLibrary(currentFilename);
            cout << "Thank you for using your Movie Library!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }

    return 0;
}
    



