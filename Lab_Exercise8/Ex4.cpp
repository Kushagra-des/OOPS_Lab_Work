#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    string name;
    float salary;
public:
    Employee(int i, string n, float s) : id(i), name(n), salary(s) {}
    void show() {
        cout << id << " " << name << " " << salary << " ";
    }
};

class Teacher : public Employee {
    string subject;
    int pubs;
public:
    Teacher(int i, string n, float s, string sub, int p) : Employee(i, n, s), subject(sub), pubs(p) {}
    void show() {
        Employee::show();
        cout << subject << " " << pubs << endl;
    }
};

class Officer : public Employee {
    char grade;
public:
    Officer(int i, string n, float s, char g) : Employee(i, n, s), grade(g) {}
    void show() {
        Employee::show();
        cout << grade << endl;
    }
};

class Typist : public Employee {
protected:
    float speed;
public:
    Typist(int i, string n, float s, float sp) : Employee(i, n, s), speed(sp) {}
    void show() {
        Employee::show();
        cout <<"; Speed : "<< speed << " ";
    }
};

class RegularTypist : public Typist {
    float wage;
public:
    RegularTypist(int i, string n, float s, float sp, float w) : Typist(i, n, s, sp), wage(w) {}
    void show() {
        Typist::show();
        cout << "; Wage "<< wage <<" (Regular Typist)"<< endl;
    }
};

class CasualTypist : public Typist {
    float wage;
public:
    CasualTypist(int i, string n, float s, float sp, float w) : Typist(i, n, s, sp), wage(w) {}
    void show() {
        Typist::show();
        cout  << "; Wage "<< wage << " (Casual Typist)" << endl;
    }
};

int main() {
    Teacher t(61, "Ravi Mishra ;", 500000 , "Mathematics ;", 5);
    Officer o(62, "Meera Sharma ;", 450000, 'A');
    RegularTypist rt(63., "Ananya Srivastav ;", 200000, 65, 600);
    CasualTypist ct(64, "Vikram Singh ;", 180000, 55, 400);

    t.show();
    o.show();
    rt.show();
    ct.show();

    return 0;
}
