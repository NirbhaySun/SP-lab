#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Create a file and write numbers 1 to 20
    ofstream outFile("numbers.txt");

    if (!outFile.is_open()) {
        cout << "Unable to create file." << endl;
        return 1;
    }

    for (int i = 1; i <= 20; ++i) {
        outFile << i << endl;
    }

    outFile.close();

    // Read numbers from the file and display twice of each number
    ifstream inFile("numbers.txt");

    if (!inFile.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    int number;
    cout << "Numbers read from file (twice of each number):" << endl;
    while (inFile >> number) {
        cout << 2 * number << endl;
    }

    inFile.close();

    return 0;
}

