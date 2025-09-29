// AX Text Files Notes

/*

QUESTIONS:
What are the 3 main sources of data for a program
-terminal - cout, cin (User given)
-file - txt, csv, binary
-network - internet, other computers

What are streams?
- a source of data or a destination

What are the different streams we might need to include in a program? 
-istream(write) and ostream(read) (ios-input, output stream)


What is the base class for all streams?
-iostream

What is buffer?
- a temporary storage in memory for reading values

How do you clear the buffer?
- cinignore(# of characters to ignore, specific # to stop ignoring on)

How do you handle invalid inputs from the terminal
- .fail() - checks if the user inputed a string instead of a number

What streams are for files specifically
-ifstream(allows us to input filestream)
-ofstream(allows us to output filestream)
-fstream(combines both ifstream and ofstream)

How do you write to a text file?
- you use file.is_open()
- you use file << "text" to write to the file

What do stream manipulators let us do?
-lets you change the formatting of how you write it to the file

How do you write to a CSV?
- first do file << the headers
- then do file << the data, separating each item with a comma

How do you read a text file?
-
How do you read a CSV file?
-
What is a delimiter?
-
How do you read an entire CSV?
-
How do you turn items from a CSV into objects of a structure?
-

*/

#include <iostream>
#include <limits> 
#include <fstream>
#include <iomanip>
using namespace std;

int getNumber(const string& prompt){
    int num;
    while(true){
        cout << prompt;
        cin >> num;
        if (cin.fail()){
            cout << "Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else break;  
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}

int main(){
    int first = getNumber("Enter first number: ");
    int second = getNumber("Enter second number: ");
    cout << "You entered " << first << " and " << second << endl;

    ofstream file;
    file.open("data.txt");
    if(file.is_open()){
        file << setw(20) << "Hello " << setw(20) << "World!" << endl;
        file.close();
    }

    // CSV
    file.open("data.csv");
    if(file.is_open()){
        file << "id, title, year\n"
        << "1, Terminator, 1984\n"
        << "2, Terminator, 1991\n";
        file.close();
    }



    return 0;
}