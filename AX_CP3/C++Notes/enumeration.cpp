// AX Enumeration Notes

/*

QUESTIONS:
What is enumeration?
- user-defined data type that consists of a set of named integral constants, known as enumerators
How do you build enumeration?
-Shown below
How do we display our enumerator? 
- Shown below
Why does it matter that enumerators are constants?
- since they can't be changed once you have manually typed it in
What is the default beginning enumerator? 
- It starts at zero until you tell it otherwise
How do you give a different default value?
- you make it = to whatever default value you want
What is a strongly typed enumerator?
- You use enum class and then the name in uppercase
How are strongly typed enumerators different from a normal one?
- Strongly typed ones can't be duplicated

*/

#include <iostream>

using namespace std;
enum Menu{
    Find = 1,
    Battle,
    Heal
};

enum Menu{
    List = 1,
    Add,
    Update
};

//these lists cant be duplicated
enum class Operation{
    List = 1,
    Add,
    Update
};

int main(){
    int input;

    // user instructure
    cout <<
    "1: List invoices" << endl <<
    "2: Add invoices" << endl <<
    "3: Update invoices" << endl <<
    "Select: ";
    cin >> input;

    // 
    if (input == static_cast<int>(Operation::List)){
        cout << "List invoices";
    }else if(input == Menu::Battle){
        cout << "I haven't built this yet" << endl;
    }else if(input == Menu::Heal){
        cout << "Suprisingly I haven't built this either" << endl;
    }else{
        cout << "Womp womp not an option." << endl;
    }

    return 0;
}