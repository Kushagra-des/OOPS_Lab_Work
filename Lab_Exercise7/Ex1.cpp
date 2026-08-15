#include <iostream>
#include<math.h>
#include<cstdlib>
using namespace std;

class Distance {
private:
    int feet;
    double inches;
    void normalize() {
        if (inches >= 12) {
            feet += static_cast<int>(inches / 12);
            inches = fmod(inches, 12);
        } else if (inches < 0) {
            feet -= static_cast<int>(abs(inches) / 12 + 1);
            inches = 12 - fmod(abs(inches), 12); } }
public:
    Distance(int f = 0, double i = 0.0) : feet(f), inches(i) {
        normalize(); }
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl; }
    Distance operator+(const Distance &d) const {
        return Distance(feet + d.feet, inches + d.inches); }
    Distance operator-(const Distance &d) const {
        double totalInches1 = feet * 12 + inches;
        double totalInches2 = d.feet * 12 + d.inches;
        double resultInches = totalInches1 - totalInches2;
        return Distance(static_cast<int>(resultInches / 12), fmod(resultInches, 12)); }
    Distance &operator+=(const Distance &d) {
        feet += d.feet;
        inches += d.inches;
        normalize();
        return *this; }
    Distance &operator-=(const Distance &d) {
        double totalInches1 = feet * 12 + inches;
        double totalInches2 = d.feet * 12 + d.inches;
        double resultInches = totalInches1 - totalInches2;
        feet = static_cast<int>(resultInches / 12);
        inches = fmod(resultInches, 12);
        normalize();
        return *this; }
    bool operator>(const Distance &d) const {
        return (feet * 12 + inches) > (d.feet * 12 + d.inches); }
    bool operator<(const Distance &d) const {
        return (feet * 12 + inches) < (d.feet * 12 + d.inches); }
};

int main() {
    Distance d1(5, 11);
    Distance d2(3, 6);
    cout << "Distance 1: ";
    d1.display();
    cout << "\nDistance 2: ";
    d2.display();
    Distance d3 = d1 + d2;
    cout << "\nAfter addition: ";
    d3.display();
    Distance d4 = d1 - d2;
    cout << "\nAfter subtraction: ";
    d4.display();
    d1 += d2;
    cout << "\nAfter += operation: ";
    d1.display();
    d1 -= d2;
    cout << "\nAfter -= operation: ";
    d1.display();
    cout << "\nDistance 1 > Distance 2: " << (d1 > d2 ? "true" : "false") << endl;
    cout << "\nDistance 1 < Distance 2: " << (d1 < d2 ? "true" : "false") << endl;
    return 0;
}
