// Eunice Wu
// October 15, 2024
// HW #3

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
    ifstream log; // declares input file name
    ofstream statement;

    log.open ("log.txt"); // opens input file name
    statement.open ("statement.txt");

    double start; // declare variables so values from input value can be used
    char type;
    double amt;
    double withdrawl;
    double withdrawlsum;
    double deposit;
    double depositsum;

    cout << fixed << setprecision(2);

    log >> start; // stores the starting balance

    for (int i=0; i< 7; ++i) { //loop that keeps storing type of transation and amt, then prints type and balance subtracted/added
        log >> type >> amt;
        switch (type) {
            case 'W':
                withdrawl = withdrawl + 1;
                withdrawlsum = withdrawlsum + amt;
                start = start - amt;
                statement << "Withdrawl, Balance: " << start;
                break;
            case 'D':
                deposit = deposit + 1;
                depositsum = depositsum + amt;
                start = start + amt;
                statement << "Deposit, Balance: " << start;
                break;
                }       
        }
    statement << "Ending balance: " << start; // prints ending balance
    statement << "Number of Withdrawls: " << withdrawl << "Number of Deposit: " << deposit; // prints ending balance
    statement << "Sum of Withdrawls: " << withdrawlsum << "Sum of Deposit: " << depositsum;

    log.close (); //closes the input file
    statement.close ();
        return 0;
    }
