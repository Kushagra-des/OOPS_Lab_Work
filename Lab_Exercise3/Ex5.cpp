#include<iostream>
using namespace std;

void minmax(int array[], int length, int& min, int& max);

int main() {
    cout<<"Array is : 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 7, 8"<<endl;
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    minmax(arr, length, min, max);
    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;
    return 0;
}
void minmax(int array[], int length, int& min, int& max) {
    min = array[0];
    max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i]; }
        if (array[i] > max) {
            max = array[i];
}
    }
}
