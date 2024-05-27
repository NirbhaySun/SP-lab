
//write program to read records from file created in fourth code and display them.
 
#include <iostream>
#include <fstream>
#include <sstream>
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
    // Open file for reading
    ifstream inFile("customers.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }
 
    // Read and display customer information
    Customer cust;
    string line;
    cout << "Customer information read from file:\n";
    while (getline(inFile, line)) {
        istringstream iss(line);
        if (!(iss >> cust.fname >> cust.lname >> cust.accNum >> cust.accBalance)) {
            cout << "Error reading customer information from file." << endl;
            break;
        }
        cout << "First Name: " << cust.fname << ", Last Name: " << cust.lname << ", Account Number: " << cust.accNum << ", Account Balance: " << cust.accBalance << endl;
    }
 
    // Close file
    inFile.close();
 
    return 0;
}
 
 
 
 