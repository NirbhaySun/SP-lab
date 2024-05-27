//define a structure named customer  that has fname,lname,accNum, accBalance as its members use this structure to
//read account information of  multiple persons and save it in a file. Program should read records until user enter 'stop' for frame.
 
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
// Structure to represent a customer
struct Customer {
    string fname;
    string lname;
    int accNum;
    double accBalance;
};
 
int main() {
    // Open file for writing
    ofstream outFile("customers.txt");
    if (!outFile.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }
 
    // Read and save customer information
    Customer cust;
    while (true) {
        cout << "Enter customer's first name (enter 'stop' to finish): ";
        cin >> cust.fname;
        if (cust.fname == "stop")
            break;
 
        cout << "Enter customer's last name: ";
        cin >> cust.lname;
        cout << "Enter customer's account number: ";
        cin >> cust.accNum;
        cout << "Enter customer's account balance: ";
        cin >> cust.accBalance;
 
        // Write customer information to file
        outFile << cust.fname << " " << cust.lname << " " << cust.accNum << " " << cust.accBalance << endl;
    }
 
    // Close file
    outFile.close();
    cout << "Customer information saved to customers.txt." << endl;
 
    return 0;
}
 