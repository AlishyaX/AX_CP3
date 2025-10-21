// AX smart pointers

#include <iostream>
#include <memory>

using namespace std;

int main(){
    // unique pointers
    unique_ptr <int> x(new int); // this is making a variable
    auto y =  make_unique<int>();
    *x = 10;
    *y = 7;
    cout << *x << endl;

    // shared pointers(clean up after themselves so you dont have to delete them)
    auto z = make_shared<int>();
    *z = 4;


    cout << *x << ", " << *y << ", " << *z << endl;

    return 0;
}