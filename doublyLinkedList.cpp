#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:    
    DoublyLinkedList() {
        head = nullptr;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert new node at the beginning of the DLL.
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert new node at the end of the DLL.
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;

    }

    // Insert new node after a given node y.
    void insertAfterNode(Node* y, int val) {
        if(y == nullptr) {
            cout << "Given node cannot be null." << endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->prev = y;
        newNode->next = y->next;
        if (y->next != nullptr) {
            y->next->prev = newNode;
        }
        y->next = newNode;
    }

    // Delete a node with data = val
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "Empty List." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            return; // Value not found;
        }
        if(temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }

        if(temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    Node* search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if(temp->data == val) {
                return temp;
            }
            temp = temp->next;
        }
        cout << "Node not found." << endl;
        return nullptr;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);

    Node* node = dll.search(10);
    if (node) dll.insertAfterNode(node, 15); // Insert 15 after node with value 10

    dll.display();  // Output: 10 <-> 15 <-> 20 <-> 30 <-> NULL

    dll.deleteNode(20);
    dll.display();  // Output: 10 <-> 15 <-> 30 <-> NULL

    return 0;

}