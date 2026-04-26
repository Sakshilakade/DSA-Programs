#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {

    if ((rear + 1) % SIZE == front) {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue() {

    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Deleted: " << queue[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {

    if (front == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }

    int i = front;
    while (1) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
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