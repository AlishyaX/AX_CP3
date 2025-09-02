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


// Displays the board in a specific way
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
    int row, col;
    cout << "Enter row(0-2): ";
    cin >> row;
    cout << "Enter column(0-2)";
    cin >> col;

    // Keeps asking the user until they have picked a spot that is empty
    if (board[row][col] != ' '){
        cout << "That is spot is already taken. Please Try Again!";
        usermove();
    } else{
        board[row][col] = 'X';
    }
}

void computermove() {
    srand(time(0)); 
    int row_num, col_num;

    do {
        row_num = rand() % 3;
        col_num = rand() % 3;
    } while (board[row_num][col_num] != ' ');

    board[row_num][col_num] = 'O';
    cout << "Computer placed an O at (" << row_num << ", " << col_num << ")" << endl;
}

char check_winner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; // No winner yet
}


bool is_tie() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}



int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

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
        if (is_tie()) {
            display_board();
            cout << "It's a tie!" << endl;
            break;
        }
    }

    return 0;
}

