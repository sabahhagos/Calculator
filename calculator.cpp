#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to perform arithmetic operations
double performOperation(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                cout << "Error: Division by zero!" << endl;
                exit(1);
            }
        default:
            cout << "Error: Invalid operation!" << endl;
            exit(1);
    }
}

// Function to perform linear regression
double linearRegression(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size()) {
        cout << "Error: Size mismatch for input data!" << endl;
        exit(1);
    }

    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    return slope;
}

// Function to display menu and get user input
void displayMenu() {
    cout << "Choose operation:" << endl;
    cout << "1. Arithmetic Operation" << endl;
    cout << "2. Linear Regression" << endl;
    cout << "Enter your choice (1-2): ";
}

int main() {
    double num1, num2, result;
    char op;

    // Display menu
    displayMenu();

    // Get user input
    int choice;
    cin >> choice;

    // Validate choice
    if (choice != 1 && choice != 2) {
        cout << "Error: Invalid choice!" << endl;
        return 1;
    }

    if (choice == 1) {
        // Get numbers from user for arithmetic operation
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        // Get arithmetic operation from user
        cout << "Enter operation (+, -, *, /): ";
        cin >> op;

        // Perform arithmetic calculation
        result = performOperation(num1, num2, op);

        // Display result
        cout << "Result: " << result << endl;
    } else if (choice == 2) {
        // Placeholder for linear regression
        vector<double> x;
        x.push_back(1);
        x.push_back(2);
        x.push_back(3);
        x.push_back(4);
        x.push_back(5);

        vector<double> y;
        y.push_back(2);
        y.push_back(4);
        y.push_back(5);
        y.push_back(4);
        y.push_back(5);


        // Perform linear regression
        double slope = linearRegression(x, y);

        // Display result
        cout << "Slope of the regression line: " << slope << endl;
    }

    return 0;
}
