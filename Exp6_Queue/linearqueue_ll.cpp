//linearqueue using linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Inserted: " << value << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << front->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display() {
    Node* temp = front;

    if (temp == NULL) {
        cout << "Queue is Empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (1) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
}