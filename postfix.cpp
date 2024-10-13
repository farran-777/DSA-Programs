#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

void convertToPostfix(const string& infix, string& postfix) {
    stack<string> s;
    string currentToken;

    for (char ch : infix) {
        if (ch == ' ') {
            if (!currentToken.empty()) {
                postfix.append(currentToken).append(" ");
                currentToken.clear();
            }
            continue;
        }

        if (isdigit(ch) || (ch == '-' && currentToken.empty())) {
            currentToken.append(1, ch);
        } else {
            if (!currentToken.empty()) {
                postfix.append(currentToken).append(" ");
                currentToken.clear();
            }

            if (isOperator(string(1, ch))) {
                while (!s.empty() && precedence(s.top()) >= precedence(string(1, ch))) {
                    postfix.append(s.top()).append(" ");
                    s.pop();
                }
                s.push(string(1, ch));
            }
        }
    }

    if (!currentToken.empty()) {
        postfix.append(currentToken).append(" ");
    }

    while (!s.empty()) {
        postfix.append(s.top()).append(" ");
        s.pop();
    }
}

int main() {
    string infix;
    string postfix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    convertToPostfix(infix, postfix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
