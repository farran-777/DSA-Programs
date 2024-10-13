#include <iostream>
using namespace std;

int main() {
    int size, position, newValue;
    cout << "Enter the size of the array: ";
    cin >> size;

    int numbers[size + 1];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cout << "Enter the new element to insert: ";
    cin >> newValue;
    cout << "Enter the position to insert the new element (0 to " << size << "): ";
    cin >> position;

    if (position < 0 || position > size) {
        cout << "Invalid position." << endl;
        return 1;
    }

    for (int i = size; i > position; i--) {
        numbers[i] = numbers[i - 1];
    }

    numbers[position] = newValue;

    cout << "Array after insertion: ";
    for (int i = 0; i <= size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
