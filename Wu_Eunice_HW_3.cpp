// Eunice Wu
// October 15, 2024
// HW #3

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
    ifstream log; // declares input file name

    log.open ("log.txt"); // opens input file name

    double start; // declare variables so values from input value can be used
    char type;
    double amt;

    log >> start; // stores the starting balance, prints this line below
    cout << "Starting Balance: $" << fixed << setprecision(2) << showpoint << start << endl; // also formats numbers to look like money for all numbers
    cout << endl;

    for (int i=0; i< 7; ++i) { //repeats 7 times. a loop that store type of transation and amt, then uses to prints type and balance subtracted or added
        log >> type >> amt; //first reads and stores type and amt from log
        switch (type) { // based if its a withdrawl or transaction, different steps will follow
            case 'W':
                start = start - amt; // adds amt to balance
                cout << "Withdrawal, Balance: " << start <<endl; //prints
                break; //stop this case and repeat loop if goal not met
            case 'D':
                start = start + amt; 
                cout << "Deposit, Balance: " << start << endl;
                break;
                }       
        }
    cout << endl;
    cout << "Ending balance: $" << start; // prints ending balance

    log.close (); //closes the input file

        return 0;
    }

/*Starting Balance: $5000.00

Withdrawal, Balance: 4800.00
Withdrawal, Balance: 4000.00
Withdrawal, Balance: 3960.00
Deposit, Balance: 4050.00
Deposit, Balance: 4150.00
Deposit, Balance: 5150.00
Withdrawal, Balance: 5130.00

Ending balance: $5130.00
*/