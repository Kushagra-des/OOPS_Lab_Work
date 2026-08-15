#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidOperatorException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Operator. Use {(+) or (-) or (*) or (/)}";
    }
};

class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Division by Zero is NOT ALLOWED.";
    }
};

int calculate(int num1, char op, int num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
                throw DivisionByZeroException();
            return num1 / num2;
        default:
            throw InvalidOperatorException();
    }
}

int main() {
    int a, b;
    char op;

    cout << "Enter the First Number: ";
    cin >> a;

    cout << "\nEnter the Second Number: ";
    cin >> b;

    cout << "\nEnter the Operator ((+) or (-) or (*) or (/)): ";
    cin >> op;

    try {
        int result = calculate(a, op, b);
        cout << "\nResult: " << result << endl;
    } catch (const exception& e) {
        cerr << "\nError: " << e.what() << endl;
    }

    return 0;
}
