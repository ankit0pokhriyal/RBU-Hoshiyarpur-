#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    // Define Structure with key and height as integer  and left and right pointer 

};

// Function to calculate the height of a node
int height(Node* node) {
// If Node is empty  reuturn 0
 
// else return node->height
    
}

// Function to get the maximum of two integers
int max(int a, int b) {
    // if a > b get a or else b
   
}

// Create a new AVL tree node
Node* newNode(int key) {
    // Create Dynamically New Node by the name of node 
    
    // Intialize nodekey-> = key
   
    // node ->left = nullptr
    
    // node ->right  =nullptr
   
    // node ->height =1
  // return node
  
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    // Create Structure x as left child of y
   
    // Create Structure T2 as right child of x
  

    // Perform rotation
    // y will become right child of x
    
    // T2 will become left child of y
    

    // Update heights
       
    //y->height = max(height(y->left), height(y->right)) + 1;
    //x->height = max(height(x->left), height(x->right)) + 1;
   

    // Return new root x

   
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    //create y as right child of x
 
    // creat T2 as left child of y
   

    // Perform rotation
    // left child of y become x
    // right  child of x become T2


    // Update heights


    // Return new root
 
}

// Get balance factor of a node
int balanceFactor(Node* node) {
    // if node  == null
    //return  0
    // else  return height of node->left - height of  node ->right

}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // Perform standard BST insertion
   

    // Update height of the current node
    // node height  =  1 + max(height (node ->left ), height(node->right))
   

    // Get the balance factor of this node to check if it's unbalanced
    // balance   =  balance factor(node)
    

    // If this node becomes unbalanced, there are four cases

    // Left Left Case
    //if (balance > 1 && key < node->left->key)
       // return rightRotate(node);
    

    // Right Right Case
    //     if (balance < -1 && key > node->right->key)
     //   return leftRotate(node);
    

    // Left Right Case
    //if (balance > 1 && key > node->left->key) 
        //node->left = leftRotate(node->left);
        //return rightRotate(node);
    
    // Right Left Case
    //if (balance < -1 && key < node->right->key) 
        //node->right = rightRotate(node->right);
       // return leftRotate(node);
    
    // return node
    
}

// Function to find the node with the minimum key value in a given AVL tree
Node* minValueNode(Node* node) {
// same as BST
}

// Delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    // Perform standard BST delete
    
    
    
    // If the tree had only one node, return root


    // Update the height of the current node
    // same as insertion in avl
   

    // Get the balance factor of this node
    // balance = balanceFactor(root);

    // If this node becomes unbalanced, there are four cases

    // Left Left Case
    //    if (balance > 1 && balanceFactor(root->left) >= 0)
    //    return rightRotate(root);
    

    // Left Right Case
    //     if (balance > 1 && balanceFactor(root->left) < 0) 
    // root->left = leftRotate(root->left);
    //  return rightRotate(root);
    
   
    // Right Right Case
    //     if (balance < -1 && balanceFactor(root->right) <= 0)
     //   return leftRotate(root);
    

    // Right Left Case
      //  if (balance < -1 && balanceFactor(root->right) > 0) 
      //  root->right = rightRotate(root->right);
       // return leftRotate(root);
    
  
   // return root;
}

// Print the AVL tree in in-order traversal
void inOrder(Node* root) {
// same as bst
}

int main() {
    Node* root = nullptr;

    root = insert(root, 63);
    root = insert(root, 9);
    root = insert(root, 19);
    root = insert(root, 27);
    root = insert(root, 18);
    root = insert(root, 108);
    root = insert(root, 99);
    root = insert(root, 81);

    cout << "In-order traversal of the AVL tree: ";
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 81);
    root = deleteNode(root, 99);
    root = deleteNode(root, 108);
    root = deleteNode(root, 18);
    root = deleteNode(root, 27);
    root = deleteNode(root, 19);

    cout << "In-order traversal of the AVL tree after deletions: ";
    inOrder(root);
    cout << endl;

    return 0;
}