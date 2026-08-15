#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ofstream outFile("TEXT.txt");
    if (!outFile) {
        cerr << "Error: Could not create file.\n";
        return 1;
    }
    outFile << "This is the first line.\n";
    outFile << "Here is the second line.\n";
    outFile << "And this is the third line.\n";
    outFile.close();

    ifstream inFile("TEXT.txt");
    if (!inFile) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    string line;
    while (getline(inFile, line)) {
        lines++;
        chars += line.length() + 1;
        bool inWord = false;
        for (char c : line) {
            if (isspace(c))
                inWord = false;
            else if (!inWord) {
                inWord = true;
                words++;
            }
        }
    }
    inFile.close();

    cout << left << setw(20) << "Number of lines" << right << setw(10) << lines << endl;
    cout << left << setw(20) << "Number of words" << right << setw(10) << words << endl;
    cout << left << setw(20) << "Number of characters" << right << setw(10) << chars << endl;

    return 0;
}
