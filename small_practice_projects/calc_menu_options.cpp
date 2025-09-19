// AX Calculator Menu Options Program
 /*
 
 INSTRUCTIONS:
Write a program that creates a user menu for a basic calculator using enumeration in C++. The calculator should be able to perform addition, subtraction, multiplication, and division. The program should display a menu of options, allow the user to select an operation, input two numbers, perform the calculation, and display the result. The program must continue to run till the user chooses to exit and have proper input handling. 

OUTPUT EXAMPLE: 

Calculator Menu:

Addition
Subtraction
Multiplication
Division
Exit
Enter your choice (1-5): 1 Enter first number: 10 Enter second number: 5 Result: 10 + 5 = 15
 
 
 */

 #include <iostream>

 using namespace std;

 enum Menu{
    Add = 1,
    Sub,
    Mult,
    Div,
    Exit
};

void addition(){
    float add1;
    float add2;

    cout << "Enter a number: ";
    cin >> add1;
    cout << "Enter another number: ";
    cin >> add2;
    
    cout << "The output is: " << (add1+add2) << endl;
}

void subtraction(){
    float sub1;
    float sub2;

    cout << "Enter a number: ";
    cin >> sub1;
    cout << "Enter another number: ";
    cin >> sub2;
    
    cout << "The output is: " << (sub1-sub2) << endl;
}

void multiplication(){
    float mult1;
    float mult2;

    cout << "Enter a number: ";
    cin >> mult1;
    cout << "Enter another number: ";
    cin >> mult2;
    
    cout << "The output is: " << (mult1*mult2) << endl;
}

void division(){
    float div1;
    float div2;

    cout << "Enter a number: ";
    cin >> div1;
    cout << "Enter another number: ";
    cin >> div2;
    
    cout << "The output is: " << (div1/div2) << endl;
}



 int main(){
    int input;


    
    cout <<
    "Calculator Menu:"
    "\n1. Addition" << endl <<
    "2. Subtraction" << endl <<
    "3. Multiplication" << endl <<
    "4. Division" << endl <<
    "5. Exit" << endl <<
    "Select: ";
    cin >> input;

    while(true){
        if (input == Menu::Add){
            addition;
        }else if(input == Menu::Sub){
            subtraction;
        }else if(input == Menu::Mult){
            multiplication;
        }else if(input == Menu::Div){
            division;
        }else if(input == Menu::Exit){
            cout << "Thank you for using my Calculator!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }


    return 0;
 }