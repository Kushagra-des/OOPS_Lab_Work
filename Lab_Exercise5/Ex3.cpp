#include <iostream>
#include <limits>
using namespace std;

class Student {
private:
    int rollNumber;
    int marks[3];
public:
    void inputStudentData(int rollNo) {
        rollNumber = rollNo;
        cout << "Enter marks for 3 subjects for student with Roll Number " << rollNumber << ":\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i]; }}
    int calculateTotal() {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i]; }
        return total; }
    void displayStudentData() {
        cout << "Roll Number: " << rollNumber << "\nMarks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " "; }
        cout << "\nTotal Marks: " << calculateTotal() << endl; }
    int getMark(int subjectIndex) {
        if (subjectIndex >= 0 && subjectIndex < 3) {
            return marks[subjectIndex]; }
        return -1; }
    int getRollNumber() {
        return rollNumber; }
};
void findHighestMarksInEachSubject(Student students[], int totalStudents) {
    for (int subject = 0; subject < 3; subject++) {
        int highestMarks = -1;
        int highestRollNo = -1;
        for (int i = 0; i < totalStudents; i++) {
            int marks = students[i].getMark(subject);
            if (marks > highestMarks) {
                highestMarks = marks;
                highestRollNo = students[i].getRollNumber(); } }
        cout << "Highest marks in Subject " << subject + 1 << " is " << highestMarks
             << " by student with Roll Number " << highestRollNo << endl; } }
void findStudentWithHighestTotalMarks(Student students[], int totalStudents) {
    int highestTotal = -1;
    int highestRollNo = -1;
    for (int i = 0; i < totalStudents; i++) {
        int total = students[i].calculateTotal();
        if (total > highestTotal) {
            highestTotal = total;
            highestRollNo = students[i].getRollNumber(); } }
    cout << "Student with Roll Number " << highestRollNo
         << " secured the highest total marks: " << highestTotal << endl; }
int main() {
    const int totalStudents = 4;
    Student students[totalStudents];
    for (int i = 0; i < totalStudents; i++) {
        students[i].inputStudentData(i + 1); }
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all student data\n";
        cout << "2. Find highest marks in each subject\n";
        cout << "3. Find student with highest total marks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                for (int i = 0; i < totalStudents; i++) {
                    students[i].displayStudentData(); }
                break;
            case 2:
                findHighestMarksInEachSubject(students, totalStudents);
                break;
            case 3:
                findStudentWithHighestTotalMarks(students, totalStudents);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; }
    } while (choice != 4);
    return 0; }
