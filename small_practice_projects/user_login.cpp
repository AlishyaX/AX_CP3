//AX User Login Program
// Write a program that takes in a user name and checks to see if that user is an admin, returning user, or a new user and then says hello to them accordingly. 
// I need tro make a list to store the user names so i can check if they return
// Have another list that saved all of the Admins
#include <iostream>
using namespace std;

int main(){
    string user_name;
    cout << "What is your username: ";
    cin >> user_name;
    string admin_list = {"Mrs. Larose", "Alishya"};
    cin >> admin_list;
    if(user_name == admin_list)
    return 0;

}