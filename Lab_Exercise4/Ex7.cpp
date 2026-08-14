#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    int tableNumber;
    string serverName;
    int numberOfPatrons;

    static const double tableMinimumCharge;

public:
    static void displayMinimumCharge() {
        cout << "The minimum charge for a table is: $" << tableMinimumCharge << endl; }
};
const double Order::tableMinimumCharge = 4.75;

int main() {
    Order::displayMinimumCharge();

    return 0;
}
