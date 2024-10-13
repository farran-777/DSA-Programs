#include <iostream>
using namespace std;

int main() {
    int count, position;
    cout << "Enter the size of the array: ";
    cin >> count;

    int arrayElements[count];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < count; i++) {
        cin >> arrayElements[i];
    }

    cout << "Enter the position from which to delete the element (0 to " << count - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= count) {
        cout << "Invalid position." << endl;
        return 1;
    }

    for (int i = position; i < count - 1; i++) {
        arrayElements[i] = arrayElements[i + 1];
    }

    count--;

    cout << "Array after deletion: ";
    for (int i = 0; i < count; i++) {
        cout << arrayElements[i] << " ";
    }
    cout << endl;

    return 0;
}
