#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int highestOccurringDigit(int L, int R) {
    map<int, int> digitCount;
    for (int num = L; num <= R; ++num) {
        if (isPrime(num)) {
            string primeStr = to_string(num);
            for (char digit : primeStr) {
                digitCount[digit - '0']++;
            }
        }
    }
    if (digitCount.empty()) {
        return -1;
    }
    int maxCount = 0;
    int resultDigit = -1;
    for (auto &entry : digitCount) {
        if (entry.second > maxCount || (entry.second == maxCount && entry.first > resultDigit)) {
            maxCount = entry.second;
            resultDigit = entry.first;
        }
    }
    return resultDigit;
}
int main() {
    int L, R;
    cout << "Enter the range L and R: ";
    cin >> L >> R;
    int result = highestOccurringDigit(L, R);
    if (result == -1) {
        cout << "No prime numbers in the given range." << endl;
    } else {
        cout << "The highest occurring digit is: " << result << endl;
    }
    return 0;
}
