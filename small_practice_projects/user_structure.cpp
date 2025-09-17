// AX User Structure Program

/*
INSTRUCTIONS:
Write a program that takes in a username, password, and admin status. The program then uses that information to create a user object from a structure. 

It then needs to compare that user with a list of already existing users (10 users minimum) to see if the user already exists.

OUTPUT EXAMPLE: 

User: Alex LaRose

Already exists. 

OR

Welcome

User: Alex LaRose

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// structure that holds the values
struct User{
    string username;
    string password;
    bool isAdmin;

};

// compares users based on their username and password
bool operator==(const User& first, const User& second){
    return first.username == second.username && first.password == second.password;
}

int main(){
    // a list with 10 users that already exist
    vector<User> existingUsers = {
        {"Alishya Xavier", "123456", true},
        {"Emma Richard", "222333444", false},
        {"Mia Scar", "9876543", true},
        {"Ava Burgeson", "13243546", false},
        {"Charity Strong", "5656565", true},
        {"Bob Joe", "4656354", true},
        {"Billy Fetcher", "8882772", false},
        {"Max Weber", "000330", false},
        {"Sophia Holland", "1356332", false},
        {"Anna Hunt", "8357833", true},
    };

    //the user inputs their info
    string inputUsername;
    string inputPassword;
    bool inputIsAdmin;

    cout << "username: ";
    getline(cin, inputUsername);

    cout << "password: ";
    getline(cin, inputPassword);

    cout << "Are you Admin(0 for no, 1 for yes): ";
    cin >> inputIsAdmin;

    //Creates a new user object
    User newUser = {inputUsername, inputPassword, inputIsAdmin}

    ///working on this part ......................
    bool userExists = false;

    for (const auto& user : existingUsers) {
        if (user == newUser) {
            userExists = true;
            break;
        }
    }

    cout << "\nUser: " << newUser.username << endl;

    if (userExists) {
        cout << "Already exists." << endl;
    } else {
        cout << "Welcome" << endl;
    }



    return 0;
}
