#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isValidCharacter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || isOperator(ch) || ch == ' ';
}

string convertToPostfix(const string& expression) {
    stack<char> s;
    string output;
    
    for (char ch : expression) {
        if (!isValidCharacter(ch)) {
            return "Error: Invalid character in expression.";
        }
        if (ch == ' ') {
            continue;
        } else if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
            output += ch;
            output += ' ';
        } else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                output += s.top();
                output += ' ';
                s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.empty()) {
        output += s.top();
        output += ' ';
        s.pop();
    }
    
    return output;
}

int main() {
    string input;
    cout << "Enter an infix expression: ";
    getline(cin, input);
    string result = convertToPostfix(input);
    cout << "Postfix expression: " << result << endl;
    return 0;
}
