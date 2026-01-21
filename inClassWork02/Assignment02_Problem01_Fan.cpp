// Task 1: Compile, run and observe
// 1. Compile:
// 2. Use this test case:
// o Length: 5
// o Codes: 8 5 12 12 15
// Expected message: HELLO
// 3. Observe the issues:
// o Wrong letters?
// o Extra character?
// o Problems when length is 0 or negative?

cpp#include <iostream>
#include <string>
using namespace std;

int main() {  
    cout << "How many numbers are in the secret sequence? ";
    cin >> length;
    
    while(length <= 0) {
        cout << "Length must be longer than 0" << endl;
        cout << "Re-enter the number: ";
        cin >> length;
    }
    
    string message = "";

    for (int i = 0; i < length; i++) {
        int code;
        cout << "Enter the coded number: "
        cin >> code;
    }            
    
    return 0;
}