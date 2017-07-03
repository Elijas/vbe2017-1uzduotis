#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

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
    std::cout << getHexNumber(16) << std::endl;
    assert(getHexNumber(0) == "00");
    assert(getHexNumber(128) == "80");
    assert(getHexNumber(255) == "FF");
    return 0;
}
