#include<iostream>
using namespace std;

class Mother {
public:
    void display() {
        cout << "This is the Mother Class Code." << endl;
    }
};

class Daughter : public Mother {
public:
    void display() {
        cout << "This is the Daughter Class Code." << endl;
    }
};

int main() {
    Daughter d;
    d.display();
    d.Mother::display();
    return 0;
}
