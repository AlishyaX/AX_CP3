// AX strings, arrays, and conditionals part 2

#include <iostream>
#include <limits>
using namespace std;

string fam[5] = {"Alishya", "Andrew", "Jalaja", "Ajash"};
string sibs[1] = {"Ajash"};
// Array as an argument
void search(string list[], int len, string item){
    for(int i=0; i < len; i++){
        if (list[i] == item){
            cout << "You are a sibling\n";
            return 1;
        }
    }
    cout << "You are a parent!\n";
    return 0;
}

int main(){
    
    for(int i=0;i <size(fam);i++){
        cout << fam[i] << " Xavier\n";
        search(sibs,size(fam), fam[i]);
    }

    //Size of T
    cout << numeric_limits <long long>::min() <<endl;
    cout << numeric_limits <long long>::max() <<endl;
    cout << numeric_limits <size_t>::min() <<endl;
    cout << numeric_limits <size_t>::max() <<endl;

    //Structured Binding
    auto [a,b,w,e,r,t,y,g,u,j] = fam
    cout << e << endl;

    //Multi demensional
    int matrix[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};

    return 0;
}



// Questions
//-----------------------------------------------------------------
// How are for loops constructed in C++
    // For loops are constructed by using the for key word
    // example: for(int i=0;i < size(fam);i++)
        //cout << fam[i] << " Xavier\n";

//When do you need to use curly brackets in C++
    // They help define bloacks of code. They are needed to group statements together, and enclose the body of a function.

//How do you compare items in arrays
    // You cant compare lists because its comparing if the lists are saved to the same location which are never gonna.

//How do you use an array as an argument in a function
    //You use an array as an argument by above

//What is type_t
    // finds the size of the largest type of info

//Why would we use type_t
    // you can use it as a replacement for specifying data

//How do you search an array
    //

//How do you sort an array
    //

//How do you make a multi-dimensional array
    //