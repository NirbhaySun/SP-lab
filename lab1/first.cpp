//program1
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("student.txt");

    if (!file.is_open()) {
        cout << "Unable to create file." << endl;
        return 1;
    }

    string name, roll, address, marks;

    // Sample student information
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> roll;
    cin.ignore(); // Ignore newline character left in buffer
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter marks: ";
    cin >> marks;

    // Write formatted data to the file
    file << "Name: " << name << endl;
    file << "Roll: " << roll << endl;
    file << "Address: " << address << endl;
    file << "Marks: " << marks << endl;

    cout << "Student information has been written to the file successfully." << endl;

    return 0;
}