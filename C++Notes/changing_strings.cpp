// AX Chainging Strings Notes
/*


QUESTIONS:
How do I get a substring from within a string?
    - Start with substr(starting position, number of characters).
    - I can make a string upper case, lower case, and make it go higher or lower in characters

How do I create an escape character in C++
    - By doing \"   to print " 
    - By doing \t tabs it
    - By doing \n to make it on a new line
How do I convert a string to another data type?
    - You can convert a string to another data type by using std::stoi.
What is a raw string and when would I use it?
    - A raw string is useful for many escape characters. Instead you can do R"(and that what you want to print with howerever many amout of "'s)"
 


*/
#include <iostream>
#include <string>
using namespace std;

string name = "alishya xavier";
string sentence = "The quick brown fox jumps over the lazy dog!";

int main(){
    // how to find the spaces
    auto index = name.find(' ');
    string first_name = name.substr(0,index);
    string last_name = name.substr(index + 1);
    first_name[0] = toupper(first_name[0]);
    cout << first_name << endl << last_name;
    int length = size(sentence);
    for(int i=0;i<length; i++){
        if(isspace(sentence[i])){
            sentence[i] = '_';
        }else if(isupper(sentence[i])){
            sentence[i] = tolower(sentence[i]);
        }else{
            sentence[i] = char((int(sentence[i]) + 4) % 26 + 97);
        }
    }
    cout << sentence << endl;

    cout << "This is a \"Question\". . .  .I think";
    return 0;
}