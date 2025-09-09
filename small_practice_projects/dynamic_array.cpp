// AX Dynamic Array Program

/*

INSTRUCTIONS:
Write a program that asks the user to enter colors until they can't think of anymore. 

Start your array with only 5 spaces. Continue to increase the size of the array as your user hits the array cap. 

THEN, print out each of the inputs they gave you!

*/
// I still need to implement the Correct and effective use of smart pointers (std::unique_ptr, std::shared_ptr) where appropriate. Demonstrates understanding of memory management.

#include <iostream>
#include <string>

using namespace std;

int main(){
    int capacity = 5;
    string* colors = new string[capacity];
    int entries = 0;
    string input;

    while (true){
        cout << "Color(click enter if you don't know anymore): ";
        getline(cin, input);
        
        if(input.empty()) break; // if they dont know anymore
        
        if(entries == capacity){
            // if the amount of space in the array are all used up it will give it more space
            capacity += 5;
            string* temp = new string[capacity];
            for(int i = 0; i < entries; i++){
                temp[i] = colors[i];
            }
            delete[] colors;
            colors = temp;
        }

        colors[entries] = input;
        entries++;
    }
    //prints all the colors
    cout << "Here are all of the colors you enteres:" << endl;
    for(int i = 0; i < entries; i++){
        cout << colors[i] << endl;
    }

    delete[] colors;
    return 0;
}