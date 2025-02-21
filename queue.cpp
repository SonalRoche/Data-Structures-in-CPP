#include<iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int length; // max capacity of array
    int size;
    int head;
    int tail;

public:
    Queue(int length) {
        this->length = length;
        arr = new int[length];
        head = 0;
        tail = 0;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == length) {
            cout << "Queue Full.\n";
            return;
        }
        arr[tail] = value;
        size++;
        if (tail + 1 == length) {
            tail = 0;
        }
        else {
            tail++;
        }
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Empty.\n";
            return -1;
        }
        int x = arr[head];
        if (head == length -1) {
            head = 0;
        }
        else {
            head++;
        }
        size--;

        return x;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == length;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue Empty.\n";
            return -1;
        }
        return arr[head];
    }

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