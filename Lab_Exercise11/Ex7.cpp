#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string encrypt(const string& text, int shift) {
    string encryptedText = text;
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            encryptedText[i] = (text[i] - base + shift) % 26 + base;
        }
    }
    return encryptedText;
}

string decrypt(const string& text, int shift) {
    string decryptedText = text;
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            decryptedText[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
    return decryptedText;
}

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
    string filename, choice;
    int shift;

    cout << "Enter the filename to encrypt/decrypt: ";
    cin >> filename;

    cout << "Enter shift value for Caesar Cipher: ";
    cin >> shift;

    cout << "Do you want to encrypt or decrypt the file? (enter 'encrypt' or 'decrypt'): ";
    cin >> choice;

    string fileContent = readFile(filename);

    if (choice == "encrypt") {
        string encryptedContent = encrypt(fileContent, shift);
        writeFile("encrypted_" + filename, encryptedContent);
        cout << "File encrypted successfully. Encrypted file: encrypted_" << filename << endl;
    } else if (choice == "decrypt") {
        string decryptedContent = decrypt(fileContent, shift);
        writeFile("decrypted_" + filename, decryptedContent);
        cout << "File decrypted successfully. Decrypted file: decrypted_" << filename << endl;
    } else {
        cerr << "Invalid choice! Please enter 'encrypt' or 'decrypt'." << endl;
        return 1;
    }

    return 0;
}
