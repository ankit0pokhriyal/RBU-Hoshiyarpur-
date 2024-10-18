#include <iostream>
using namespace std;

struct Tree {
    // Enter data as int , create Left pointer, create right pointer

    // Create Constructor
   
};

// Function to create a new node
Tree* createTree(int data) {
    // Return Tree with data as argument inside Heap memory

}

// Function To Create Searching Algorithm
void search(Tree *root, int val) {
    // If root is equal to nullpointer
    //Print Value Not Found or Tree is Empty
    // Return Out
   
    // Print Value Found
    
    

    
    // Else if Val < root->data 
    // recursively Move to Left Tree 

    // ELse recursively Move to right->tree
     
    
}

// Function to find the minimum value in a tree (used in deletion for two children case)

Tree* minValueNode(Tree* root) {
    // Initialize current with root
    
    // Find the left most pointer By
    // using While loop  Move current till current->left != nullptr
    // return current

}

// Function to delete a node
Tree* deleteNode(Tree* root, int val) {
    // If root is equal to nullptr
    // return root


    // If val < root->data
    // Recursively store the deletion of left in root->left
    //Else if 

    // If val > root->data
    // Recursively store the deletion of right in root->Right

        // Node with only one child or no child
        // if root->left =nulllptr
        // intitalize temp with root->right
        // delete root
        // return temp

        // Else if root->right =nulllptr
        // intitalize temp with root->right
        // delete root
        // return temp

        // Node with two children, get the in-order successor (smallest in the right subtree) store in temp


        // Copy the in-order successor's content of temp into root


        // Delete the in-order successor i.e root->right And also temp->data and stores in root->right
    // retrurn root
}

// Function TO insert a node 
Tree* insert(Tree* root, int val) {
    // Check if root = nullptr
    // return CreateTree

    
    // If value < root->data
    // recursively insert() in root->left

    // Else recursively Insert in root->right

    // return the root

}

void inorder(Tree* root) {
    // if root =nullptr
    // return out of loop

    // recursively call inorder for root->left
    // Print  Data of root
    // recursively call inorder for root->right

}

void preorder(Tree* root) {
    // if root =nullptr
    // return out of loop
 
   // Print  Data of root
   // recursively call inorder for root->left

}

void postorder(Tree* root) {
    // if root =nullptr
    // return out of loop

    // recursively call inorder for root->left
    // recursively call inorder for root->right
    // Print  Data of root


}

int main() {
    //Tree* root = nullptr;
   // root = insert(root, 50);
    //insert(root, 30);
    //insert(root, 20);
   // insert(root, 40);
    //insert(root, 70);
    //insert(root, 60);
    //insert(root, 80);

    //cout << "Inorder traversal: ";
    //inorder(root);
    //cout << endl;

    //cout << "Preorder traversal: ";
    //preorder(root);
    //cout << endl;

    //cout << "Postorder traversal: ";
    //postorder(root);
    //cout << endl;

    //search(root, 50);
    //cout << endl;

    //cout << "Deleting 20\n";
    //root = deleteNode(root, 20);
    //cout << "Inorder traversal after deletion: ";
    //inorder(root);
    //cout << endl;

    //cout << "Deleting 30\n";
    //root = deleteNode(root, 30);
    //cout << "Inorder traversal after deletion: ";
    //inorder(root);
    //cout << endl;

    //cout << "Deleting 50\n";
   // root = deleteNode(root, 50);
    //cout << "Inorder traversal after deletion: ";
    //inorder(root);
    //cout << endl;

    return 0;
}
