#include <iostream>
#include <string>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of strings: ";
    cin >> size;

    string strings[size];
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> strings[i];
    }

    for (int i = 1; i < size; i++) {
        string key = strings[i];
        int j = i - 1;

        while (j >= 0 && strings[j] > key) {
            strings[j + 1] = strings[j];
            j--;
        }
        strings[j + 1] = key;
    }

    cout << "Sorted array in alphabetical order:" << endl;
    for (int i = 0; i < size; i++) {
        cout << strings[i] << endl;
    }

    return 0;
}
