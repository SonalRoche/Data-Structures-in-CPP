#include<iostream>
#include <iomanip> // For setw
using namespace std;

// Struct representing a node in the BST
struct Node{
    int data;
    Node* parent; // Pointer to parent of node
    Node* left; // Pointer to left child of node
    Node* right; // Pointer to right child of node

    Node(int val, Node* par = nullptr) {
        data = val;
        parent = par;
        left = nullptr;
        right = nullptr;
    }
};

// Class representing a BST
class BST {
public:
     Node* root; // Root of BST

    // Constructor 
    BST() {
        root = nullptr;
    }

    // Destructor
    ~BST() {
        destroyTree(root);
    }

    // Recursive function to delete all nodes in the tree
    void destroyTree(Node* node) {
        if (!node) return; // Base case: If node is null, return

        // Recursively delete left and right subtrees
        destroyTree(node->left);
        destroyTree(node->right);

        // Delete current node
        delete node;
    }

    // Insert a node into the BST
    void insert(int value) {
        Node* newNode = new Node(value);

        // Insert first node, which is the root
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

    // Minimum element in BST
    int minimum() {
        return min(root)->data;
    }

    // Maximum element in BST
    int maximum() {
        return max(root)->data;
    }

    // Search the BST to see if 'val' is present
    Node* search(int val) {
        if(!root) {
            cout << "BST is empty." << endl;
            return nullptr;
        }
        Node* curr = root;
        while(curr) {
            if(curr->data == val) {
                //cout << val << " exists in the BST." << endl;
                return curr;
            }
            else if(val < curr->data) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        //cout << val << " does not exist in the BST." << endl;
        return nullptr;
    }

    // Return the successor of the given node
    Node* successor(int val) {
        
        // Search BST for node 'val'
        Node* valNode = search(val);

        // Node not found in BST
        if(!valNode) {
            cout << "Node " << val << "  does not exist." << endl;
            return nullptr;
        }

        // Case1 :If the node has a right subtree, return the leftmost 
        // node in subtree
        if(valNode->right) {
            return min(valNode->right);
        }
        
        // Case2: Find the lowest ancestor of x whose left child is an 
        // ancestor of x
        Node* par = valNode->parent;
        while(par && valNode == par->right) {
            valNode = par;
            par = par->parent;
        }

        return par;
    }

    // Return the predecessor of the given node
    Node* predecessor(int val) {
        
        // Search BST for node 'val'
        Node* valNode = search(val);

        // Node not found in BST
        if(!valNode) {
            cout << "Node " << val << "  does not exist." << endl;
            return nullptr;
        }

        // Case1 :If the node has a left subtree, return the rightmost 
        // node in subtree
        if(valNode->left) {
            return max(valNode->left);
        }
        
        // Case2: Find the lowest ancestor of x whose left child is an 
        // ancestor of x
        Node* par = valNode->parent;
        while(par && valNode == par->left) {
            valNode = par;
            par = par->parent;
        }

        return par;
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

    Node* min(Node* node) {
        if(!node) {
            cout << "BST is empty." << endl;
            return nullptr;
        }
        Node* curr = node;
        while(curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    Node* max(Node* node) {
        if(!node) {
            cout << "BST is empty." << endl;
            return nullptr;
        }
        Node* curr = node;
        while(curr->right) {
            curr = curr->right;
        }
        return curr;
    }

};

int main() {

    BST tree;

    tree.insert(15);
    tree.insert(6);
    tree.insert(18);
    tree.insert(3);
    tree.insert(7);
    tree.insert(17);
    tree.insert(20);
    tree.insert(2);
    tree.insert(4);
    tree.insert(13);
    tree.insert(9);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    cout << "Minimum: " << tree.minimum() << endl;
    cout << "Maximum: " << tree.maximum() << endl;

    Node* s = tree.search(5);
    if(s) {
        cout << s->data << " found in BST." <<  endl;
    } else {
        cout << "5 not found in BST." << endl;
    }

    s = tree.search(17);
    if(s) {
        cout << s->data << " found in BST." <<  endl;
    } else {
        cout << "17 not found in BST." << endl;
    }

    Node* succ = tree.successor(15);
    if(succ) {
        cout << "Successor of " << 15 << " is " << succ->data << endl;
    }
    else{
        cout << "No successor exists" << endl;
    }

    succ = tree.successor(13);
    if(succ) {
        cout << "Successor of " << 13 << " is " << succ->data << endl;
    }
    else{
        cout << "No successor exists" << endl;
    }

    Node* pred = tree.predecessor(15);
    if(pred) {
        cout << "Predecessor of " << 15 << " is " << pred->data << endl;
    }
    else{
        cout << "No predecessor exists" << endl;
    }

    pred = tree.predecessor(7);
    if(pred) {
        cout << "Predecessor of " << 7 << " is " << pred->data << endl;
    }
    else{
        cout << "No predecessor exists" << endl;
    }

    return 0;
}