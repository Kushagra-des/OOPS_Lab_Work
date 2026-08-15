#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor of global object called." << endl;
    }

    ~MyClass() {
        cout << "Destructor of global object called." << endl;
    }
};
MyClass globalObject;

int main() {
    cout << "Inside main function." << endl;

    return 0;
}
