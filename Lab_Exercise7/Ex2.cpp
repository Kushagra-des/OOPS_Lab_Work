#include <iostream>
#include <stdexcept>

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp; }
        return a;  }
    void simplify() {
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator; } }
public:
    Rational(int num = 0, int denom = 1) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero."); }
        numerator = num;
        denominator = denom;
        simplify(); }
    void getInput() {
        while (true) {
            try {
                std::cout << "Enter numerator: ";
                std::cin >> numerator;
                std::cout << "Enter denominator: ";
                std::cin >> denominator;
                if (denominator == 0) {
                    std::cout << "Invalid input: Denominator cannot be zero." << std::endl;
                    continue; }
                simplify();
                break;
            } catch (const std::exception& e) {
                std::cout << "Invalid input. Please enter integers." << std::endl; }}}
    void display() const {
        std::cout << numerator << "/" << denominator << std::endl; }
    Rational operator+(const Rational& other) const {
        int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);
        int new_denominator = denominator * other.denominator;
        return Rational(new_numerator, new_denominator); }
    Rational operator-(const Rational& other) const {
        int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);
        int new_denominator = denominator * other.denominator;
        return Rational(new_numerator, new_denominator); }
    Rational operator*(const Rational& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Rational(new_numerator, new_denominator); }
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero."); }
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Rational(new_numerator, new_denominator); }
};

int main() {
    Rational r1;
    r1.getInput();
    r1.display();
    Rational r2;
    r2.getInput();
    r2.display();
    Rational r3 = r1 + r2;
    std::cout << "Addition Result: ";
    r3.display();
    Rational r4 = r1 - r2;
    std::cout << "Subtraction Result: ";
    r4.display();
    Rational r5 = r1 * r2;
    std::cout << "Multiplication Result: ";
    r5.display();
    Rational r6 = r1 / r2;
    std::cout << "Division Result: ";
    r6.display();
    return 0;
}
