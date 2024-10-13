#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int evaluatePostfix(const string& postfix) {
    stack<int> s;
    string currentToken;

    for (char ch : postfix) {
        if (ch == ' ') {
            if (!currentToken.empty()) {
                if (isOperator(currentToken)) {
                    if (s.size() < 2) return INT_MIN;
                    int b = s.top(); s.pop();
                    int a = s.top(); s.pop();
                    int result = 0;
                    if (currentToken == "+") result = a + b;
                    else if (currentToken == "-") result = a - b;
                    else if (currentToken == "*") result = a * b;
                    else if (currentToken == "/") {
                        if (b == 0) return INT_MIN;
                        result = a / b;
                    }
                    s.push(result);
                } else {
                    try {
                        s.push(stoi(currentToken));
                    } catch (...) {
                        return INT_MIN;
                    }
                }
                currentToken.clear();
            }
        } else {
            currentToken.append(1, ch);
        }
    }

    return (s.size() == 1) ? s.top() : INT_MIN;
}

int main() {
    string postfix;
    
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    if (result == INT_MIN) {
        cout << "Error: Invalid evaluation." << endl;
    } else {
        cout << "Result: " << result << endl;
    }

    return 0;
}
