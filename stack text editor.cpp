#include <iostream>
#include <stack>
#include <string>
using namespace std;

class SimpleTextEditor {
private:
    stack<char> textStack;

public:
    void addCharacter(char c) {
        textStack.push(c);
        cout << "Added: " << c << endl;
    }

    void undo() {
        if (isEmpty()) {
            cout << "Nothing to undo." << endl;
            return;
        }
        char lastChar = textStack.top();
        textStack.pop();
        cout << "Undid: " << lastChar << endl;
    }

    void currentCharacter() {
        if (isEmpty()) {
            cout << "No characters to display." << endl;
            return;
        }
        cout << "Current character: " << textStack.top() << endl;
    }

    bool isEmpty() {
        return textStack.empty();
    }
};

int main() {
    SimpleTextEditor editor;
    char input;
    string command;

    cout << "Simple Text Editor - Type characters (type '!' to undo, 'exit' to quit):" << endl;

    while (true) {
        cout << "Enter a character: ";
        cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "!") {
            editor.undo();
        } else if (command.length() == 1) {
            editor.addCharacter(command[0]);
        } else {
            cout << "Invalid input. Type a single character or '!' to undo." << endl;
        }

        editor.currentCharacter();
    }

    return 0;
}
