#include <iostream>
#include <stack>
#include <string>
using namespace std;

class WebNavigator {
private:
    stack<string> pageStack;

public:
    void openPage(const string& url) {
        pageStack.push(url);
        cout << "Opened: " << url << endl;
    }

    void navigateBack() {
        if (isEmpty()) {
            cout << "Cannot go back. No pages in history." << endl;
            return;
        }
        string previousPage = pageStack.top();
        pageStack.pop();
        cout << "Navigated back from: " << previousPage << endl;
    }

    void showCurrentPage() {
        if (isEmpty()) {
            cout << "No current page." << endl;
            return;
        }
        cout << "Current page: " << pageStack.top() << endl;
    }

    bool isEmpty() {
        return pageStack.empty();
    }
};

int main() {
    WebNavigator navigator;
    string command;
    string url;

    cout << "Web Navigation System - Type 'open <url>' to open a page, 'back' to go back, or 'exit' to quit:" << endl;

    while (true) {
        cout << "Command: ";
        getline(cin, command);

        if (command == "exit") {
            break;
        } else if (command.find("open ") == 0) {
            url = command.substr(5);
            navigator.openPage(url);
        } else if (command == "back") {
            navigator.navigateBack();
        } else {
            cout << "Invalid command. Use 'open <url>', 'back', or 'exit'." << endl;
        }

        navigator.showCurrentPage();
    }

    return 0;
}
