#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
public:
    void getStudentInfo() {
        cout << "Enter Roll No. : ";
        cin >> rollNo;
        cout << "Enter Name of the Student : ";
        cin.ignore();
        getline(cin, name);
    }

    void displayStudentInfo() {
        cout << "\nRoll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class Exam : public Student {
protected:
    int marks[6];
public:
    void getMarks() {
        cout << "Enter marks for 6 subjects:" << endl;
        for (int i = 0; i < 6; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks() {
        cout << "Marks in 6 subjects: ";
        for (int i = 0; i < 6; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class Result : public Exam {
    int totalMarks;
public:
    void calculateTotal() {
        totalMarks = 0;
        for (int i = 0; i < 6; i++) {
            totalMarks += marks[i];
        }
    }

    void displayResult() {
        displayStudentInfo();
        displayMarks();
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main() {
    Result r;
    r.getStudentInfo();
    r.getMarks();
    r.calculateTotal();
    r.displayResult();
    return 0;
}
