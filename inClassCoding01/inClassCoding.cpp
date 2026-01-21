#include <iostream>
using namespace std;

void greet();
int add(int a, int b);
double area(double width, double height);

int main()
{
    cout << "Ex 1" << endl;
    {
        int x = 5;
        int y = 7;
        cout << endl;
        cout << x + y << " " << x * y;
        cout << endl;
    }
    cout << endl;

    cout << "Ex 2: basic input output" << endl;
    {
        int age;
        cout << "Enter your age: ";
        cin >> age;
        cout << "You entered: " << age << endl;
    }
    cout << endl;

    cout << "Ex 3: varaibles, data types, type casting" << endl;
    {
        int a = 10;
        double b = 3.5;
        double result = (double)a / b;

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "Result of a / b = " << result << endl;
    }
    cout << endl;

    cout << "Ex 4: operations and expressions" << endl;
    {
        int x = 8;
        int y = 3;
        cout << "x + y = " << x + y << endl;
        cout << "x - y = " << x - y << endl;
        cout << "x * y = " << x * y << endl;
        cout << "x / y = " << x / y << endl;
        cout << "x % y = " << x % y << endl;
    }
    cout << endl;

    cout << "Ex 5: if else" << endl;
    {
        int temp = 30;

        if (temp > 25)
            cout << "It's hot outside!" << endl;
        else
            cout << "It's cool outside." << endl;
    }
    cout << endl;

    cout << "Ex 6: switch statements" << endl;
    {
        int day = 3;

        switch(day) {
            case 1: cout << "Monday"; break;
            case 2: cout << "Tuesday"; break;
            case 3: cout << "Wednesday"; break;
            default: cout << "Invalid day"; break;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Ex 7: for loops" << endl;
    {
        for (int i = 1; i <= 5; i++) {
            cout << "Count: " << i << endl;
        }
    }
    cout << endl;

    cout << "Ex 8: functions with no params" << endl;
    {
        greet();
    }
    cout << endl;

    cout << "Ex 9: functions with params" << endl;
    {
        int result = add(4, 6);
        cout << "Sum = " << result << endl;
    }
    cout << endl;

    cout << "Ex 10: functions w return value and user inputs" << endl;
    {
        double w, h;
        cout << "Enter width: ";
        cin >> w;
        cout << "Enter height: ";
        cin >> h;

        cout << "Area = " << area(w, h) << endl;
    }
    cout << endl;
    return 0;
}

void greet() {
    cout << "Hello from a function!" << endl;
}

int add(int a, int b) {
    return a + b;
}

double area(double width, double height) {
    return width * height;
}