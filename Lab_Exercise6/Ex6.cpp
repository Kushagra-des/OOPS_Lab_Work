#include <iostream>
#include <string>
using namespace std;

class Example {
private:
    int number;
    string text;

public:
    Example() : number(0), text("Default") {
        cout << "Default constructor called." << endl;
    }
    Example(int n) : number(n), text("Default") {
        cout << "Constructor with one parameter called. Number: " << number << endl;
    }
    Example(int n, string t) : number(n), text(t) {
        cout << "Constructor with two parameters called. Number: " << number << ", Text: " << text << endl;
    }
    void display() const {
        cout << "Number: " << number << ", Text: " << text << endl; }
};
int main() {

    Example ex1;
    ex1.display();
    Example ex2(42);
    ex2.display();
    Example ex3(42, "Custom Text");
    ex3.display();
    return 0;
}
