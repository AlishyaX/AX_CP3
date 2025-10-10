// AX Strings, Arrays, Conditionals notes
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int seconds = time(nullptr);
    srand(seconds);
    int my_num = rand() % 11;
    cout << my_num << endl;

    // Creates an array
    int grades[11] = {99,24,48,67,48,84,77,79,87,65,98};
    cout << grades[3] << endl;

    // Creates a string
    string name = "Alishya";
    cout << name << endl;
    string sentence = "The quick brown fox fumps over the lazy dog";
    cout << sentence << endl;
    cout << sentence.length() << endl;
    cout << (name > sentence) << endl;
    
    




//Questions:
//------------------------------------------------------------------------------------
// What is Narrowing?
    // you take a variable that already exists and move its content to a variable that is a smaller amount of space.
    // for example chnaging a long into a int
    // Risk: You can loose info
    // With numbers you can use apostrophes as commas and it wont mess up anything

// What is a basic way to generate random numbers in C++?
    // The basic way is to use % #U want the random to be until.

// What is an array?
    // An array is a list 

// How do I create an array?
    // To create an array you specify how many items are in the list and what it is equal to in curly brackets.

// How do you make strings in C?
    // strings are an array of characters
    // You make it by making the name of the variable and specify the length and one more.

// How did C++ improve creating strings? 
    // We improved it by just using string from the std library.

// How do I search a string?
    // .starts_with() and .ends_with() checks to see what character the string starts and ends with
    // .empty() checks to see if the string is empty
    // Both give a true or false output(0 or 1)
    // .front() <= returns the first char
    // .back() <= returns the last char
    // rfind() <= starts the search at the end of the string
    // find_first_of() <= finds the first occurance of the character given
    // find_last_of() <= finds the last occuramce of the char given
    // .find_last_not_of() <= 

// How do I modify a string?
    // You can do .append()
    // You can do .insert()
    // You can do .erase()
    // You can do .clear() to make it an empty string
    // You can do .replace(index, "string") to replace a string

    name.append("Alishya");
    cout << name << endl;

    
// What are some string methods? 
    // We can do the .length() method to find th elength of the string.
    // sub strings a strings inside of strings
    // cout << sentence.substr(starting #, length) << endl;
    
// What are conditionals?
if(name < sentence){
    cout << name.front() << "is earlier in the alphabet" << sentence.front() << endl;
}else if(){

}else{
    
}

return 0;
}