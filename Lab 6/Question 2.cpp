#include <iostream>
using namespace std;

// Define a structure for the nodes in the binary search tree
struct Node {
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

// Function to insert a new value into the binary search tree
Node* insert(Node* root, int x) {
    // If the root is null, create a new node with the given value
    if (root == NULL)
        return new Node(x);
    // If the value is less than the current node's value, insert into the left subtree
    if (x < root->val)
        root->left = insert(root->left, x);
    // If the value is greater than or equal to the current node's value, insert into the right subtree
    else
        root->right = insert(root->right, x);
    return root;
}

// Function to find the Lowest Common Ancestor (LCA) of two values in the binary search tree
Node* lca(Node* root, int v1, int v2) {
    // If the root is null, return null (base case)
    if (root == NULL)
        return NULL;
    // If both values are less than the current node's value, search in the left subtree
    if (v1 < root->val && v2 < root->val)
        return lca(root->left, v1, v2);
    // If both values are greater than the current node's value, search in the right subtree
    else if (v1 > root->val && v2 > root->val)
        return lca(root->right, v1, v2);
    // If one value is less than the current node's value and the other is greater,
    // or if one value matches the current node's value, then the current node is the LCA
    else
        return root;
}

// Main function to test the above functions
int main() {
    Node* root = NULL; // Initialize the root of the binary search tree
    int n;
    cin >> n; // Input the number of elements in the binary search tree
    // Loop to input the elements and construct the binary search tree
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // Input the value
        root = insert(root, x); // Insert the value into the binary search tree
    }
    int v1, v2;
    cin >> v1 >> v2; // Input the two values to find their Lowest Common Ancestor (LCA)
    Node* result = lca(root, v1, v2); // Find the LCA
    cout << result->val; // Output the value of the LCA
    return 0;
}
