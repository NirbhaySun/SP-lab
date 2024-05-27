 
 
//write the program that read file created in first code and display them
 
#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    // Open file for reading
    ifstream inFile("numbers.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }
 
    // Read and display numbers
    double num;
    cout << "Numbers read from file:\n";
    while (inFile >> num) {
        cout << num << endl;
    }
 
    // Close file
    inFile.close();
 
    return 0;
}
 