// AX High Score Leaderboard Program
// the ones that I over explain is the ones I didn't know how to do even with notes before using Copilot
#include <iostream>
#include <limits> 
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
//(Used Copilot)
#include <algorithm>
using namespace std;

//menu options
enum Menu{
    NewHighScore = 1,
    DisplayHighScores,
    Exit
};

//structure for each high score entry
struct HighScore {
    string playerName;
    int score;
    string date;
};

// Reads all high scores from file into a vector(Used Copilot)
vector<HighScore> readHighScores(const string& filename) {
    // creates an empty vector of high scores
    vector<HighScore> scores;
    // opens the file to read
    ifstream file(filename);
    string line;
    // starts a loop that reads each line
    while(getline(file, line)) {
        // finds the commas in each line
        size_t firstComma = line.find(',');
        size_t lastComma = line.rfind(',');
        // uses the commas to find each value either before or after the comma
        if(firstComma != string::npos && lastComma != string::npos && firstComma != lastComma) {
            // makes a highsore structure to hold the data of the scores
            HighScore hs;
            hs.playerName = line.substr(0, firstComma);
            hs.score = stoi(line.substr(firstComma + 1, lastComma - firstComma - 1));
            hs.date = line.substr(lastComma + 1);
            // adds the high score structure to the vector
            scores.push_back(hs);
        }
    }
    return scores;
}

// Writes all high scores from vector to file
void writeHighScores(const string& filename, const vector<HighScore>& scores) {
    // opens the file to be able to write to it
    ofstream file(filename, ios::trunc);
    // a loop that iterates over each high score in the vector
    for(const auto& hs : scores) {
        // writes the players name, score, and date in a specific way the csv wants
        file << hs.playerName << "," << hs.score << "," << hs.date << endl;
    }
}

// function to add a new high score
void newhighscore(vector<HighScore>& scores){
    //variables for player name, score, and date
    string playerName, date;
    int score;

    // player name input
    cout << "Enter player name: ";
    cin >> playerName;

    // score input
    cout << "Enter score: ";
    while(!(cin >> score)){
        // Makes sure that the score is a number
        cout << "Please enter a valid number for the score: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // date input
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> date;
    scores.push_back({playerName, score, date});
    // Sort scores in descending order
    sort(scores.begin(), scores.end(), [](const HighScore& a, const HighScore& b){
        return a.score > b.score;
    });
    cout << "High score added!" << endl;
}

//function to display high scores
void displayhighscore(const vector<HighScore>& scores){
    // makes sure they have high scores
    if(scores.empty()){
        cout << "No high scores available." << endl;
        return;
    }

    cout << "--- High Scores ---" << endl;

    // variables for each num for displaying and line reading
    int num = 1;
    for(const auto& hs : scores) {
        cout << num << ". Player: " << hs.playerName << " | Score: " << hs.score << " | Date: " << hs.date << endl;
        num++;
    }
}


// main function with the menu and the loop letting them add a new high score, display high scores, or exit
int main(){
    const string filename = "scoredata.csv";
    vector<HighScore> scores = readHighScores(filename);

    int input;
    cout << "Welcome to Your High Score Leaderboard!" << endl;

    // Keeps running until they exit
    while(true){
        cout <<
        "\n\nCalculator Menu:"
        "\n1. Add a new high score" << endl <<
        "2. Display high scores" << endl <<
        "3. Exit" << endl <<
        "Enter your choice(1-3): ";

        while(!(cin >> input)){
            cout << "Please enter a number option" << endl;
            cin.clear();
            cin.ignore();
        }
        


        if (input == Menu::NewHighScore){
            newhighscore(scores);
            writeHighScores(filename, scores);
        }else if(input == Menu::DisplayHighScores){
            displayhighscore(scores);
        }else if(input == Menu::Exit){
            cout << "Goodbye!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }


    return 0;
}