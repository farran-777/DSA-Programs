#include <iostream>
#include <stack>
#include <string>
using namespace std;

class DishStack {
private:
    stack<string> dishStack;
    int capacity;

public:
    DishStack(int size) : capacity(size) {}

    void addDish(const string& dish) {
        if (is_full()) {
            cout << "Stack is full. Cannot add dish: " << dish << endl;
            return;
        }
        dishStack.push(dish);
        cout << "Dish added: " << dish << endl;
    }

    void removeDish() {
        if (is_empty()) {
            cout << "No dishes left to use." << endl;
            return;
        }
        string topDish = dishStack.top();
        dishStack.pop();
        cout << "Dish used: " << topDish << endl;
    }

    void showTopDish() {
        if (is_empty()) {
            cout << "No dishes available." << endl;
            return;
        }
        cout << "Top dish: " << dishStack.top() << endl;
    }

    bool is_full() {
        return dishStack.size() >= capacity;
    }

    bool is_empty() {
        return dishStack.empty();
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the dish stack: ";
    cin >> capacity;

    DishStack dishStack(capacity);
    string command, dish;

    cout << "Dish Stack System - Type 'wash <dish>' to add a dish, 'use' to remove a dish, or 'exit' to quit:" << endl;

    cin.ignore(); 
    while (true) {
        cout << "Command: ";
        getline(cin, command);

        if (command == "exit") {
            break;
        } else if (command.find("wash ") == 0) {
            dish = command.substr(5);
            dishStack.addDish(dish);
        } else if (command == "use") {
            dishStack.removeDish();
        } else {
            cout << "Invalid command. Use 'wash <dish>', 'use', or 'exit'." << endl;
        }

        dishStack.showTopDish();
    }

    return 0;
}
