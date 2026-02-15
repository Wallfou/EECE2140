#include <iostream>
#include "../include/Queue.h"
using namespace std;

int main() {
    Queue q(5);
    int choice, value;
    do {
        cout << "\nmenu\n";
        cout << "1: enqueue\n";
        cout << "2: dequeue\n";
        cout << "3: peek\n";
        cout << "4: size\n";
        cout << "5: print\n";
        cout << "6: clear\n";
        cout << "7: exit\n";
        cout << "Input: ";
        cin >> choice;

        try {
            switch(choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    q.enqueue(value);
                    break;
                
                case 2:
                    cout << "Removed value: " << q.dequeue() << endl;
                    break;

                case 3:
                    cout << "Peek: " << q.peek() << endl;
                    break;

                case 4:
                    cout << "Size of queue: " << q.size() << endl;
                    break;

                case 5:
                    q.printQueue();
                    break;

                case 6:
                    q.clear();
                    cout << "cleraed" << endl;
                    break;
            }
        }
        catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while(choice != 7);
    return 0;
}
