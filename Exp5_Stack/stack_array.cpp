//stack using array

#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Cannot pop" << endl;
    } else {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();

    return 0;
}