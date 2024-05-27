//Create structure named employee having members ename,age and salary of employee and write info to file
 
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
// Structure to represent an employee
struct Employee {
    string ename;
    int age;
    double salary;
};
 
int main() {
    // Ask user for employee information
    Employee emp;
    cout << "Enter employee name: ";
    getline(cin, emp.ename);
    cout << "Enter employee age: ";
    cin >> emp.age;
    cout << "Enter employee salary: ";
    cin >> emp.salary;
 
    // Write employee information to file
    ofstream outFile("employees.txt", ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << emp.ename << " " << emp.age << " " << emp.salary << endl;
        cout << "Employee information written to employees.txt successfully." << endl;
        outFile.close();
    } else {
        cout << "Unable to open file." << endl;
        return 1;
    }
 
    // Read and display employee information from file
    cout << "\nEmployee information read from file:\n";
    ifstream inFile("employees.txt");
    if (inFile.is_open()) {
        while (inFile >> emp.ename >> emp.age >> emp.salary) {
            cout << "Name: " << emp.ename << ", Age: " << emp.age << ", Salary: " << emp.salary << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file." << endl;
        return 1;
    }
 
    return 0;
}