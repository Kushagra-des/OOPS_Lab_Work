#include <iostream>
#include <limits>
#include <cmath>
using namespace std;
class DB;
class DM {
private:
    int meters;
    float centimeters;
public:
    void inputDM() {
        cout << "Enter distance in meters: ";
        while (true) {
            cin >> meters;
            if (meters < 0) {
                cout << "Distance cannot be negative. Please enter a valid distance in meters: ";
            } else {
                break; }}
        cout << "Enter distance in centimeters: ";
        while (true) {
            cin >> centimeters;
            if (centimeters < 0) {
                cout << "Distance cannot be negative. Please enter a valid distance in centimeters: ";
            } else {
                break;}}}
    void displayDM() const {
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
    friend DM addDistance(DM, DB);
};
class DB {
private:
    int feet;
    float inches;
public:
    void inputDB() {
        cout << "Enter distance in feet: ";
        while (true) {
            cin >> feet;
            if (feet < 0) {
                cout << "Distance cannot be negative. Please enter a valid distance in feet: ";
            } else {
                break; }}
        cout << "Enter distance in inches: ";
        while (true) {
            cin >> inches;
            if (inches < 0) {
                cout << "Distance cannot be negative. Please enter a valid distance in inches: ";
            } else {
                break; }}}
    void displayDB() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
    friend DB addDistance(DB, DM);
};
const double METER_TO_FEET = 3.28084;
const double INCH_TO_CM = 2.54;
const double CM_TO_INCH = 0.393701;
const double FEET_TO_METER = 0.3048;
DM addDistance(DM d, DB b) {
    float totalCentimeters = b.feet * 12 * INCH_TO_CM + b.inches * INCH_TO_CM;
    int totalMeters = static_cast<int>(totalCentimeters) / 100;
    totalCentimeters = totalCentimeters - (totalMeters * 100);
    int metersResult = d.meters + totalMeters;
    float centimetersResult = d.centimeters + totalCentimeters;
    if (centimetersResult >= 100) {
        metersResult += static_cast<int>(centimetersResult) / 100;
        centimetersResult = fmod(centimetersResult, 100); }
    DM result;
    result.meters = metersResult;
    result.centimeters = centimetersResult;
    return result;
}
DB addDistance(DB b, DM d) {
    float totalFeet = d.meters * METER_TO_FEET;
    float totalInches = d.centimeters * CM_TO_INCH;
    totalFeet += totalInches / 12;
    totalInches = fmod(totalInches, 12);
    int feetResult = b.feet + static_cast<int>(totalFeet);
    float inchesResult = b.inches + totalInches;
    if (inchesResult >= 12) {
        feetResult += static_cast<int>(inchesResult) / 12;
        inchesResult = fmod(inchesResult, 12); }
    DB result;
    result.feet = feetResult;
    result.inches = inchesResult;
    return result; }
int main() {
    DM distance1, distance2;
    DB distance3, distance4;
    int choice;
    cout << "Enter details for the first distance (in meters & centimeters):\n";
    distance1.inputDM();
    cout << "Enter details for the second distance (in feet & inches):\n";
    distance3.inputDB();
    cout << "Enter details for the third distance (in meters & centimeters):\n";
    distance2.inputDM();
    cout << "Enter details for the fourth distance (in feet & inches):\n";
    distance4.inputDB();
    do {
        cout << "\n------ Menu ------\n";
        cout << "1. Add two distances and display the result in meters & centimeters\n";
        cout << "2. Add two distances and display the result in feet & inches\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            DM resultDM = addDistance(distance1, distance3);
            cout << "Resulting distance in meters & centimeters: ";
            resultDM.displayDM();
            break; }
        case 2: {
            DB resultDB = addDistance(distance2, distance4);
            cout << "Resulting distance in feet & inches: ";
            resultDB.displayDB();
            break; }
        case 3:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid option! Please select a valid option.\n";
            break; }
    } while (choice != 3);
    return 0; }
