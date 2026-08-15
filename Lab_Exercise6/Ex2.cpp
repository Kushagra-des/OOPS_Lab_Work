#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor called! Object is created." << endl; }
    ~MyClass() {
        cout << "Destructor called! Object is deleted." << endl; }
};
int main() {
    MyClass* obj = nullptr;
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create object dynamically\n";
        cout << "2. Delete object dynamically\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (obj == nullptr) {
                    obj = new MyClass;
                } else {
                    cout << "Object is already created!\n"; }
                break;
            case 2:
                if (obj != nullptr) {
                    delete obj;
                    obj = nullptr;
                } else {
                    cout << "Error: No object to delete. Create an object first.\n"; }
                break;
            case 3:
                cout << "Exiting the program.\n";
                if (obj != nullptr) {
                    delete obj; }
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n"; } }
    return 0;
}
