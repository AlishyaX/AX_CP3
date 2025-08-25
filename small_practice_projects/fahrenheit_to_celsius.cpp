// AX farenheit to celsius

#include <iostream>
using namespace std;

int main(){
    double tempf;
    cout << "Tell me a temperature in Farenheit: ";
    cin >> tempf;
    double celsius = (tempf - 32)* 5/9;
    std::cout << tempf << " degrees Farenheit is " << celsius << " degrees Celsius" << endl;
    return 0;
}
