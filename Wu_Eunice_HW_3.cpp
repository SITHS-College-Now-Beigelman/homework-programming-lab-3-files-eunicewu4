// Eunice Wu
// October 15, 2024
// HW #3

#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream log; // declares input file name

    log.open ("log.txt"); // opens input file name

    double start; // declare variables so values from input value can be used
    char type;
    double amt;

    log >> start; // stores the starting balance

    for (int i=0; i< 7; ++i) { //loop that keeps storing type of transation and amt, then prints type and balance subtracted/added
        log >> type >> amt;
        switch (type) {
            case 'W':
                start = start - amt;
                cout << "Withdrawl, Balance: " << start;
                break;
            case 'D':
                start = start + amt;
                cout << "Deposit, Balance: " << start;
                break;
                }       
        }
    cout << "Ending balance: " << start; // prints ending balance

    log.close (); //closes the input file



        return 0;
    }
