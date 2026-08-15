#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;
public:
    Complex() {
        real = 0;
        imag = 0;
    }
    Complex(float value) {
        real = value;
        imag = value;
    }
    Complex(float r, float i) {
        real = r;
        imag = i;
    }
    Complex sum(const Complex& other) {
        float sumReal = real + other.real;
        float sumImag = imag + other.imag;
        return Complex(sumReal, sumImag); }
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl; }
};
int main() {
    float real1, imag1, real2, imag2;
    cout << "Enter the real and imaginary parts of the first complex number (a + bi):\n";
    cout << "Real part: ";
    cin >> real1;
    cout << "Imaginary part: ";
    cin >> imag1;
    cout << "Enter the real and imaginary parts of the second complex number (a + bi):\n";
    cout << "Real part: ";
    cin >> real2;
    cout << "Imaginary part: ";
    cin >> imag2;
    Complex c1(real1, imag1);
    Complex c2(real2, imag2);
    cout << "First complex number: ";
    c1.display();
    cout << "Second complex number: ";
    c2.display();
    Complex sum = c1.sum(c2);
    cout << "Sum of the complex numbers: ";
    sum.display();
    return 0; }
