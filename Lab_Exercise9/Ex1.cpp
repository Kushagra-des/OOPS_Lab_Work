#include <iostream>
using namespace std;

class Shape {
protected:
    double x, y;
public:
    void get_data(double a, double b = 0) {
        x = a;
        y = b;
    }

    virtual void display_area() = 0;
};

class Triangle : public Shape {
public:
    void display_area()
    override {
        cout << "\nArea of Triangle: " << 0.5 * x * y << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area()
    override {
        cout << "\nArea of Rectangle: " << x * y << endl;
    }
};

class Circle : public Shape {
public:
    void display_area()
    override {
        cout << "\nArea of Circle: " << 3.14 * x * x << endl;
    }
};

int main() {
    Shape* shapePtr = nullptr;
    int choice;
    double val2, val3;

    cout << "Select Shape to Calculate Area:\n";
    cout << "\n1. Triangle\n";
    cout << "2. Rectangle\n";
    cout << "3. Circle\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Triangle t;
            shapePtr = &t;
            cout << "\nEnter Base Value of the Triangle Shape : ";
            cin >> val2;
            cout << "Enter Height Value of the Triangle Shape : ";
            cin >> val3;
            shapePtr->get_data(val2, val3);
            break;
        }
        case 2: {
            Rectangle r;
            shapePtr = &r;
            cout << "\nEnter Length Value of the Rectangle Shape : ";
            cin >> val2;
            cout << "Enter Breadth Value of the Rectangle Shape : ";
            cin >> val3;
            shapePtr->get_data(val2, val3);
            break;
        }
        case 3: {
            Circle c;
            shapePtr = &c;
            cout << "\nEnter Radius Value of the Circle Shape : ";
            cin >> val2;
            shapePtr->get_data(val2);
            break;
        }
        default:
            cout << "Invalid Choice you have Entered. Please run the Program Again.\n";
            return 1;
    }
    shapePtr->display_area();
    return 0;
}
