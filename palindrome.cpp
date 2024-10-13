#include <iostream>
#include <string>
using namespace std;

bool checkSymmetry(const string& str) {
    string cleaned;
    for (char ch : str) {
        if (ch != ' ') {
            if (ch >= 'A' && ch <= 'Z') {
                cleaned += ch + 32;
            } else {
                cleaned += ch;
            }
        }
    }
    int left = 0, right = cleaned.length() - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    if (checkSymmetry(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
