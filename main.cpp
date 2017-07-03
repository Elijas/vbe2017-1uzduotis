#include <iostream>
#include <sstream>
#include <fstream>

#define outputFile cout //D
using namespace std;

char getHexDigit(int decDigit) {
    return (char) (decDigit < 10 ? decDigit + '0' : decDigit - 10 + 'A');
}

string getHexNumber(int decNumber) {
    stringstream ss;
    ss << getHexDigit(decNumber / 16) << getHexDigit(decNumber % 16);
    return ss.str();
}

int main() {
    // Opening files and reading metadata
    ifstream inputFile("U1.txt");
    //ofstream outputFile("U1rez.txt"); //D
    int length, width;
    inputFile >> length >> width;

    // Converting the numbers
    for (int il = 0; il < length; ++il) {
        for (int iw = 0; iw < width; ++iw) {
            for (int i = 0; i < 3; ++i) {
                int num;
                inputFile >> num;
                outputFile << getHexNumber(num);
            }

            if (iw < width - 1)
                outputFile << ';';
            else
                outputFile << endl;
        }
    }



    return 0;
}
