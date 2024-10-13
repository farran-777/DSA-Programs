#include <iostream>
using namespace std;

int main() {
    int count;
    cout << "Enter the number of elements in the array: ";
    cin >> count;

    float arrayElements[count];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < count; i++) {
        cin >> arrayElements[i];
    }

    for (int i = 0; i < count - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (arrayElements[j] > arrayElements[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arrayElements[i], arrayElements[maxIndex]);
    }

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < count; i++) {
        cout << arrayElements[i] << " ";
    }
    cout << endl;

    return 0;
}
