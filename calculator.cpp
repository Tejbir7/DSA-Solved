#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;

    cout << "===== Simple Calculator =====" << endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;

        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed!" << endl;
            } else {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endl;
            }
            break;

        default:
            cout << "Error: Invalid operator!" << endl;
            break;
    }

    return 0;
}
