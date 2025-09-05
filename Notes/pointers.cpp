// AX Pointers notes

/*
QUESTIONS:
What is a pointer?
- A specific variable that holds a specific address instead of specific info assumed
Why do we use pointers?
- Efficiency of space(since lists automatically use pointers)
How do I create a pointer
-int* pnum = &num;(below ex)
What is indirection or de-referencing?
- This is where you do *pnum to go back to what it was before
What are constant pointers? How are the different types used?
- constant pointer 
- 1st level is where the value of the item cant be changed
- 2nd level you can change the value but not the location
- 3rd level "const int* const pmonth = &month;" the value and location cant change
How do you pass a pointer into a function?
- You pass a pointer by focusing on the array and the size in the function.
Why would you pass a pointer to a function?
- Inside of your function you need to access info that is large( it saves space aswell)
How do you compare pointers?
What is dynamic memory allocation?
What is the Stack?
What is the Heap?
What are smart pointers?



*/

#include <iostream>

using namespace std;

int numbers[] = {4, 2, 6, 8, 14, 24, 65};
void divide(int* list, int size){// use the & when using pointer values
    for(int i; i < size; i++){
        list[i] = list[i]/2;
        cout << list[i] << endl;


    }
    cout << "This is my number list:" << *list << endl;
}

int main(){
    // pointers hold adress instead of info
    int num = 4;
    int* pnum = &num;
    int day = 5;
    int month = 9;
    const double pi = 3.141592;
    const double gpa = 3.99999;

    *pnum = 8;

    // Constant pointers
    const double* ppi = &pi;
    ppi = &gpa;

    int* const pday = &day;//you can change the value but not the location being pointed at
    *pday = 6;
    //*pday = &num

    const int* const pmonth = &month; // location and value cant change
    
    
    cout << "The number is " << num << endl;
    cout << "The location of num is " << pnum << endl;
    divide(numbers, size(numbers));


    return 0;
}
