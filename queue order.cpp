#include <iostream>
#include <string>
using namespace std;

const int MAX_ORDERS = 100;

class CustomerOrder {
public:
    string orderName;
    bool urgent;

    CustomerOrder() : orderName(""), urgent(false) {}
};

class OrderDeque {
private:
    CustomerOrder orders[MAX_ORDERS];
    int front;
    int rear;
    int count;

public:
    OrderDeque() : front(-1), rear(0), count(0) {}

    void addUrgent(string orderName) {
        if (count >= MAX_ORDERS) {
            cout << "Deque is full!" << endl;
            return;
        }
        front = (front + 1) % MAX_ORDERS;
        orders[front].orderName = orderName;
        orders[front].urgent = true;
        count++;
    }

    void addRegular(string orderName) {
        if (count >= MAX_ORDERS) {
            cout << "Deque is full!" << endl;
            return;
        }
        orders[rear].orderName = orderName;
        orders[rear].urgent = false;
        rear = (rear + 1) % MAX_ORDERS;
        count++;
    }

    void processUrgent() {
        if (count == 0) {
            cout << "No orders to process." << endl;
            return;
        }
        cout << orders[front].orderName << " (Urgent) is being processed." << endl;
        front = (front - 1 + MAX_ORDERS) % MAX_ORDERS;
        count--;
    }

    void processRegular() {
        if (count == 0) {
            cout << "No orders to process." << endl;
            return;
        }
        rear = (rear - 1 + MAX_ORDERS) % MAX_ORDERS;
        cout << orders[rear].orderName << " (Regular) is being processed." << endl;
        count--;
    }

    void viewNextOrder() {
        if (count == 0) {
            cout << "No orders to check." << endl;
            return;
        }
        if (front >= 0) {
            cout << "Next urgent order: " << orders[front].orderName << endl;
        }
        if (rear > 0) {
            cout << "Next regular order: " << orders[(rear - 1 + MAX_ORDERS) % MAX_ORDERS].orderName << endl;
        }
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    OrderDeque orders;
    int choice;
    string orderName;

    while (true) {
        cout << "1. Add Urgent Order\n2. Add Regular Order\n3. Process Urgent Order\n4. Process Regular Order\n5. Check Next Order\n6. Is Empty\n7. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter urgent order name: ";
                cin >> orderName;
                orders.addUrgent(orderName);
                break;
            case 2:
                cout << "Enter regular order name: ";
                cin >> orderName;
                orders.addRegular(orderName);
                break;
            case 3:
                orders.processUrgent();
                break;
            case 4:
                orders.processRegular();
                break;
            case 5:
                orders.viewNextOrder();
                break;
            case 6:
                if (orders.isEmpty()) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "There are orders in the queue." << endl;
                }
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
