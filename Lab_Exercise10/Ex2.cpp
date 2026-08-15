#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    int choice;
    double temp, convertedTemp;

    cout << "Temperature Converter Program\n";
    cout << "1. Convert Celsius to Fahrenheit\n";
    cout << "2. Convert Fahrenheit to Celsius\n";
    cout << "Enter Your Choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter Temperature in Celsius: ";
        cin >> temp;

        if (temp < -273.15) {
            cout << "Error: Temperature below Absolute Zero (-273.15 degree C) is NOT VALID.\n";
        } else {
            convertedTemp = celsiusToFahrenheit(temp);
            cout << temp << " degree C is " << convertedTemp << " degree F\n";
        }

    } else if (choice == 2) {
        cout << "Enter Temperature in Fahrenheit: ";
        cin >> temp;

        if (temp < -459.67) {
            cout << "Error: Temperature below Absolute Zero (-459.67 degree F) is NOT VALID.\n";
        } else {
            convertedTemp = fahrenheitToCelsius(temp);
            cout << temp << " degree F is " << convertedTemp << " degree C\n";
        }

    } else {
        cout << "Invalid Choice. Please Run the Program again and Select (1 or 2).\n";
    }

    return 0;
}
