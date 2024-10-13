#include <iostream>
using namespace std;

void findElement(int arr[], int count, int target) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found in the array." << endl;
}

int main() {
    int count;
    cout << "Enter the size of the array: ";
    cin >> count;

    int arrayElements[count];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < count; i++) {
        cin >> arrayElements[i];
    }

    int searchElement;
    cout << "Enter the target element to search for: ";
    cin >> searchElement;

    findElement(arrayElements, count, searchElement);

    return 0;
}
