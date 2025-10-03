// AX Binary and Searching Notes


#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

struct Movie{
    string title;
    int year;

};

using namespace std;
string to_string(double number, int precision){
    stringstream stream; // controls how things are being controlled
    stream << fixed << setprecision(precision) << number; // can change the num of floats wanted to include
    return stream.str();
}

Movie parseMovie(string str){
    // Parsing(taking the stream and telling the computer where to start and stop and where to change it to a different type)
    stringstream stream;
    stream.str(str);
    Movie movie;
    getline(stream, movie.title, ','); // gets everything up to the comma, deliminator
    stream >> movie.year; // reads the year
    return movie;
}

int main(){
    double number = 3.14;

    cout << to_string(number, 2) << endl; // 3.14

    //parsing
    string user = "10 20";
    stringstream fix;
    fix.str(user);
    int first;
    fix >> first;

    int second;
    fix >> second;
    cout << "first: " << first << endl << "second: " << second << endl;


    auto movie = parseMovie("Terminator 1,1984");
    cout << movie.title << endl << movie.year << endl;

   
    fstream file;
    file.open("file.txt", ios::in | ios::out | ios::app);
    if(file.is_open()){


        file.close();
    }


    



    return 0;

}


/*
QUESTIONS:
What is a potential issue with converting values to strings without control?
istringstream is for reading a string
ostringstream is for writing a string
stringstream is for reading and writing a string

How can you control the way a value is converted to a string?
You can control it by using stringstream along with manipulators like fixed and setprecision.

Why is it useful to create a reusable function for converting values to strings?
The function above called to_string converts a double to a string with a specified number of decimal places.

What is parsing in the context of working with strings?
Extracting a piece of information from a string.

How do you extract specific information from a string in programming?


When a title contains a space, which function should you use to read it properly?


Why might extra zeros be added to a string when converting a value without control?


How does controlling the string conversion process benefit your program?


Give an example scenario where parsing a string would be necessary in a program.


When writing to a binary file, what does the first parameter (reinterpret_cast<char*>(&numbers)) represent?


Why does the binary file only take 12 bytes while the array of integers might be larger?


What is the main difference between sequential search and binary search?


In which type of data structure is binary search most efficient?


What is a key requirement for binary search to work correctly on a list?


How does sequential search find an item in a list?


Why is binary search generally faster than sequential search for large, sorted lists?



*/
