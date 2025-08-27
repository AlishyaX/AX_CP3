// AX strings, arrays, and conditionals part 2

#include <iostream>
using namespace std;

string fam[4] = {"Alishya", "Andrew", "Jalaja", "Ajash"};
string sibs[1] = {"Ajash"};

void search(string list, string item);
    cout << list << endl;

int main(){
    
    for(int i=0;i < size(fam);i++){
        cout << fam[i] << " Xavier\n";
        if(fam[i]== sibs[i-3])
            cout << "They are siblings\n";
    }


    return 0;
}




// Questions
//-----------------------------------------------------------------
// How are for loops constructed in C++
    // For loops are constructed by using the for key word
    // example: for(int i=0;i < size(fam);i++)
        //cout << fam[i] << " Xavier\n";

//When do you need to use curly brackets in C++
    //

//How do you compare items in arrays
    // You cant compare lists because its comparing if the lists are saved to the same location which are never gonna.

//How do you use an array as an argument in a function
    //

//What is type_t
    //

//Why would we use type_t
    //

//How do you search an array
    //

//How do you sort an array
    //

//How do you make a multi-dimensional array
    //