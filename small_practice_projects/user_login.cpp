//AX User Login Program

#include <iostream>
using namespace std;

int main(){
    string user_name;
    cout << "What is your username: ";
    cin >> user_name;
    string admin_list[2] = {"Mrs. Larose", "Alishya"};
    string returning[5] = {"Billy", "Bob", "Joe", "Sara", "Jill"};
    if(user_name == admin_list[0]){
        cout << "Hello Admin Mrs. Larose";
    } else if(user_name == admin_list[1]){
        cout << "Hello Admin Alishya";
    } else if(user_name == returning[0]){
        cout << "Welcome back Billy";
    } else if(user_name == returning[1]){
        cout << "Welcome back Bob";
    }  else if(user_name == returning[2]){
        cout << "Welcome back Joe";
    }  else if(user_name == returning[3]){
        cout << "Welcome back Sara";
    }  else if(user_name == returning[4]){
        cout << "Welcome back Jill";
    } else{
        cout << "Lets get you signed up " << user_name;
    }
    return 0;

}