#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert new node at the beginning of the SLL.
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert new node at the end of the SLL.
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

        temp->next = newNode;
    }

    // Insert new node after a given node y.
    void insertAfterNode(Node* y, int val) {
        if(y == nullptr) {
            cout << "Given node cannot be null." << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = y->next;
        y->next = newNode;
    }

    // Delete a node with data = val
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "Empty List." << endl;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next->data != val && temp->next != nullptr) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            return; // Value not found
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Returns a node with data = val if found
    Node* search(int val) {
        Node* temp =  head;
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
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main() {
    SinglyLinkedList sll;
    sll.insertAtHead(10);
    sll.insertAtTail(20);
    sll.insertAtTail(30);

    Node* node = sll.search(10);
    if (node) {
        sll.insertAfterNode(node, 15);
    }

    sll.display();

    sll.deleteNode(20);
    sll.display();

    return 0;
}