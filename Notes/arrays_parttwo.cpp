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
    int matrix[3][3][2] = {{{1,2},{1,2},{1,2}}
                    {{1,2},{1,2},{1,2}},
                    {{1,2},{1,2},{1,2}}};

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
    // We use it to tell when we don't know how much we are going to need

//How do you search an array
    //std::find can help you find things in an array?

//How do you sort an array
    // Bubble sort: takes two numbers and then compares them, it takes the two numbers and checks which one is smallest and keps going to check 2 numbers
    // Then you repeat it again and again until its sorted from least to greatest
    // 0. length of the loop
    // 1. Loop array
    // 2. select second item 
    // 3. Compare it to first item
    // 4. if i-1 is bigger switch them

int nums[] = {5, 24, 1, 0, 66, 47, 3}; 
int main(){
    int length = size(nums);
    for(int j = 0; j<length; j++){
        for(int i=1; i < (length); i++){
            //cout << nums[i] << endl;
            if(nums[i] < nums[i-1]){
                int swap = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = swap;
            }
        }
    }
    for(int i = 0; i < length; i++){
        cout << nums[i] << ", ";
    }
    return 0;
}


//How do you make a multi-dimensional array
    //Do matrix [# of rows][# of columns] = {{}{}{}}