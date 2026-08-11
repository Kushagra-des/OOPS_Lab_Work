#include <stdio.h>
void minmax(int array[], int length, int *min, int *max) {
    if (length <= 0) {
        return;
    }
    *min = *max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < *min) {
            *min = array[i];
        }
        if (array[i] > *max) {
            *max = array[i];
        }
    }
}
int main() {
    int arr[] = {10, 5, 3, 8, 15, 2, 20};
    int length = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    minmax(arr, length, &min, &max);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
