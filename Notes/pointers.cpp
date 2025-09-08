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
- We compare pointers to see which ones location comes sooner. (Comparing location not value)
- This helps us make sure that our pointer isnt a null value
What is dynamic memory allocation?
- allows you to request memory only when needed and release it when your done
What is the Stack?
- An area of memory used for managing function calls, local variables, and control flow. It is managed by the compiler for quick allocation of memory.
What is the Heap?
- An area of memory used for dynamic memory. Stores data is the size is unknown at the time of compiling. Memory must be manually managed by the program. Used for flexible long-lived storage of complex data sturctures, objects, and large files.
What are smart pointers?
- make it so we dont have to delete pointers and we can use it as variables
1. unique pointers
- owns that piece of the memory and nothing else can use it
2. shared pointer
- can have multiple pointers pointing at the same thing



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

int capacity = 5;
int* sanity = new int[capacity];
int entries = 0;


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
    cout << (pnum > pday) << endl;
    if(pnum != nullptr){ // checks to see if the pointer is empty
        cout << *pnum << endl;
        pnum++;

    }
    cout << *pnum << endl;

    while (true){
        cout << "Number: ";
        cin >> sanity[entries];
        if(cin.fail()) break;
        entries++;
        if(entries == capacity){
            capacity += 5;
            int* temp = new int[capacity];
            for(int i = 0; i < entries; i++)
                temp[i] = numbers[i];
            delete[] sanity;
            sanity = temp;
        }
    }

    for(int i = 0; i < entries; i++)
        cout << sanity[i] << endl;
    
    delete[] sanity;

    return 0;
}
