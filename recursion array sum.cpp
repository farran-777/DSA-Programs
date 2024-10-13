#include <iostream>
using namespace std;

int calculateSum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + calculateSum(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = calculateSum(arr, n);
    cout << "The sum of the array elements is: " << result << endl;
    return 0;
}
