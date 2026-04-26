#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue
void enqueue(int val) {
    Node* newNode = new Node;
    newNode->data = val;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;   // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;   // maintain circular
    }

    cout << val << " inserted\n";
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    if (front == rear) {
        cout << front->data << " deleted\n";
        delete front;
        front = rear = NULL;
    } else {
        Node* temp = front;
        cout << temp->data << " deleted\n";
        front = front->next;
        rear->next = front;   // maintain circular
        delete temp;
    }
}

// Display
void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;

    cout << "Queue: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}

int main() {
    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
        }

    } while (choice != 4);

    return 0;
}