#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insert() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Delete node
void deleteNode() {
    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Display list
void display() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}