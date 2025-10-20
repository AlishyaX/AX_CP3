// AX User Structure Program

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// user structure that holds the values
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

    //Lets the user keep logging in until they dont want to
    while(true){
        bool userExists = false;
    
        cout << "Username: ";
        getline(cin, inputUsername);

        cout << "Password: ";
        getline(cin, inputPassword);

        cout << "Are you Admin(0 for no, 1 for yes): ";
        cin >> inputIsAdmin;

        //Creates a new user object
        User newUser = {inputUsername, inputPassword, inputIsAdmin};

        // Checks to see if the user is in the existing list and if so returns true
        for (const auto& user : existingUsers) {
            if (user == newUser) {
                userExists = true;
                break;
            }
        }

        // output displays if their already a user or if they are new
        if (userExists) {
            cout << "\nUser: " << newUser.username << endl;
            cout << "Already exists." << endl;
        } else {
            cout << "Welcome" << endl;
            cout << "User: " << newUser.username << endl;
        }

        string choice;
        cout << "Do you want to log in again(y or n): ";
        cin >> choice;
        cin.ignore();// copilot suggested using this to let it keep running

        if(choice == "n") {
            cout << "Bye!!!" <<endl;
            break;
        }

    }


    return 0;
}
