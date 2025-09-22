// AX Calculator Menu Options Program


 #include <iostream>

 using namespace std;

 // Enumerator Menu
 enum Menu{
    Add = 1,
    Sub,
    Mult,
    Div,
    Exit
};

// All my functions for each equation
void addition(){
    float add1;
    float add2;

    cout << "Enter a number: ";
    cin >> add1;
    cout << "Enter another number: ";
    cin >> add2;
    
    cout << "Result: "<< add1 << " + " << add2 << " = "<< (add1+add2) << endl;
}

void subtraction(){
    float sub1;
    float sub2;

    cout << "Enter a number: ";
    cin >> sub1;
    cout << "Enter another number: ";
    cin >> sub2;
    
    cout << "Result: "<< sub1 << " - " << sub2 << " = "<< (sub1-sub2) << endl;
}

void multiplication(){
    float mult1;
    float mult2;

    cout << "Enter a number: ";
    cin >> mult1;
    cout << "Enter another number: ";
    cin >> mult2;
    
    cout << "Result: "<< mult1 << " x " << mult2 << " = "<< (mult1*mult2) << endl;
}

void division(){
    float div1;
    float div2;

    cout << "Enter a number: ";
    cin >> div1;
    cout << "Enter another number: ";
    cin >> div2;
    
    // If the user enters 0
    if (div1 == 0){
        cout << "You can't divide something by zero!";
    } else{
    cout << "Result: "<< div1 << " / " << div2 << " = "<< (div1/div2) << endl;
    };
}



 int main(){
    int input;
    cout << "Welcome to Your Calculator!" << endl;

    // Keeps running until they exit
    while(true){
        cout <<
        "\n\nCalculator Menu:"
        "\n1. Addition" << endl <<
        "2. Subtraction" << endl <<
        "3. Multiplication" << endl <<
        "4. Division" << endl <<
        "5. Exit" << endl <<
        "Select(1-5): ";

        while(!(cin >> input)){
            cout << "Please enter a number option" << endl;
            cin.clear();
            cin.ignore();
        }
        

    
        if (input == Menu::Add){
            addition();
        }else if(input == Menu::Sub){
            subtraction();
        }else if(input == Menu::Mult){
            multiplication();
        }else if(input == Menu::Div){
            division();
        }else if(input == Menu::Exit){
            cout << "Thank you for using my Calculator!" << endl;
            break;
        }else{
            cout << "That isn't an option. Try Again" << endl;
        }
    }


    return 0;
 }