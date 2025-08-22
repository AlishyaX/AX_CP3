// AX VData Types, Variables, Inputs, and Outputs

#include <iostream>
using namespace std; //makes it so you don't have to write <<std::endl at the end of every line

int main(){
    int students = 11;
    double days = 5;
    long years = 2554l; // long will compile with int unless you put l at the end
    const float pi = 3.14f; // floats will compile to a double unless you put an f at the end
    bool on = true;
    char name = 'A';
    cout << "Tell me your age";
    int age;
    cin >> age;
    double divide = students/days;
    cout << divide;
    return 0;
}




// Questions:
//------------------------------------------------------------------------------------------------------------------------------------------------

// How are static and dynamically typed variables different?
    // They are different because static variables nead to clarify the type while dynamically types so not need us to declare the type.
    // int/4bytes/-2 bill to 2 bill
    // short/2bytes/-32,768 to 32, 768
    // long/4bytes/-2 bill to 2 bill
    // long long/8bytes/big #
    // floats/4bytes/3.4E38
    // doubles/8bytes/1.7E308
    // long doubles/3bytes/3.4E932
    // bool/8bytes/tre or false
    // char/1byte/single letter




// REMINDER: What is the difference between instantiating and declaring a variable?
    // Instantiating a variable is where you create an object.
    // Declaring a variable is where you define the variables name and type.


// What case type should be used for c++ variables?
    // We like to use snake case.

// What is the C++ standard library?
    // The C++ standard library includes all of the things that are add on that make your program work easier.
    // Right now we are using iostream meanining input, output, stream that controlls information going in and out of your computer.

// How do you access the standard library?
    // To access the standard library you can just search it up and it pulls up everything.

// How do you create an output in C++?
    // You can create an output in C++ by using the cout object from the iostream library.

// How do you create an input in C++?
    // To get an input first make an output. Then specify the type of variable. Then cin >> variable.

// What is the stream in C++?
    // The stream is the flow of information where the input and output are going.


// What is a constant?
    // Values within our program that we don't want to change.

// Why do we write constants?
    // Before the word you put const.