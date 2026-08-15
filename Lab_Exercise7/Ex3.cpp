#include <iostream>
#include <string>
using namespace std;

class String {
private:
    string value;
public:
    String() : value("") {}
    String(const string &str) : value(str) {}
    String operator+(const String &other) const {
        return String(value + other.value); }
    void display() const {
        cout << value << endl; }
    void setValue(const string &str) {
        value = str; }
    string getValue() const {
        return value; }
};

int main() {
    String str1;
    String str2;
    String str3("Hello");
    String str4("World");
    String str5 = str3 + String(" ") + str4;
    cout << "String 1 (uninitialized): ";
    str1.display();
    cout << "String 2 (uninitialized): ";
    str2.display();
    cout << "String 3: ";
    str3.display();
    cout << "String 4: ";
    str4.display();
    cout << "Concatenated String: ";
    str5.display();
    return 0;
}
