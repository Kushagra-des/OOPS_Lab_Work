#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string school, degree;
public:
    void setStudent(string s, string d) { school = s; degree = d; }
    void showStudent() const { cout << "School: " << school << "\nDegree: " << degree << endl; }
};

class Employee {
protected:
    string name;
    int empNo;
public:
    void setEmployee(string n, int no) { name = n; empNo = no; }
    void showEmployee() const { cout << "Name: " << name << "\nEmployee No: " << empNo << endl; }
};

class Manager : public Employee, public Student {
    string title;
    float dues;
public:
    void setManager(string n, int no, string t, float d, string s, string deg) {
        setEmployee(n, no); title = t; dues = d; setStudent(s, deg);
    }
    void showManager() const {
        showEmployee();
        cout << "Title: " << title << "\nDues: " << dues << endl;
        showStudent();
    }
};

class Scientist : public Employee, public Student {
    int publications;
public:
    void setScientist(string n, int no, int p, string s, string deg) {
        setEmployee(n, no); publications = p; setStudent(s, deg);
    }
    void showScientist() const {
        showEmployee();
        cout << "Publications: " << publications << endl;
        showStudent();
    }
};

class Laborer : public Employee {
public:
    void setLaborer(string n, int no) { setEmployee(n, no); }
    void showLaborer() const { showEmployee(); }
};

int main() {
    Manager m;
    Scientist s;
    Laborer l;

    m.setManager("Alice", 1, "Head", 2000, "Oxford", "MBA");
    s.setScientist("Bob", 2, 12, "MIT", "PhD");
    l.setLaborer("Charlie", 3);

    m.showManager();
    cout << endl;
    s.showScientist();
    cout << endl;
    l.showLaborer();

    return 0;
}

