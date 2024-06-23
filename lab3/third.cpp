
// Create a structure named employee having name,age and salary as its members.Read name,age and salary of number of
//employees from user and write these data to a file named employee.txt.Read employee info again and again until user wants to add more employees.
//finally,write a program to search information of particular employee from file
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
// Define a structure for employee record
struct Employee {
    string name;
    int age;
    double salary;
};
 
// Function to add an employee record to the file
void addEmployeeRecord(const string& fileName, const Employee& emp) {
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << emp.name << "," << emp.age << "," << emp.salary << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
 
// Function to search for information of a particular employee in the file
void searchEmployeeInfo(const string& fileName, const string& searchName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        bool found = false;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            string name = line.substr(0, pos);
            if (name == searchName) {
                found = true;
                cout << "Employee Found:" << endl;
                cout << "Name: " << name << endl;
                line.erase(0, pos + 1);
                pos = line.find(',');
                int age = stoi(line.substr(0, pos));
                cout << "Age: " << age << endl;
                line.erase(0, pos + 1);
                double salary = stod(line);
                cout << "Salary: " << salary << endl;
                break;
            }
        }
        if (!found) {
            cout << "Employee not found." << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
 
int main() {
    string fileName = "employee.txt";
    char choice;
 
    do {
        Employee emp;
        cout << "Enter employee details:" << endl;
        cout << "Name: ";
        cin >> emp.name;
        cout << "Age: ";
        cin >> emp.age;
        cout << "Salary: ";
        cin >> emp.salary;
 
        // Add the employee record to the file
        addEmployeeRecord(fileName, emp);
 
        cout << "Do you want to add more employees? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
 
    string searchName;
    cout << "Enter the name of the employee to search: ";
    cin >> searchName;
 
    // Search for information of the particular employee
    searchEmployeeInfo(fileName, searchName);
 
    return 0;
}
 