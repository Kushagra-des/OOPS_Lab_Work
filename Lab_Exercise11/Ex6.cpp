#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
    string content;
    string line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

void writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to write to file " << filename << endl;
        exit(1);
    }
    file << content;
    file.close();
}

int main() {
    string file1, file2, outputFile;

    cout << "Enter the name of the first file: ";
    cin >> file1;

    cout << "Enter the name of the second file: ";
    cin >> file2;

    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    string content1 = readFile(file1);
    string content2 = readFile(file2);

    string mergedContent = content1 + "\n" + content2;

    writeFile(outputFile, mergedContent);

    cout << "Files merged successfully. Merged content written to " << outputFile << endl;

    return 0;
}
