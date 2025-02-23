#include <iostream>
using namespace std;

// Stack class implementing basic stack operations
class Stack {
private:
    int* arr; // Dynamic array to store stack elements
    int top;  // Index of the top element
    int size; // Maximum size of the stack

public:
    // Constructor to initialize stack with a given size
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1; // Initialize top to -1 (empty stack)
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr; // since arr is an array we have to use delete[]
    }

    // Push operation to add an element to the stack
    void push(int value) {

        if (top == size - 1) {
            cout << "Stack Overflow.";
            return;
        }
        top++;
        arr[top] = value;

    }

    // Pop operation to remove and return the top element
    int pop() {

        if (top == -1) {
            cout << "Stack Underflow.";
            return -1;
        }
        top--;
        return arr[top+1];
    }

    // Peek operation to view the top element without removing it
    int peek() {
        if (top == -1) {
            cout << "Stack Empty.";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
    
    // Display all elements in the stack
    void display() {
        if (top == -1) {
            cout << "Stack Empty.";
            return;
        }
        cout << "Stack Elements: \n";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    Stack s(5); // create stack object on the stack
    //Stack* s = new Stack(5); // create stack object on the heap, 
                               //must use 'delete s' later. eg. s->pop();
    s.push(10);
    s.push(15);
    s.pop();
    s.push(20);
    s.push(25);
    s.pop();
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.display();
    
    cout << "Peeking: " << s.peek();

    return 0;
}