#include <iostream>
using namespace std;

class Shirt {
public:
    float collarSize;
    float sleeveLength;

    Shirt(float cSize = 0.0, float sLength = 0.0) {
        collarSize = cSize;
        sleeveLength = sLength; }
};

class Pants {
public:
    float waistSize;
    float inseam;

    Pants(float wSize = 0.0, float iSeam = 0.0) {
        waistSize = wSize;
        inseam = iSeam; }
};

void displayClothingFacts(Shirt s) {
    cout << "Shirt Facts:" << endl;
    cout << "Collar Size: " << s.collarSize << " inches" << endl;
    cout << "Sleeve Length: " << s.sleeveLength << " inches" << endl<<endl;
}

void displayClothingFacts(Pants p) {
    cout << "Pants Facts:" << endl;
    cout << "Waist Size: " << p.waistSize << " inches" << endl;
    cout << "Inseam: " << p.inseam << " inches" << endl;
}

int main() {
    Shirt shirt1(15.5, 32);
    Pants pants1(34, 30);
    displayClothingFacts(shirt1);
    displayClothingFacts(pants1);

    return 0; }
