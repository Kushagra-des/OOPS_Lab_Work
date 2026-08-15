#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const int MAX_LINES = 100;
    string lines[MAX_LINES];
    string filename;
    int count = 0;

    cout << "Enter file name: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file '" << filename << "'." << endl;
        return 1;
    }

    while (getline(inFile, lines[count])) {
        count++;
        if (count >= MAX_LINES) {
            cerr << "Warning: Maximum lines (" << MAX_LINES << ") reached, stopping read." << endl;
            break;
        }
    }

    if (inFile.bad()) {
        cerr << "Error: Problem reading the file." << endl;
        return 1;
    }

    inFile.close();

    cout << "\nLines read from file:\n";
    for (int i = 0; i < count; ++i) {
        cout << lines[i] << endl;
    }

    return 0;
}
