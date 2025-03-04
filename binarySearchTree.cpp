#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* parent; // pointer to parent of node
    Node* left; // pointer to left child of node
    Node* right; // pointer to right child of node

    Node(int val, Node* par = nullptr) {
        data = val;
        parent = par;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    ~BST() {
        delete root;
    }

    //Insert a node into the BST
    void insert(int value) {
        Node* newNode = new Node(value);

        if(!root) {
            root = newNode;
            return;
        }

        Node* curr = root;
        Node* par = nullptr;
        while(curr) {
            par = curr;
            if(value < curr->data) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        newNode->parent = par;
        if(value < par->data) {
            par->left = newNode;
        }
        else {
            par->right = newNode;
        }
    }

    // Inorder traversal of BST: Print Left->Root->Right
    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }

    // Preorder traversal of BST: Print Root->Left->Right
    void preorder() {
        preorderRecursive(root);
        cout << endl;
    }

    // Postorder traversal of BST: Print Left->Right->Root
    void postorder() {
        postorderRecursive(root);
        cout << endl;
    }

private:
    void inorderRecursive(Node* node) {
        if(!node) return;
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    void preorderRecursive(Node* node) {
        if(!node) return;
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void postorderRecursive(Node* node) {
        if(!node) return;
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }

};

int main() {

    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();


    return 0;
}