// Eunice Wu
// October 15, 2024
// HW #3

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
// declares input/output file name
    ifstream log; 
    ofstream statement;

// opens input/output file name
    log.open ("log.txt"); 
    statement.open ("statement.txt");

// declare variables so values from input value can be used. set some to zero to avoid random numbers.
    double start; 
    char type;
    double amt;
    int withdrawl =0;
    double withdrawlsum;
    int deposit =0;
    double depositsum;

// stores and prints the starting balance from log to statement
    log >> start; 
    statement << "Starting Balance: $" << fixed << setprecision(2) << showpoint << start << endl; //makes numbers appear like money for the rest
    statement << endl;
    
// uses output manipulators to print and format sections into "Type           Amount         Balance" into statement
    statement << left << setw(15) << "Type" << setw(15) << "Amount"<< "Balance" << endl;

// keeps going until the end loop. keeps formating info from log into statement
    while (!log.eof()) {
        log >> type >> amt;
        switch (type) {
           case 'W':
                withdrawl = withdrawl + 1; // calculates the times of withdrawls to later print at end
                withdrawlsum = withdrawlsum + amt; // sums up withdrawl amount
                start = start - amt; // calculates balance, later prints it out 
                statement << setfill('.') << setw(15) << type << setw(15) << amt << start << endl; // setfills dots instead of spaces
                break;
            case 'D':
                deposit = deposit + 1; // same as withdrawl, but stored into respective variables
                depositsum = depositsum + amt;
                start = start + amt;
                statement << setfill('.') << setw(15) << type << setw(15) << amt << start << endl;
                break;
         }  
    }
    // after reaches the end of log, will move on to print summary
    statement << endl;
    statement << "Ending balance: $" << start << endl; // prints ending balance
    statement << "Sum of Withdrawls: $" << withdrawlsum << endl; // sum of withdrawl
    statement << "Sum of Deposit: $" << depositsum << endl; // sum of deposit
    statement << "Withdrawals Times: " << withdrawl << endl; //withdrawl times 
    statement << "Deposit Times: " << deposit << endl; // deposit times

    //closes the input/otput file
    log.close (); 
    statement.close ();
        
        return 0;
    }
    /*
    Starting Balance: $5000.00

Type           Amount         Balance
W..............200.00.........4800.00
W..............800.00.........4000.00
W..............40.00..........3960.00
D..............90.00..........4050.00
D..............100.00.........4150.00
D..............1000.00........5150.00
W..............20.00..........5130.00
W..............800.00.........4330.00
W..............40.00..........4290.00
D..............90.00..........4380.00
D..............100.00.........4480.00
D..............1000.00........5480.00
W..............20.00..........5460.00

Ending balance: $5460.00
Sum of Withdrawls: $1920.00
Sum of Deposit: $2380.00
Withdrawals Times: 7
Deposit Times: 6

      
    */
