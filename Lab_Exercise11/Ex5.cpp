#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string sourceFile, destFile;
    cout << "Enter source file name: ";
    cin >> sourceFile;
    cout << "Enter destination file name: ";
    cin >> destFile;

    ifstream inFile(sourceFile, ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open source file '" << sourceFile << "'." << endl;
        return 1; }

    ofstream outFile(destFile, ios::binary);
    if (!outFile) {
        cerr << "Error: Could not create destination file '" << destFile << "'." << endl;
        return 1; }

    outFile << inFile.rdbuf();

    if (inFile.fail() || outFile.fail()) {
        cerr << "Error: Failed to copy file contents." << endl;
        return 1; }

    cout << "File copied successfully from '" << sourceFile << "' to '" << destFile << "'." << endl;

    inFile.close();
    outFile.close();

    return 0; }
