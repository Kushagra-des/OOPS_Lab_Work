#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    Rectangle() {
        length = 0;
        width = 0; }

    float calculatePerimeter() {
        return 2 * (length + width); }

    float calculateArea() {
        return length * width; }

    void getValuesFromUser() {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width; }

    void displayValues() {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "Area: " << calculateArea() << endl; }
};

int main() {
    Rectangle rect;
    rect.getValuesFromUser();
    rect.displayValues();
    return 0;
}
