#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
        cout << "Point(" << x << ", " << y << ") created." << endl;
    }
    ~Point() {
        cout << "Point(" << x << ", " << y << ") destroyed." << endl; }
};
class Rectangle {
private:
    Point topLeft, bottomRight;
public:
    Rectangle(int x1, int y1, int x2, int y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {
        cout << "Rectangle created with top-left (" << x1 << ", " << y1 << ") and bottom-right (" << x2 << ", " << y2 << ")." << endl; }
    ~Rectangle() {
        cout << "Rectangle destroyed." << endl; }
};
int main() {
    int x1, y1, x2, y2;
    cout << "Enter coordinates of the top-left corner (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of the bottom-right corner (x2, y2): ";
    cin >> x2 >> y2;
    Rectangle rect(x1, y1, x2, y2);
    return 0;
}
