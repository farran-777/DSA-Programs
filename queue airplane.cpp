#include <iostream>
#include <string>
using namespace std;

const int MAX_PLANES = 100;

class Aircraft {
public:
    int urgency;
    string identifier;

    Aircraft() : urgency(0), identifier("") {}
};

class PlaneQueue {
private:
    Aircraft aircrafts[MAX_PLANES];
    int front;
    int rear;
    int count;

public:
    PlaneQueue() : front(0), rear(-1), count(0) {}

    void addAircraft(string identifier, int urgency) {
        if (count >= MAX_PLANES) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX_PLANES;
        aircrafts[rear].identifier = identifier;
        aircrafts[rear].urgency = urgency;
        count++;
    }

    void landAircraft() {
        if (count == 0) {
            cout << "No aircraft waiting to land." << endl;
            return;
        }
        int highestPriorityIndex = front;
        for (int i = 1; i < count; i++) {
            int index = (front + i) % MAX_PLANES;
            if (aircrafts[index].urgency > aircrafts[highestPriorityIndex].urgency) {
                highestPriorityIndex = index;
            }
        }
        cout << aircrafts[highestPriorityIndex].identifier << " is landing (Urgency: " << aircrafts[highestPriorityIndex].urgency << ")." << endl;

        for (int i = highestPriorityIndex; i != rear; i = (i + 1) % MAX_PLANES) {
            aircrafts[i] = aircrafts[(i + 1) % MAX_PLANES];
        }
        rear = (rear - 1 + MAX_PLANES) % MAX_PLANES;
        count--;
    }

    void viewNext() {
        if (count == 0) {
            cout << "No aircraft waiting to land." << endl;
            return;
        }
        int highestPriorityIndex = front;
        for (int i = 1; i < count; i++) {
            int index = (front + i) % MAX_PLANES;
            if (aircrafts[index].urgency > aircrafts[highestPriorityIndex].urgency) {
                highestPriorityIndex = index;
            }
        }
        cout << "Next aircraft to land: " << aircrafts[highestPriorityIndex].identifier << " (Urgency: " << aircrafts[highestPriorityIndex].urgency << ")." << endl;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    PlaneQueue queue;
    int choice;
    string identifier;
    int urgency;

    while (true) {
        cout << "1. Add Aircraft\n2. Land Aircraft\n3. View Next\n4. Check if Empty\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter aircraft identifier: ";
                cin >> identifier;
                cout << "Enter urgency level (9, 6, 4): ";
                cin >> urgency;
                queue.addAircraft(identifier, urgency);
                break;
            case 2:
                queue.landAircraft();
                break;
            case 3:
                queue.viewNext();
                break;
            case 4:
                if (queue.isEmpty()) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "There are aircrafts waiting to land." << endl;
                }
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
