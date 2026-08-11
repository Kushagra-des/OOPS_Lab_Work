#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp; }
    return a; }
void simplify(int *num, int *den) {
    int divisor = gcd(*num, *den);
    *num /= divisor;
    *den /= divisor;
    if (*den < 0) {
        *num = -*num;
        *den = -*den; } }
int main() {
    int a, b, c, d, num, den;
    char op;
    printf("Enter first fraction (numerator and denominator): ");
    scanf("%d %d", &a, &b);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter second fraction (numerator and denominator): ");
    scanf("%d %d", &c, &d);
    switch (op) {
        case '+':
            num = a * d + b * c;
            den = b * d;
            break;
        case '-':
            num = a * d - b * c;
            den = b * d;
            break;
        case '*':
            num = a * c;
            den = b * d;
            break;
        case '/':
            num = a * d;
            den = b * c;
            break;
default:
            printf("Invalid operator!\n");
            return 1; }
    simplify(&num, &den);
    printf("Result: %d/%d\n", num, den);
    return 0; }
