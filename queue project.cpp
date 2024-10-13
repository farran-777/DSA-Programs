#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 10;

struct Task {
    string title;
    int priority;
};

class MinPriorityQueue {
private:
    Task tasks[MAX_TASKS];
    int count;

public:
    MinPriorityQueue() : count(0) {}

    void addTask(const string& title, int priority) {
        if (count < MAX_TASKS) {
            tasks[count] = {title, priority};
            count++;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    void executeTask() {
        if (count == 0) {
            cout << "No tasks to execute." << endl;
            return;
        }

        int minIndex = 0;
        for (int i = 1; i < count; i++) {
            if (tasks[i].priority < tasks[minIndex].priority) {
                minIndex = i;
            }
        }

        cout << tasks[minIndex].title << " (Priority: " << tasks[minIndex].priority << ") is being executed." << endl;

        tasks[minIndex] = tasks[count - 1];
        count--;
    }

    void checkNextTask() {
        if (count == 0) {
            cout << "No tasks to check." << endl;
            return;
        }

        int minIndex = 0;
        for (int i = 1; i < count; i++) {
            if (tasks[i].priority < tasks[minIndex].priority) {
                minIndex = i;
            }
        }

        cout << "Next task: " << tasks[minIndex].title << " (Priority: " << tasks[minIndex].priority << ")" << endl;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    MinPriorityQueue queue;
    int choice;
    string title;
    int priority;

    while (true) {
        cout << "1. Add Task\n2. Execute Task\n3. Check Next Task\n4. Is Empty\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task title: ";
                cin >> title;
                cout << "Enter task priority (1, 3, or 5): ";
                cin >> priority;
                queue.addTask(title, priority);
                break;
            case 2:
                queue.executeTask();
                break;
            case 3:
                queue.checkNextTask();
                break;
            case 4:
                cout << (queue.isEmpty() ? "The queue is empty." : "There are tasks in the queue.") << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
