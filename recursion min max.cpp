#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxOfRest = findMax(arr, n - 1);
    return (arr[n - 1] > maxOfRest) ? arr[n - 1] : maxOfRest;
}

int findMin(int arr[], int n) {
    if (n == 1) return arr[0];
    int minOfRest = findMin(arr, n - 1);
    return (arr[n - 1] < minOfRest) ? arr[n - 1] : minOfRest;
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
        while (true) {
            cin >> arr[i];
           

    int maxVal = findMax(arr, n);
    int minVal = findMin(arr, n);
    
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;
    return 0;
}
}
}
