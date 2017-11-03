#include <iostream>
using namespace std;

/* Ouput matches 100% */

int doSomething(int *x, int *y){
    int temp = *x; // dereference the pointer's location
    *x = *y * 10; // same operation, just dereferencing values
    *y = temp * 10;
    return *x + *y; // derefernce the values and add them together, then return the result
}

int main(){
    int x, y, result;
    
    cout << "Please enter a value for x: ";
    cin >> x;
    
    cout << "Please enter a value for y: ";
    cin >> y;
    
    // get the result and store it
    result = doSomething(&x, &y); // pass by address -- since it takes pointers
    
    cout << "The result of the function was " << result << endl;
    
    // show the values of x and y
    cout << "x's current value is " << x << endl;
    cout << "y's current value is " << y << endl;
    
    return 0;
}
