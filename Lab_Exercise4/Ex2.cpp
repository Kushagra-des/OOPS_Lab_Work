#include <iostream>
using namespace std;
int add(int a, int b, int c) {
    return a + b + c;
}

float add(float a, float b, float c) {
    return a + b + c;
}

double add(double a, double b, double c) {
    return a + b + c;
}

long double add(long double a, long double b, long double c) {
    return a + b + c;
}

int main() {
    int intResult = add(10, 20, 30);
    cout << "Sum of integers: " << intResult << endl;

    float floatResult = add(10.5f, 20.3f, 30.2f);
    cout << "Sum of floats: " << floatResult << endl;

    double doubleResult = add(10.5, 20.3, 30.2);
    cout << "Sum of doubles: " << doubleResult << endl;

    long double longDoubleResult = add(10.5l, 20.3l, 30.2l);
    cout << "Sum of long doubles: " << longDoubleResult << endl;

    return 0;
}
