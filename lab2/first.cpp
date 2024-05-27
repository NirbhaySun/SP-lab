//write a program that asks user for 10 numbers ad store them in array write this array to file
#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    // Ask user for 10 numbers
    double numbers[10];
    cout << "Enter 10 numbers:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }
 
    // Write numbers to a file
    ofstream outFile("numbers.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 10; ++i) {
            outFile << numbers[i] << endl;
        }
        cout << "Numbers written to numbers.txt successfully." << endl;
        outFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
 
    return 0;
}
 