#include <iostream>
using namespace std;

int main() {
    int size, targetValue;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int numbers[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cout << "Enter the value to search for: ";
    cin >> targetValue;

    int position = -1;
    for (int i = 0; i < size; i++) {
        if (numbers[i] == targetValue) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        cout << "Element found at index: " << position << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
