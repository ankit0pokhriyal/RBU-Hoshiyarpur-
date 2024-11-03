#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    // Define Structure with key and height as integer  and left and right pointer 
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to calculate the height of a node
int height(Node* node) {
// If Node is empty  reuturn 0
    if (node == nullptr) 
        return 0;
// else return node->height
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    // if a > b get a or else b
    return (a > b) ? a : b;
}

// Create a new AVL tree node
Node* newNode(int key) {
    // Create Dynamically New Node
    Node* node = new Node();
    // Intialize nodekey-> = key
    node->key = key;
    // node ->left = nullptr
    node->left = nullptr;
    // node ->right  =nullptr
    node->right = nullptr;
    // node ->height =1
    node->height =1;
    return node;
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    // Create Structure x as left child of y
    Node* x = y->left;
    // Create Structure T2 as right child of x
    Node* T2 = x->right;

    // Perform rotation
    // y will become right child of x
    x->right = y;
    // T2 will become left child of y
    y->left = T2;

    // Update heights
       
    //y->height = max(height(y->left), height(y->right)) + 1;
    //x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root x

    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    //create y as right child of x
    Node* y = x->right;
    // creat T2 as left child of y
    Node* T2 = y->left;

    // Perform rotation
    // left child of y become x
    // right  child of x become T2
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of a node
int balanceFactor(Node* node) {
    // if node  == null
    //return  0
    // else  return height of node->left - node ->right
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // Perform standard BST insertion
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed
        return node;

    // Update height of the current node
    // node height  =  1 + max(height (node ->left ), height(node->right))
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this node to check if it's unbalanced
    // balance   =  balance factor(node)
    int balance = balanceFactor(node);

    // If this node becomes unbalanced, there are four cases

    // Left Left Case
    //if (balance > 1 && key < node->left->key)
       // return rightRotate(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    //     if (balance < -1 && key > node->right->key)
     //   return leftRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    //if (balance > 1 && key > node->left->key) 
        //node->left = leftRotate(node->left);
        //return rightRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    //if (balance < -1 && key < node->right->key) 
        //node->right = rightRotate(node->right);
       // return leftRotate(node);
    
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the node with the minimum key value in a given AVL tree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) // Recurrent function can also be used instead of while loop
        current = current->left;
    return current;
}

// Delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    // Perform standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            // Node with two children: get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, return
    if (root == nullptr)
        return root;

    // Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this node
    int balance = balanceFactor(root);

    // If this node becomes unbalanced, there are four cases

    // Left Left Case
    //    if (balance > 1 && balanceFactor(root->left) >= 0)
    //    return rightRotate(root);
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    //     if (balance > 1 && balanceFactor(root->left) < 0) 
    // root->left = leftRotate(root->left);
    //  return rightRotate(root);
    
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    //     if (balance < -1 && balanceFactor(root->right) <= 0)
     //   return leftRotate(root);
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
      //  if (balance < -1 && balanceFactor(root->right) > 0) 
      //  root->right = rightRotate(root->right);
       // return leftRotate(root);
    
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

   // return root;
}

// Print the AVL tree in in-order traversal
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
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
