#include <iostream>
#include <algorithm>

using namespace std;

void findKthSmallestAndLargest(int arr[], int n, int k) {
    sort(arr, arr + n);
    int kthSmallest = arr[k - 1];
    int kthLargest = arr[n - k];
    cout << k << "th smallest number is " << kthSmallest << " and ";
    cout << k << "th largest number is " << kthLargest << endl;
}
int main() {
    cout<<"Array 1 is : 4, 5, 60, 70, 33, 44"<<endl;
    cout<<"Array 1 is : 2, 46, 56, 68, 3, 34, 489, 457, 4545, 100"<<endl<<endl;
    int arr1[] = {4, 5, 60, 70, 33, 44};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    findKthSmallestAndLargest(arr1, n1, k1);
    int arr2[] = {2, 46, 56, 68, 3, 34, 489, 457, 4545, 100};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 5;
    findKthSmallestAndLargest(arr2, n2, k2);
    return 0;
}
