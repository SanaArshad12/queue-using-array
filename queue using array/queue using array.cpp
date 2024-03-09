#include <iostream>
using namespace std;
//#define MAX_SIZE 100
const int MAX_SIZE = 100; // Maximum size of the queue array

class Queue {
    int arr[MAX_SIZE]; // Array to store queue elements
    int front; // Index of the front element
    int back; // Index of the back element
public:
    Queue() {
        front = -1; // Initialize front index to -1 (empty queue)
        back = -1; // Initialize back index to -1 (empty queue)
    }

    void enqueue(int number) {
        if (back == MAX_SIZE - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            // If queue is empty, set front to 0
            front = 0;
        }
        // Increment back index and add element to the array
        arr[++back] = number;
    }

    void dequeue() {
        if (front == -1 || front > back) {
            cout << "Queue is empty" << endl;
            return;
        }
        // Increment front index to remove the element
        front++;
    }

    int peek() {
        if (front == -1 || front > back) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        // Return the front element of the queue
        return arr[front];
    }

    bool empty() {
        return (front == -1 || front > back);
    }
};

int main() {
    Queue q;
    // Enqueue some elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    // Display the element at the front of the queue
    cout << "Number at front: " << q.peek() << endl;

    // Dequeue elements and display the front of the queue after each dequeue operation
    q.dequeue();
    cout << "Number at front after dequeue: " << q.peek() << endl;
    q.dequeue();
    cout << "Number at front after dequeue: " << q.peek() << endl;
    q.dequeue();
    cout << "Number at front after dequeue: " << q.peek() << endl;
    q.dequeue();

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
