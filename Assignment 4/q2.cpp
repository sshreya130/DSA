#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
        } else {
            if (front == -1) front = 0; 
            rear = (rear + 1) % SIZE;
            arr[rear] = value;
            cout << value << " enqueued successfully.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
        } else {
            cout << arr[front] << " dequeued successfully.\n";
            if (front == rear) {
                front = rear = -1; 
            } else {
                front = (front + 1) % SIZE;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No element to peek.\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << "\n";
        }
    }
};

int main() {
    CircularQueue q;
    int choice, value;
    while(true){
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
