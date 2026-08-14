#include <iostream>
#include <string>
using namespace std;

class BankAccount {

public
:
    string name;
    string acc_no;
    string acc_type;
    double bal;
    void initializeAccount(string acc_name, string acc_number, string acc_type, double balance) {
        name = acc_name;
        acc_no = acc_number;
        this->acc_type = acc_type;
        bal = balance; }
    void deposit(double amount) {
        if (amount > 0) {
            bal += amount;
            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Error: Cannot deposit a negative amount!\n"; }}
    void displayDetails() const {
        cout << "Account Number: " << acc_no << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Account Type: " << acc_type << endl;
        cout << "Balance: $" << bal << endl;
    }
    friend void withdraw(BankAccount& account, double amount);
};
void withdraw(BankAccount& account, double amount) {
    if (amount <= 0) {
        cout << "Error: Cannot withdraw a non-positive amount!\n";
    } else if (amount > account.bal) {
        cout << "Insufficient balance! Transaction failed.\n";
    } else {
        account.bal -= amount;
        cout << "Withdrawal of $" << amount << " successful.\n"; } }
int main() {
    BankAccount account1, account2;
    string acc_no_input;
    double amount;
    account1.initializeAccount("Alice", "A123", "Savings", 1000.0);
    account2.initializeAccount("Bob", "B456", "Current", 500.0);
    int choice;
    do {
        cout << "\n------ Bank Account Menu ------\n";
        cout << "1. Deposit money\n";
        cout << "2. Withdraw money\n";
        cout << "3. Display account details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter account number to deposit to: ";
            cin >> acc_no_input;
            if (acc_no_input == account1.acc_no || acc_no_input == account2.acc_no) {
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (amount > 0) {
                    if (acc_no_input == account1.acc_no) {
                        account1.deposit(amount);
                    } else {
                        account2.deposit(amount); }
                } else {
                    cout << "Error: Invalid deposit amount!\n"; }
            } else {
                cout << "Error: Invalid account number!\n"; }
            break;
        case 2:
            cout << "Enter account number to withdraw from: ";
            cin >> acc_no_input;
            if (acc_no_input == account1.acc_no || acc_no_input == account2.acc_no) {
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (acc_no_input == account1.acc_no) {
                    withdraw(account1, amount);
                } else {
                    withdraw(account2, amount); }
            } else {
                cout << "Error: Invalid account number!\n"; }
            break;
        case 3:
            cout << "Enter account number to display details: ";
            cin >> acc_no_input;
            if (acc_no_input == account1.acc_no) {
                account1.displayDetails();
            } else if (acc_no_input == account2.acc_no) {
                account2.displayDetails();
            } else {
                cout << "Error: Invalid account number!\n"; }
            break;
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Error: Invalid option! Please select a valid choice.\n";
            break; }
    } while (choice != 4);
    return 0; }
