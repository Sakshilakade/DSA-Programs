//stack using linked list
//hashing

#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void displayList(int arr[], int n) {
    cout << "\nElements in the list:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayTable(int searchKey) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << "Index " << i << " : Empty" << endl;
        else if (hashTable[i] == searchKey)
            cout << "Index " << i << " : " << hashTable[i] << "  <-- searched key" << endl;
        else
            cout << "Index " << i << " : " << hashTable[i] << endl;
    }
}

int main() {
    int n, key, searchKey;
    int arr[20];

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        insert(arr[i]);
    }

    displayList(arr, n);

    cout << "\nWhich element do you want to search: ";
    cin >> searchKey;

    displayTable(searchKey);

    return 0;
}