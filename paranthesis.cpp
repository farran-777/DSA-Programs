#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool areParenthesesBalanced(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);
    if (areParenthesesBalanced(input)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does not have balanced parentheses." << endl;
    }
    return 0;
}
