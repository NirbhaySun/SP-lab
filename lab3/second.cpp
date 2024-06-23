
//Create a file named çollege.txt write a program to keep records of N colleges ofnepal in file.THese records contain name,location and phone of respective colleges.DIsplay name of college in kathmandu
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
 
// Define a structure for college record
struct College {
    string name;
    string location;
    string phone;
};
 
// Function to add a college record to the file
void addCollegeRecord(const string& fileName, const College& college) {
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << college.name << "," << college.location << "," << college.phone << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
 
// Function to display colleges located in Kathmandu
void displayCollegesInKathmandu(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            string name = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(',');
            string location = line.substr(0, pos);
            line.erase(0, pos + 1);
            string phone = line;
            if (location == "Kathmandu") {
                cout << "College Name: " << name << endl;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
 
int main() {
    int N;
    cout << "Enter the number of colleges: ";
    cin >> N;
 
    vector<College> colleges(N);
 
    // Get college records from user
    for (int i = 0; i < N; ++i) {
        cout << "Enter details for college " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, colleges[i].name);
        cout << "Location: ";
        getline(cin, colleges[i].location);
        cout << "Phone: ";
        getline(cin, colleges[i].phone);
        // Add the college record to the file
        addCollegeRecord("college.txt", colleges[i]);
    }
 
    // Display colleges located in Kathmandu
    cout << "\nColleges in Kathmandu:" << endl;
    displayCollegesInKathmandu("college.txt");
 
    return 0;
}
 