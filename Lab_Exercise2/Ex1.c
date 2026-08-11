#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m;

    printf("Enter the upper number (m): ");
    scanf("%d", &m);

    printf("Enter the lower number (n): ");
    scanf("%d", &n);

    int number = n + rand() % (m - n + 1);
    printf("Random number between %d and %d: %d\n", m, n, number);

    return 0;
}
