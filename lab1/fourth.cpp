//program 4
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Open the file in read mode
    ifstream inFile("inventory.txt");
    if (inFile.is_open()) {
        string line;
        // Print table header
        cout << "ProductName  Qty  Rate  Total Amount" << endl;

        // Skip the header line
        getline(inFile, line);

        // Process each line of the file
        while (getline(inFile, line)) {
            istringstream iss(line);
            string productName;
            int qty, rate;

            iss >> productName >> qty >> rate;
            int totalAmount = qty * rate;

            cout << productName << "          "
                 << qty << "    "
                 << rate << "    "
                 << totalAmount << endl;
        }

        inFile.close();
    } else {
        cerr << "Unable to open file for reading" << endl;
    }

    return 0;
}