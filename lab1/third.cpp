//program 3
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("inventory.txt");

    if (!outFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

outFile << "Product Name \t Quantity \t Rate\n";
outFile << "AAA \t\t 5 \t \t 100 \n";
outFile << "BBB \t\t 3 \t \t  150\n";
outFile << "CCC \t\t 2 \t \t 250 \n";


outFile.close();

 


    return 0;
}