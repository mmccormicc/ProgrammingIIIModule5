#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reversal() { 
    try {
        // Opening input file
        ifstream inFile("CSC450_CT5_mod5.txt", ios_base::binary);
        // Creating/overriding output file
        ofstream outFile("CSC450-mod5-reverse.txt", ios_base::binary);
        // File iterators
        istreambuf_iterator<char> inBegin(inFile);
        istreambuf_iterator<char> inEnd;
        ostreambuf_iterator<char> outBegin(outFile);
        // Creating vector of file chars
        vector<char> input_data(inBegin, inEnd);
        // Reversing characters
        reverse_copy(input_data.begin(), input_data.end(), outBegin);
    } catch (...) {
        cout << "Error reversing file.";
    }
}

int main() {
    // Opening file in append mode
    ofstream file("CSC450_CT5_mod5.txt", ios_base::app);

    cout << "Enter text to be appended: ";

    // Empty string to hold user input
    string input;
    // Getting line of user input
    getline(cin, input);
    // Appending user input to file
    file << input;
    // Closing file to save changes before reversal
    file.close();

    // Calling reversal funciton
    reversal();

    return 0;

}