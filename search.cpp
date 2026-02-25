#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to search: ";
                cin >> key;
                {
                    int result = linearSearch(arr, n, key);
                    if (result != -1)
                        cout << "Element found at index " << result << endl;
                    else
                        cout << "Element not found\n";
                }
                break;

            case 2:
                if (isSorted(arr, n))
                    cout << "Array is already sorted.\n";
                else {
                    cout << "Array is NOT sorted. \n";
                    sortArray(arr, n);
                }
                 cout << "Sorted Array: ";
                printArray(arr, n);

                cout << "Enter element to search: ";
                cin >> key;
                {
                    int result = binarySearch(arr, n, key);
                    if (result != -1)
                        cout << "Element found at index " << result << endl;
                    else
                        cout << "Element not found\n";
                }
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}