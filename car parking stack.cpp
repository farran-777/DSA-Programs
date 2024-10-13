#include <iostream>
#include <string>
using namespace std;

class CarStack {
private:
    string* cars;
    int top;
    int capacity;

public:
    CarStack(int size) {
        capacity = size;
        cars = new string[capacity];
        top = -1;
    }

    ~CarStack() {
        delete[] cars;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void addCar(const string& licensePlate) {
        if (isFull()) {
            cout << "Parking lot is full. Cannot add car with license plate: " << licensePlate << endl;
            return;
        }
        cars[++top] = licensePlate;
        cout << "Car with license plate " << licensePlate << " added." << endl;
    }

    void removeCar() {
        if (isEmpty()) {
            cout << "Parking lot is empty. No car to remove." << endl;
            return;
        }
        cout << "Car with license plate " << cars[top--] << " removed from the parking lot." << endl;
    }

    void viewTopCar() {
        if (isEmpty()) {
            cout << "Parking lot is empty. No car on top." << endl;
            return;
        }
        cout << "Car on top: " << cars[top] << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the parking lot: ";
    cin >> capacity;

    CarStack parkingLot(capacity);
    int choice;
    string licensePlate;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add a car\n";
        cout << "2. Remove the last added car\n";
        cout << "3. View the top car\n";
        cout << "4. Check if the lot is full\n";
        cout << "5. Check if the lot is empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter license plate number: ";
            cin >> licensePlate;
            parkingLot.addCar(licensePlate);
        } else if (choice == 2) {
            parkingLot.removeCar();
        } else if (choice == 3) {
            parkingLot.viewTopCar();
        } else if (choice == 4) {
            cout << (parkingLot.isFull() ? "Parking lot is full." : "Parking lot is not full.") << endl;
        } else if (choice == 5) {
            cout << (parkingLot.isEmpty() ? "Parking lot is empty." : "Parking lot is not empty.") << endl;
        } else if (choice == 6) {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
