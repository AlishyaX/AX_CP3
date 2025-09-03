// AX Tic Tac Toe Project

#include <iostream>
// Random number generation
#include <cstdlib>
#include <ctime>
using namespace std;

// game Grid saved as a multidimentional array
char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };


// Displays the board in a specific way that the grid is looped over to print
void display_board(){
    for (int i = 0; i < 3; i++){
        cout << " " << board[i][0] << " | " << board[i][1] << "|" << board[i][2] << endl;
        if (i<2){
            cout << "---|--|---" << endl;
        }
    }
}

// Lets the user make a move and tells them if the spot is already taken else prints it on the board
void usermove(){
    // Users are given the opportunity to input their chosen spot
    int row, col;
    cout << "Enter row(1-3): ";
    cin >> row;
    row--;
    cout << "Enter column(1-3): ";
    cin >> col;
    col--;

    // Keeps asking the user until they have picked a spot that is empty
    if (board[row][col] != ' '){
        cout << "That is spot is already taken. Please Try Again!";
        usermove();
    } else{
        board[row][col] = 'X';
    }
}

void computermove() {
    // The computer randomly generates the spot and places it inside the array/grid
    srand(time(0)); 
    int row_num, col_num;

    // Didn't know about this till searched it up
    do {
        // Makes the random number chosen have to be (0, 1, or 2)
        row_num = rand() % 3;
        col_num = rand() % 3;
      // Only puts the num in the grid if it isn't already occupied
    } while (board[row_num][col_num] != ' ');

    // Puts O in the spot the computer chose and informs the user 
    board[row_num][col_num] = 'O';
    cout << "The computer placed its move\n" <<endl;
}

char check_winner() {
    // Checks all of the ways that the user could have a win
    // returns the character in the grid that won, else returns an empty character
    // This part was the most confusing for me to understand
    for (int i = 0; i < 3; i++) {
        // All rows and all collumns
        // the i's help check every column and every row
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Checks diagonals( There are only two diagnols that can let the comp or user win)
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; 
}

// This makes it so if the check function for either doesn't win then it will either end because it is a tie or keep running if there is still space on the grid
// This also was quite hard to understand
bool is_tie() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}



int main() {
    // Instructions on how to play
    cout << "Welcome to Tic-Tac-Toe!" << "\nTo play the game all you have to do is type in the row and column you want to put your X on.\nFor example you cant type in (1-3) for both the column and row.\n" << endl;

    // All the checks that either make the game a tie or the computer/user wins
    while (true) {
        display_board();
        usermove();
        if (check_winner() == 'X') {
            display_board();
            cout << "You win!" << endl;
            break;
        }
        if (is_tie()) {
            display_board();
            cout << "It's a tie!" << endl;
            break;
        }

        computermove();
        if (check_winner() == 'O') {
            display_board();
            cout << "Computer wins!" << endl;
            break;
        }
        
    }

    return 0;
}

