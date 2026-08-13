#include <stdio.h>
int findMissingNumber(int arr[], int size) {
    int N = size + 1;
    int expectedSum = (N * (N + 1)) / 2;
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}
int main() {
    printf("Test Case 1 is : 1,2,3,5\n");
    printf("Test Case 2 is : 1,2,3,4,5,6,7,8,10\n");
    int arr1[] = {1, 2, 3, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Missing number in Test Case 1: %d\n", findMissingNumber(arr1, size1));
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Missing number in Test Case 2: %d\n", findMissingNumber(arr2, size2));
    return 0;
}
