// AX Tic Tac Toe Project

#include <iostream>
// Random number generation
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };


int main(){
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "You will be playing the computer.\nTo play all you have to do is type in the number of the place on the board you want to place your spot on.";
    

}

void display_board(){
    for (int i = 0; i < 3; i++){
        cout << " " << board[i][0] << " | " << board[i][1] << "|" << board[i][2] << endl;
        if (i<2){
            cout << "---|---|---" << endl;
        }
    }
}

void usermove(){
    int row, col;
    cout << "Enter row(0-2): ";
    cin >> row;
    cout << "Enter column(0-2)";
    cin >> col;

    // Keeps asking the user until they have picked a spot that is empty
    while (board[row][col] != ' '){
        cout << "That is spot is already taken. Please Try Again!"

    }


}
