#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream source1("Source1");
    ifstream source2("Source2");
    ofstream target("Target");

    if (!source1) {
        cerr << "Error: Could not open file 'Source1'." << endl;
        return 1;
    }
    if (!source2) {
        cerr << "Error: Could not open file 'Source2'." << endl;
        return 1;
    }
    if (!target) {
        cerr << "Error: Could not create file 'Target'." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;

    while (source1 >> num) {
        numbers.push_back(num);
    }

    while (source2 >> num) {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    for (int n : numbers) {
        target << n << " ";
    }

    cout << "Merged sorted list has been written to 'Target' file." << endl;

    source1.close();
    source2.close();
    target.close();

    return 0;
}
