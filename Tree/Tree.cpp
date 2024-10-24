#include <iostream>
using namespace std;

struct Tree {
    // Enter data as int , create Left pointer, create right pointer
    int data;
    Tree* left;
    Tree* right;
    // Create Constructor
    Tree(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create a new node
Tree* createTree(int data) {
    // Return Tree with data as argument inside Heap memory
    return new Tree(data);
}

// Function To Create Searching Algorithm
void search(Tree *root, int val) {
    // If root is equal to nullpointer
    //Print Value Not Found or Tree is Empty
    // Return Out
    if (root == nullptr) {
        cout << "Value not found";
        return; 
         // Print Value Found
        // Return Out
        cout << "Value Found"<< root->data<< endl;
        

    } 
    // Else if Val < root->data 
    // recursively Move to Left Tree 
    else if (val < root->data) {
        search(root->left, val); 
    } else {
    // ELse recursively Move to right->tree
         search(root->right, val); // Search in the right subtree
    }
}

// Function to find the minimum value in a tree (used in deletion for two children case)

Tree* minValueNode(Tree* root) {
    // Initialize current with root
    Tree* current = root;
    // Find the left most pointer By
    // using While loop  Move current till current->left != nullptr
    // return current
    while (current !=nullptr && current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a node
Tree* deleteNode(Tree* root, int val) {
    // If root is equal to nullptr
    // return root
    if (root == nullptr)
        return root;

    // If val < root->data
    // Recursively Move to Left
    //Else if 

    // If val > root->data
    // Recursively Move to Right
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);

    else {
        // Node with only one child or no child
        // if root->left =nulllptr
        // intitalize temp with root->right
        // delete root
        // return temp
        if (root->left == nullptr) {
            
            Tree* temp = root->right;
            delete root;
            return temp;
        }
        // Else if root->right =nulllptr
        // intitalize temp with root->right
        // delete root
        // return temp
        else if (root->right == nullptr) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, get the in-order successor (smallest in the right subtree)
        Tree* temp = minValueNode(root->right);

        // Copy the in-order successor's content to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function TO insert a node 
Tree* insert(Tree* root, int val) {
    // Check if root = nullptr
    // return CreateTree
    if (root == nullptr) {
        return createTree(val);
    }
    
    // If value < root->data
    // recursively insert() in root->left
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Else recursively Insert in root->right
    else if (val > root->data) {
         root->right = insert(root->right, val);
    }
    // return the root
    return root;
}

void inorder(Tree* root) {
    // if root =nullptr
    // return out of loop
    if (root == nullptr) {
        return;
    }
    // recursively call inorder for root->left
    // Print  Data of root
    // recursively call inorder for root->right
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

void preorder(Tree* root) {
    // if root =nullptr
    // return out of loop
    if (root == nullptr) {
        return;
    }
   // Print  Data of root
   // recursively call inorder for root->left
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree* root) {
    // if root =nullptr
    // return out of loop
    if (root == nullptr) {
        return;
    }
    // recursively call inorder for root->left
    // recursively call inorder for root->right
    // Print  Data of root

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Tree* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    search(root, 50);
    cout << endl;

    cout << "Deleting 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Deleting 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Deleting 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}

