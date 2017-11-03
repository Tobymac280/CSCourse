#include <iostream>
using namespace std;

/* Output works 100% */

// Takes in an integer pointer and an integer -- for the array and size, respectively -- and then returns an integer pointer
int* reverseOrder(int *arr, int SIZE){
    int *newArr = new int[SIZE*2];
    
    for(int i = 0; i < SIZE; i++){ // iterate backwards through the first array
        // Start the new array's values at the end of the old arrays values and go backwards as the iteration gets higher
        newArr[i] = arr[SIZE - i - 1]; // store the last to first value of the old array in the new array
    }
    
    for(int i = SIZE; i < SIZE*2; i++){ // start at where the last loop left off and set all remaining values to 0
        newArr[i] = 0;
    }
    
    return newArr; // returns the memory location of the first element of the array
}

int main(){
    int size;
    int *arr;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    arr = new int[size]; // allocate an array of the specified size
    
    for(int i = 0; i < size; i++){
        cout << "Enter value " << (i+1) << ": ";
        cin >> *(arr+i); // take in the value of the current array index by doing memory math and dereferencing
    }
    
    arr = reverseOrder(arr, size); // passes in the size and the address for the first element in the allocated array
    
    // print the message and the starting brace
    cout << "The reversed array is: [";
    for(int i = 0; i < size*2; i++){
        if(i == size*2-1){ // if it's on the last iteration
            // print the last element without a comma and a space after it
            cout << *(arr + i);
        }
        else{
            // print the current number
            cout << *(arr + i) << ", "; // the current element and the a comma and a space
        }
    }
    // print the ending brace
    cout << "]" << endl;
    
    delete [] arr; // give the memory back to the heap
    arr = nullptr; // set it back to null to avoid null pointer problems
    
    return 0;
}

