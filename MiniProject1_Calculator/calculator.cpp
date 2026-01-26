#include <iostream>
#include <limits>
using namespace std;

int main() {
	char operation;
	double num1, num2, output;
	
	cout << "CALCULATOR!!!" << endl;
	cout << "Supports + - * / %" << endl;
	cout << "Type q to quit" << endl;

	while (true) {
		cout << "\nEnter operation + - * / % or q: ";
		cin >> operation;

		if (operation == 'q') {
			cout << "BYE BYE!" << endl;
			break;
		}

		if (operation != '+' &&
		    operation != '-' &&
		    operation != '/' &&
		    operation != '*' &&
		    operation != '%') {
			cout << "Invalid operation" << endl;
			cin.clear();
			continue;
		}
		
		cout << "Enter num1: " << endl;
		cin >> num1;
		
		cout << "Enter num2: " << endl;
		cin >> num2;

		switch (operation) {
			case '+':
				output = num1 + num2;
				cout << "Result: " << num1 << " + " << num2 << " = " << output << endl;
				break;
			case '-':
				output = num1 - num2;
				cout << "Result: " << num1 << " - " << num2 << " = " << output << endl;
				break;
			case '*':
				output = num1 * num2;
				cout << "Result: " << num1 << " * " << num2 << " = " << output << endl;
				break;
			case '/':
				if (num2 == 0) {
					cout << "Cannot divide by zero" << endl;
				}	
				else {
					output = num1 / num2;
					cout << "Result: " << num1 << " / " << num2 << " = " << output << endl;
				}
				break;
			case '%':
				if (num2 == 0) {
					cout << "Cannot modulus by zero" << endl;
				}
				else {
					output = (int)num1 % (int)num2;
					cout << "Result: " << num1 << " % " << num2 << " = " << output << endl;
				}
				break;
			default:
				cout << "Invalid operations" << endl;
				break;
		}
	}
	return 0;
}
