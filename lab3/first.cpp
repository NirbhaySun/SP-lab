//Write a program to retrieve particular record of customer.program should ask user for record number to be retrieved
#include <iostream>
#include <string>
 
using namespace std;
 
// Define a structure for customer record
struct Customer {
    string name;
    int age;
    string address;
    // You can add more fields as needed
};
 
int main() {
    const int MAX_CUSTOMERS = 100; // Maximum number of customer records
    Customer customers[MAX_CUSTOMERS]; // Array to store customer records
    int numCustomers = 0; // Current number of customers
 
    // Sample data for demonstration
    customers[0] = {"John Doe", 30, "123 Main St"};
    customers[1] = {"Jane Smith", 25, "456 Elm St"};
    numCustomers = 2;
 
    // Prompt the user to enter the record number to retrieve
    int recordNumber;
    cout << "Enter the record number to retrieve: ";
    cin >> recordNumber;
 
    // Check if the record number is within the valid range
    if (recordNumber >= 1 && recordNumber <= numCustomers) {
        // Retrieve and display the requested record
        Customer requestedCustomer = customers[recordNumber - 1]; // Adjust for 0-based indexing
        cout << "Record " << recordNumber << ":" << endl;
        cout << "Name: " << requestedCustomer.name << endl;
        cout << "Age: " << requestedCustomer.age << endl;
        cout << "Address: " << requestedCustomer.address << endl;
        // Display more fields if needed
    } else {
        cout << "Invalid record number. Please enter a number between 1 and " << numCustomers << "." << endl;
    }
 
    return 0;
}
 