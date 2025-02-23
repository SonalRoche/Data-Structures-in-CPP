#include<iostream>
using namespace std;

// Queue class implementing basic queue operations
class Queue {
private:
    int* arr;   // Dynamic array to store queue elements
    int length; // Maximum capacity of the queue
    int size;   // Current number of elements in the queue
    int head;   // Points to the front of the queue
    int tail;   // Points to the next available position at the end of the queue

public:
    // Constructor to initialize the queue with a given capacity
    Queue(int length) {
        this->length = length;
        arr = new int[length];
        head = 0;
        tail = 0;
        size = 0;
    }

    // Destructor to release allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (size == length) {
            cout << "Queue Full.\n";
            return;
        }
        arr[tail] = value;
        size++;
        // Move tail to the next position (circular increment)
        if (tail + 1 == length) {
            tail = 0; // Wrap around if at the end
        }
        else {
            tail++;
        }
    }

    // Function to remove and return the front element
    int dequeue() {
        if (size == 0) {
            cout << "Queue Empty.\n";
            return -1;
        }
        int x = arr[head];
        if (head == length -1) {
            head = 0; // Wrap around if at the end
        }
        else {
            head++;
        }
        size--;

        return x;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == length;
    }

    // Function to return the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue Empty.\n";
            return -1;
        }
        return arr[head];
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue Empty.\n";
            return;
        }
        cout << "Queue Elements: \n";
        for (int i = 0; i < size; i++) {
            cout << arr[(head+i) % length] << " ";
            
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();

    q.display();

    cout << "Peeking: " << q.peek();

    return 0;
}