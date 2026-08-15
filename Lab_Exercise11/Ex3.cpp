#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName;
    char middleInitial;
    unsigned long empNumber;
    char moreData;
    string filename = "employees.txt";

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }

    do {
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter middle initial: ";
        cin >> middleInitial;
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Enter employee number: ";
        cin >> empNumber;

        outFile << firstName << ' ' << middleInitial << ' ' << lastName << ' ' << empNumber << endl;

        cout << "Do you want to enter another employee? (y/n): ";
        cin >> moreData;

    } while (moreData == 'y' || moreData == 'Y');

    outFile.close();

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    cout << "\nEmployee Data from File:\n";
    cout << "-----------------------------\n";

    while (inFile >> firstName >> middleInitial >> lastName >> empNumber) {
            cout << "First Name: " << firstName
             << ", Middle Initial: " << middleInitial
             << ", Last Name: " << lastName
             << ", Employee Number: " << empNumber << endl;

    inFile.close();

    }

    return 0;
}
